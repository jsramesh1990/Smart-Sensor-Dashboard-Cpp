#include <iostream>
#include "sensor.h"

// A function to print sensor values
void printSensor(const SensorPacket &packet) {
    
    // typeof() -> GCC extension
   // typeof(packet.data.float_value) temp_type_checker = 0.0f;
   // // typeof demonstration removed because GCC does not support it in C++ mode
    decltype(packet.data.float_value) temp_type_checker = 0.0f;
    std::cout << "Sensor Name : " << packet.name << "\n";

    switch (packet.type) {
        case TEMP_SENSOR:
            std::cout << "Type        : Temperature\n";
            std::cout << "Value       : " << packet.data.float_value << " °C\n";
            break;

        case HUMIDITY_SENSOR:
            std::cout << "Type        : Humidity\n";
            std::cout << "Value       : " << packet.data.int_value << " %\n";
            break;

        case PRESSURE_SENSOR:
            std::cout << "Type        : Pressure\n";
            std::cout << "Value       : " << packet.data.float_value << " Pa\n";
            break;
    }

    std::cout << "----------------------------------\n";

    return;  // using return keyword
}


int main() {

    // Using decltype (standard C++ alternative for typeof)
    decltype(5.5f) pressure_type = 101325.0f;

    // ---------- Sensor Packets ----------
    SensorPacket temp;
    temp.name = "RoomTemp";
    temp.type = TEMP_SENSOR;
    temp.data.float_value = 26.4f;

    SensorPacket humidity;
    humidity.name = "RoomHumidity";
    humidity.type = HUMIDITY_SENSOR;
    humidity.data.int_value = 58;

    SensorPacket pressure;
    pressure.name = "AtmosphericPressure";
    pressure.type = PRESSURE_SENSOR;
    pressure.data.float_value = pressure_type;

    // Print data logically
    printSensor(temp);
    printSensor(humidity);
    printSensor(pressure);

    return 0;
}

