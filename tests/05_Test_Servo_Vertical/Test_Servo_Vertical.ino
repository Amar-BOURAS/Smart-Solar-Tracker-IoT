#include <ESP32Servo.h>

// ==========================================
// TEST SERVOMOTEUR VERTICAL
// Smart Solar Tracker IoT
// GPIO26
// ==========================================

#define SERVO_V_PIN 26

Servo servoV;

void setup() {

  Serial.begin(115200);

  servoV.setPeriodHertz(50);

  servoV.attach(
    SERVO_V_PIN,
    500,
    2400
  );

  Serial.println("=== TEST SERVO VERTICAL GPIO26 ===");

  servoV.write(90);
  delay(2000);
}

void loop() {

  Serial.println("Position : 80 deg");
  servoV.write(80);
  delay(3000);

  Serial.println("Position : 90 deg");
  servoV.write(90);
  delay(3000);

  Serial.println("Position : 100 deg");
  servoV.write(100);
  delay(3000);
}
