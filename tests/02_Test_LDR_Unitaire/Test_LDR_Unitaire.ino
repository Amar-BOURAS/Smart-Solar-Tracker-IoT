// ==========================================
// TEST LDR UNITAIRE
// Smart Solar Tracker IoT
// ==========================================

#define LDR_PIN 34

void setup() {

  Serial.begin(115200);
  analogReadResolution(12);

  Serial.println("Test LDR - GPIO34");
}

void loop() {

  int valeur = analogRead(LDR_PIN);

  Serial.print("Valeur LDR : ");
  Serial.println(valeur);

  delay(500);
}
