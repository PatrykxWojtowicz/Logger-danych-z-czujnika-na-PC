# 📈 Logger danych z czujnika (symulacja)

Projekt w C++ symulujący odczyt temperatury z czujnika oraz zapis danych do pliku `.csv` w formacie:


## 🎯 Opis
Program generuje losowe wartości temperatury (symulacja czujnika) i zapisuje je wraz ze znacznikiem czasu do pliku `log.csv`.  
Dodatkowo wyświetla informację o zapisanym pomiarze w konsoli.

## 🛠 Funkcjonalności
- Generowanie danych pomiarowych w czasie rzeczywistym.
- Zapis do pliku CSV w czytelnym formacie.
- Możliwość łatwej rozbudowy o odczyt z prawdziwego czujnika (Arduino/ESP32).

## 📂 Struktura plików
│── main.cpp # Główny plik programu
│── Sensor.cpp # Implementacja klasy Sensor
│── Sensor.h # Definicja klasy Sensor
│── log.csv # Plik z zapisanymi pomiarami (tworzony po uruchomieniu)
