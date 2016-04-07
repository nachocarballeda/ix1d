#include <Arduino.h>

class UltrasonicSensors {
 public:
  UltrasonicSensors() {
    pinMode(kTriggerPinA, OUTPUT);
    pinMode(kEchoPinA, INPUT);
    
    pinMode(kTriggerPinB, OUTPUT);
    pinMode(kEchoPinB, INPUT);
  }
  
  long a() {
    return ultrasonicSensorMeasure(sensor_a_);
  }
  long b() {
    return ultrasonicSensorMeasure(sensor_b_);
  }
    
 private:
  static const int kTriggerPinA = A0; 
  static const int kEchoPinA = 3;
  static const int kTriggerPinB = A1;
  static const int kEchoPinB = 4;

  char sensor_a_ = 'A';
  char sensor_b_ = 'B';
  
  long ultrasonicSensorMeasure(char sensor) {
    // parameters:
    //   sensor: 'A' or 'B'
    
    long duration, distance;
    float distance_factor = 2.91;
    // 60 ms is the recommended timeout, as in the HC-SR04 datasheet.
    // On an Arduino Leonardo, the number is off by a factor of ~5.5
    // (and 1000 / 5.5 ~= 181.8 to get milliseconds)
    unsigned long sensor_timeout_ms = 60 * 181.8;
    
    if (sensor == 'A') {
      digitalWrite(kTriggerPinA, LOW);  
      delayMicroseconds(2); 
      digitalWrite(kTriggerPinA, HIGH);
      delayMicroseconds(10); 
      digitalWrite(kTriggerPinA, LOW);
      duration = pulseIn(kEchoPinA, HIGH, sensor_timeout_ms);
      distance = (duration / 2) / distance_factor;
    } else if (sensor == 'B') {
      digitalWrite(kTriggerPinB, LOW);  
      delayMicroseconds(2); 
      digitalWrite(kTriggerPinB, HIGH);
      delayMicroseconds(10); 
      digitalWrite(kTriggerPinB, LOW);
      duration = pulseIn(kEchoPinB, HIGH, sensor_timeout_ms);
      distance = (duration / 2) / distance_factor;
    } 
    
    if (distance >= 3100 || distance <= 0) {
      return 0;
    } else {
      return distance;
    }
  } 
};

