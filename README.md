# Sistem Otomatis Pencahayaan Kandang Ayam 🐔💡

Proyek mini ini bertujuan untuk merancang sistem otomatis yang dapat mengendalikan pencahayaan pada kandang ayam berdasarkan **suhu**, **kelembaban**, dan **waktu**. Sistem ini dibuat untuk memenuhi tugas **Ujian Tengah Semester (UTS)** dan diharapkan sesuai dengan instruksi yang telah diberikan.

## 🎯 Tujuan
Membuat sistem yang dapat mengatur lampu secara otomatis untuk menjaga kenyamanan ayam. Lampu akan menyala atau mati tergantung pada data dari sensor DHT22 dan waktu dari modul RTC DS3231.

## 🛠️ Komponen yang Digunakan
- Arduino Uno
- Sensor DHT22
- Modul RTC DS3231
- LCD I2C 16x2
- LED atau lampu (sebagai simulasi pencahayaan)
- Kabel jumper & breadboard

## 📁 Daftar File
| Nama File            | Keterangan |
|----------------------|------------|
| `sketch.ino`         | Program utama Arduino |
| `diagram.json`       | Diagram rangkaian (dari Wokwi) |
| `libraries.txt`      | Daftar library yang digunakan |
| `wokwi-project.txt`  | Link atau ID proyek Wokwi untuk simulasi |

## 📚 Library yang Dibutuhkan
Pastikan library berikut telah diinstal melalui Library Manager Arduino IDE:
- `DHT sensor library`
- `Adafruit Unified Sensor`
- `RTClib`
- `LiquidCrystal_I2C`

## 🚀 Cara Menjalankan Proyek
1. Buka `sketch.ino` di Arduino IDE.
2. Upload ke board setelah library terinstal.
3. Rakit rangkaian sesuai diagram.
4. Jalankan dan lihat tampilan suhu, kelembaban, dan waktu di LCD.
5. Lampu akan menyala atau mati secara otomatis sesuai kondisi.

## 📌 Catatan
Proyek ini merupakan bagian dari tugas UTS dan bertujuan untuk menerapkan konsep otomatisasi di bidang peternakan sederhana.

## 🙏 Penutup
Kami dari **Kelompok 9** mengucapkan terima kasih atas perhatian dan bimbingan yang telah diberikan.  
Video dan proyek ini dibuat untuk melaksanakan Ujian Tengah Semester, dan kami berharap seluruh isi sesuai dengan instruksi yang telah ditetapkan.  
Mohon maaf apabila terdapat kekurangan. Kami mohon izin undur diri. Terima kasih 🙏

