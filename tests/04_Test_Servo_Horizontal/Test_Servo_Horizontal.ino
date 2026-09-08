#include <ESP32Servo.h>

// ==========================================
// TEST SERVOMOTEUR HORIZONTAL
// Smart Solar Tracker IoT
// GPIO25
// ==========================================

#define SERVO_H_PIN 25

Servo servoH;

void setup() {

  Serial.begin(115200);

  servoH.setPeriodHertz(50);

  servoH.attach(
    SERVO_H_PIN,
    500,
    2400
  );

  Serial.println("=== TEST SERVO HORIZONTAL GPIO25 ===");

  servoH.write(90);
  delay(2000);
}

void loop() {

  Serial.println("Position : 60 deg");
  servoH.write(60);
  delay(3000);

  Serial.println("Position : 90 deg");
  servoH.write(90);
  delay(3000);

  Serial.println("Position : 120 deg");
  servoH.write(120);
  delay(3000);
}
