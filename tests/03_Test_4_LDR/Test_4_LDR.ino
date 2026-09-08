// ==========================================
// TEST DES 4 CAPTEURS LDR
// Smart Solar Tracker IoT
// ==========================================

// Haut Gauche
#define LDR_HG 34

// Haut Droite
#define LDR_HD 35

// Bas Gauche
#define LDR_BG 32

// Bas Droite
#define LDR_BD 33

void setup() {

  Serial.begin(115200);

  analogReadResolution(12);

  Serial.println("=== TEST DES 4 LDR ===");
}

void loop() {

  int HG = analogRead(LDR_HG);
  int HD = analogRead(LDR_HD);
  int BG = analogRead(LDR_BG);
  int BD = analogRead(LDR_BD);

  Serial.print("HG : ");
  Serial.print(HG);

  Serial.print(" | HD : ");
  Serial.print(HD);

  Serial.print(" | BG : ");
  Serial.print(BG);

  Serial.print(" | BD : ");
  Serial.println(BD);

  delay(500);
}
