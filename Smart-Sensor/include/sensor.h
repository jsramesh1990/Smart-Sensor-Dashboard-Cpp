#ifndef SENSOR_H
#define SENSOR_H

#include <iostream>
#include <string>

// ---------- ENUM: Sensor Types ----------
enum SensorType {
    TEMP_SENSOR,
    HUMIDITY_SENSOR,
    PRESSURE_SENSOR
};

// ---------- UNION: Raw Sensor Data ----------
union SensorRawData {
    float float_value;
    int int_value;
};

// ---------- STRUCT: Sensor Packet ----------
struct SensorPacket {
    std::string name;
    SensorType type;
    SensorRawData data;
};

#endif

