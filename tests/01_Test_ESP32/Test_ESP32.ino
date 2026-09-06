// =====================================================
// SMART SOLAR TRACKER IoT
// TEST UNITAIRE 01 : ESP32
// Objectif : vérifier le fonctionnement de l'ESP32
// =====================================================

void setup() {

  Serial.begin(115200);
  delay(1000);

  Serial.println("================================");
  Serial.println("Smart Solar Tracker IoT");
  Serial.println("ESP32 fonctionne correctement !");
  Serial.println("================================");
}

void loop() {

  Serial.println("ESP32 OK");

  delay(1000);
}
