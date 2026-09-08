#include <WiFi.h>

// ==========================================
// TEST CONNEXION WIFI
// Smart Solar Tracker IoT
// ESP32
// ==========================================

// IMPORTANT : ne jamais publier le vrai mot de passe sur GitHub
const char* ssid = "TON_RESEAU_WIFI";
const char* password = "TON_MOT_DE_PASSE";

void setup() {

  Serial.begin(115200);
  delay(1000);

  Serial.println();
  Serial.println("==============================");
  Serial.println(" TEST CONNEXION WIFI ESP32");
  Serial.println("==============================");

  WiFi.mode(WIFI_STA);

  Serial.print("Connexion au WiFi : ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  int tentative = 0;

  while (WiFi.status() != WL_CONNECTED && tentative < 30) {
    delay(500);
    Serial.print(".");
    tentative++;
  }

  Serial.println();

  if (WiFi.status() == WL_CONNECTED) {

    Serial.println("WiFi : OK");

    Serial.print("Adresse IP : ");
    Serial.println(WiFi.localIP());

    Serial.print("RSSI : ");
    Serial.print(WiFi.RSSI());
    Serial.println(" dBm");

  } else {

    Serial.println("ERREUR : connexion WiFi impossible");
  }
}

void loop() {

  if (WiFi.status() == WL_CONNECTED) {

    Serial.print("WiFi connecte | RSSI : ");
    Serial.print(WiFi.RSSI());
    Serial.println(" dBm");

  } else {

    Serial.println("WiFi deconnecte");
  }

  delay(3000);
}
