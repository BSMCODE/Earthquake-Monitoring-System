//message.h: Represents one sensor packet node

#ifndef MESSAGE_H
#define MESSAGE_H

typedef struct SensorPacket {
    int sensorid;
    double time;
    double temperature;
    double seismic;
    struct SensorPacket *next;
} SensorPacket;

#endif

