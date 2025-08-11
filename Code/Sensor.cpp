#include "Sensor.h"

double Sensor::readValue() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_real_distribution<> dist(20.0, 30.0);
    return dist(gen);
}
