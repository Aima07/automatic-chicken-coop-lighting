# Sistem Otomatis Pencahayaan Kandang Ayam 🐔💡

Proyek mini ini bertujuan untuk merancang sistem otomatis yang dapat mengendalikan pencahayaan pada kandang ayam berdasarkan **suhu**, **kelembaban**, dan **waktu**. Sistem ini dibuat dalam rangka memenuhi tugas **Ujian Tengah Semester (UTS)**.

## 🎯 Tujuan
Membuat sistem yang dapat mengatur lampu secara otomatis untuk menjaga kenyamanan ayam. Lampu akan menyala atau mati tergantung pada data suhu dan kelembaban dari sensor DHT22, serta jam dari modul RTC DS3231.

## 🛠️ Komponen yang Digunakan
- Arduino Uno
- Sensor DHT22
- Modul RTC DS3231
- LCD I2C 16x2
- LED/Lampu (simulasi pencahayaan)
- Kabel jumper dan breadboard

## 📁 File dan Fungsinya
| Nama File       | Keterangan |
|----------------|------------|
| `sketch.ino`   | Program utama untuk Arduino |
| `diagram.json` | File diagram rangkaian (misalnya dari Tinkercad) |
| `libraries.txt`| Daftar library yang digunakan |
| `README.md`    | Deskripsi proyek |
| `.gitignore`   | (Opsional) Mengabaikan file yang tidak perlu |

## 📚 Library yang Dibutuhkan
Pastikan kamu sudah install library berikut di **Library Manager Arduino IDE**:
- `DHT sensor library`
- `Adafruit Unified Sensor`
- `RTClib`
- `LiquidCrystal_I2C`

## 🚀 Cara Menjalankan Proyek
1. Buka `sketch.ino` di Arduino IDE.
2. Hubungkan Arduino ke laptop dan pilih board + port yang sesuai.
3. Upload kode ke board.
4. Pastikan rangkaian sesuai dengan diagram yang ada.
5. LCD akan menampilkan suhu, kelembaban, dan waktu. Lampu akan menyala atau mati secara otomatis berdasarkan kondisi.

## 📸 Screenshot (Opsional)
*(Masukkan gambar LCD atau diagram rangkaian di sini)*

## 📌 Catatan
Proyek ini dibuat sebagai bagian dari tugas UTS dan bertujuan untuk menerapkan konsep otomatisasi sederhana dalam lingkungan peternakan. Semoga bisa jadi inspirasi buat pengembangan lebih lanjut.

## 🙏 Penutup
Kami dari **Kelompok 9** mengucapkan terima kasih atas kesempatan dan arahan yang telah diberikan. Semoga proyek ini sesuai dengan instruksi dan bermanfaat untuk semua. 💪

