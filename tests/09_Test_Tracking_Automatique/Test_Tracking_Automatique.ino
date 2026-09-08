#include <ESP32Servo.h>

// =============================================
// TEST TRACKING AUTOMATIQUE
// Smart Solar Tracker IoT
// ESP32 + 4 LDR + 2 servomoteurs
// =============================================

// -------- LDR --------
#define LDR_HG 34   // Haut gauche
#define LDR_HD 35   // Haut droite
#define LDR_BG 32   // Bas gauche
#define LDR_BD 33   // Bas droite

// -------- SERVOS --------
#define SERVO_H_PIN 25
#define SERVO_V_PIN 26

Servo servoH;
Servo servoV;

// Position initiale
int posH = 90;
int posV = 90;

// Limites mécaniques de sécurité
const int H_MIN = 20;
const int H_MAX = 160;

const int V_MIN = 30;
const int V_MAX = 150;

// Pas de déplacement
const int PAS = 1;

// Tolérance de départ
const int TOLERANCE = 80;

// Valeurs LDR
int HG;
int HD;
int BG;
int BD;

// Moyennes
int haut;
int bas;
int gauche;
int droite;

// Erreurs
int erreurH;
int erreurV;


// =============================================
// LECTURE MOYENNÉE D'UN LDR
// =============================================

int lireLDR(int pin) {

  long somme = 0;

  // Moyenne de 5 mesures
  for (int i = 0; i < 5; i++) {

    somme += analogRead(pin);

    delay(2);
  }

  int valeur = somme / 5;

  // Nos LDR donnent une valeur faible avec
  // beaucoup de lumière.
  // On inverse donc la mesure.
  return 4095 - valeur;
}


// =============================================
// SETUP
// =============================================

void setup() {

  Serial.begin(115200);

  analogReadResolution(12);

  // Configuration servomoteur horizontal
  servoH.setPeriodHertz(50);
  servoH.attach(
    SERVO_H_PIN,
    500,
    2400
  );

  // Configuration servomoteur vertical
  servoV.setPeriodHertz(50);
  servoV.attach(
    SERVO_V_PIN,
    500,
    2400
  );

  // Position centrale
  servoH.write(posH);
  servoV.write(posV);

  delay(2000);

  Serial.println();
  Serial.println("=================================");
  Serial.println(" TEST TRACKING AUTOMATIQUE");
  Serial.println(" Smart Solar Tracker IoT");
  Serial.println("=================================");
}


// =============================================
// LOOP
// =============================================

void loop() {

  // -----------------------------
  // 1. Lecture des quatre LDR
  // -----------------------------

  HG = lireLDR(LDR_HG);
  HD = lireLDR(LDR_HD);
  BG = lireLDR(LDR_BG);
  BD = lireLDR(LDR_BD);


  // -----------------------------
  // 2. Calcul des moyennes
  // -----------------------------

  haut = (HG + HD) / 2;
  bas = (BG + BD) / 2;

  gauche = (HG + BG) / 2;
  droite = (HD + BD) / 2;


  // -----------------------------
  // 3. Calcul des erreurs
  // -----------------------------

  erreurH = gauche - droite;
  erreurV = haut - bas;


  // -----------------------------
  // 4. Commande horizontale
  // -----------------------------

  if (erreurH > TOLERANCE) {

    posH += PAS;

  }
  else if (erreurH < -TOLERANCE) {

    posH -= PAS;
  }


  // -----------------------------
  // 5. Commande verticale
  // -----------------------------

  if (erreurV > TOLERANCE) {

    posV += PAS;

  }
  else if (erreurV < -TOLERANCE) {

    posV -= PAS;
  }


  // -----------------------------
  // 6. Limites mécaniques
  // -----------------------------

  posH = constrain(posH, H_MIN, H_MAX);
  posV = constrain(posV, V_MIN, V_MAX);


  // -----------------------------
  // 7. Déplacement servomoteurs
  // -----------------------------

  servoH.write(posH);
  servoV.write(posV);


  // -----------------------------
  // 8. Affichage moniteur série
  // -----------------------------

  Serial.print("HG:");
  Serial.print(HG);

  Serial.print(" HD:");
  Serial.print(HD);

  Serial.print(" BG:");
  Serial.print(BG);

  Serial.print(" BD:");
  Serial.print(BD);

  Serial.print(" | EH:");
  Serial.print(erreurH);

  Serial.print(" EV:");
  Serial.print(erreurV);

  Serial.print(" | H:");
  Serial.print(posH);

  Serial.print(" V:");
  Serial.println(posV);

  delay(50);
}
