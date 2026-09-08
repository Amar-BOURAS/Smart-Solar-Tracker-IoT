#include <Wire.h>

// ==========================================
// TEST INA219 - COMMUNICATION I2C
// Smart Solar Tracker IoT
// SDA GPIO21 - SCL GPIO22
// ==========================================

#define SDA_PIN 21
#define SCL_PIN 22
#define INA219_ADDRESS 0x40

void setup() {

  Serial.begin(115200);
  delay(1000);

  Wire.begin(SDA_PIN, SCL_PIN);

  Serial.println();
  Serial.println("================================");
  Serial.println(" TEST INA219 - I2C");
  Serial.println("================================");

  Wire.beginTransmission(INA219_ADDRESS);
  byte erreur = Wire.endTransmission();

  if (erreur == 0) {
    Serial.println("INA219 detecte !");
    Serial.println("Adresse I2C : 0x40");
    Serial.println("Communication I2C : OK");
  }
  else {
    Serial.println("INA219 non detecte !");
    Serial.println("Verifier le cablage.");
  }
}

void loop() {

  Wire.beginTransmission(INA219_ADDRESS);
  byte erreur = Wire.endTransmission();

  if (erreur == 0) {
    Serial.println("INA219 : OK");
  }
  else {
    Serial.println("INA219 : ERREUR");
  }

  delay(2000);
}
