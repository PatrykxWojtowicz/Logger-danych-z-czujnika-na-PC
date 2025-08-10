#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include <iomanip>
#include "Sensor.h"

std::string getTimestamp() {
    auto now = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);
    std::tm tm = *std::localtime(&t);

    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

int main() {
    Sensor sensor;
    std::ofstream file("log.csv");

    if (!file) {
        std::cerr << "Nie można otworzyć pliku do zapisu.\n";
        return 1;
    }

    
    file << "Time,Temperature_C\n";

    std::cout << "\n=== POMIAR TEMPERATURY ===\n";
    std::cout << std::left << std::setw(20) << "Time"
              << std::setw(15) << "Temperature [C]" << "\n";

    for (int i = 0; i < 5; ++i) { 
        double value = sensor.readValue();

        
        file << getTimestamp() << "," << value << "\n";

        
        std::cout << std::left << std::setw(20) << getTimestamp()
                  << std::setw(15) << value << "\n";

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    std::cout << "Logowanie zakończone.\n";
    return 0;
}
