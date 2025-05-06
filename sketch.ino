#include <Wire.h>
#include <RTClib.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

#define DHTPIN        7       
#define DHTTYPE       DHT22   

RTC_DS3231 rtc;
LiquidCrystal_I2C lcd(0x27,16,2);
DHT dht(DHTPIN, DHTTYPE);

const int relayPin = 8;
const int ledPin = 9; // LED indikator

void setup() {
  Serial.begin(9600);
  
  pinMode(relayPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  
  lcd.init();
  lcd.backlight();
  
  dht.begin();
  
  if (!rtc.begin()) {
    lcd.print("RTC not found");
    while (1);
  }
  
  if (rtc.lostPower()) {
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}

void loop() {
  DateTime now = rtc.now();
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  int hour = now.hour();
  bool lampOn = false;
  bool tempWarning = false;
  bool humidWarning = false;

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Sensor error!");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error");
    delay(2000);
    return;
  }

  // Deteksi kondisi ekstrem
  if (temperature > 40.0) tempWarning = true;
  if (humidity > 90.0) humidWarning = true;

  // Logika utama pencahayaan kandang ayam
  if (hour >= 18 || hour < 6) { // Malam
    if (!tempWarning && !humidWarning) {
      lampOn = true;
    }
  } else { // Siang
    if (temperature < 30.0 && humidity < 80.0) {
      lampOn = true;
    }
  }

  // Output ke relay dan LED indikator
  digitalWrite(relayPin, lampOn ? HIGH : LOW);
  digitalWrite(ledPin, lampOn ? HIGH : LOW);

  // LCD display logic
  char buffer[17];
  sprintf(buffer, "%02d:%02d:%02d", now.hour(), now.minute(), now.second());

  static unsigned long lastSwitch = millis();
static int screenState = 0; // 0: Waktu, 1: Suhu, 2: Kelembaban, 3: Status Lampu

if (millis() - lastSwitch > 1000) {
  lcd.clear();
  lcd.setCursor(0, 0);

  char buffer[17];
  sprintf(buffer, "%02d:%02d:%02d", now.hour(), now.minute(), now.second());

  switch (screenState) {
    case 0:
      lcd.print("Waktu:");
      lcd.print(buffer);
      break;

    case 1:
      if (tempWarning) {
        lcd.print("Suhu Tinggi!");
      } else {
        lcd.print("Suhu:");
        lcd.print(temperature, 1);
        lcd.print((char)223);
        lcd.print("C");
      }
      break;

    case 2:
      if (humidWarning) {
        lcd.print("Lembab Tinggi!");
      } else {
        lcd.print("Lembab:");
        lcd.print(humidity, 1);
        lcd.print("%");
      }
      break;

    case 3:
      lcd.print("Lampu:");
      lcd.print(lampOn ? "ON " : "OFF");
      break;
  }

  screenState = (screenState + 1) % 4;
  lastSwitch = millis();
}

  // Serial monitoring
  Serial.println(buffer);
  Serial.print("Temperature: ");
  Serial.println(temperature);
  Serial.print("Humidity: ");
  Serial.println(humidity);
  Serial.println(lampOn ? "Lamp ON" : "Lamp OFF");
  if (tempWarning) Serial.println("WARNING: Suhu terlalu tinggi!");
  if (humidWarning) Serial.println("WARNING: Kelembaban terlalu tinggi!");

  delay(500);
}
