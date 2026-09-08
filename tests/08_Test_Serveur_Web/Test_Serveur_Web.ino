#include <WiFi.h>
#include <WebServer.h>

// ==========================================
// TEST SERVEUR WEB ESP32
// Smart Solar Tracker IoT
// ==========================================

// IMPORTANT :
// Ne jamais publier le vrai mot de passe Wi-Fi sur GitHub
const char* ssid = "TON_RESEAU_WIFI";
const char* password = "TON_MOT_DE_PASSE";

WebServer server(80);

// ==========================================
// PAGE WEB DE TEST
// ==========================================

const char PAGE_WEB[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="fr">

<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">

  <title>Smart Solar Tracker IoT</title>

  <style>

    body {
      margin: 0;
      font-family: Arial, sans-serif;
      background-color: #071b2b;
      color: white;
      text-align: center;
    }

    header {
      background-color: #0b2940;
      padding: 25px;
    }

    h1 {
      margin: 0;
      font-size: 32px;
    }

    .subtitle {
      color: #8ecdf5;
      margin-top: 10px;
    }

    .card {
      background-color: #102f46;
      border: 1px solid #1c668f;
      border-radius: 15px;

      max-width: 500px;

      margin: 60px auto;
      padding: 35px;
    }

    .status {
      color: #2ee66b;
      font-size: 24px;
      font-weight: bold;
    }

    .info {
      margin-top: 25px;
      color: #b8d8ec;
    }

  </style>
</head>

<body>

<header>

  <h1>SMART SOLAR TRACKER</h1>

  <div class="subtitle">
    Test serveur Web ESP32
  </div>

</header>

<div class="card">

  <h2>Supervision IoT</h2>

  <p class="status">
    ● ESP32 CONNECTÉ
  </p>

  <p class="info">
    Serveur Web du Smart Solar Tracker opérationnel.
  </p>

  <p>
    Communication Wi-Fi + HTTP validée.
  </p>

</div>

</body>
</html>
)rawliteral";

// ==========================================
// ROUTE PRINCIPALE
// ==========================================

void handleRoot() {

  server.send(
    200,
    "text/html",
    PAGE_WEB
  );

}

// ==========================================
// SETUP
// ==========================================

void setup() {

  Serial.begin(115200);

  delay(1000);

  Serial.println();
  Serial.println("==============================");
  Serial.println(" TEST SERVEUR WEB ESP32");
  Serial.println("==============================");

  WiFi.mode(WIFI_STA);

  WiFi.begin(ssid, password);

  Serial.print("Connexion WiFi");

  while (WiFi.status() != WL_CONNECTED) {

    delay(500);
    Serial.print(".");

  }

  Serial.println();
  Serial.println();
  Serial.println("WiFi connecte !");

  Serial.print("Adresse IP : ");
  Serial.println(WiFi.localIP());

  // Route page principale
  server.on("/", handleRoot);

  // Démarrage serveur
  server.begin();

  Serial.println("Serveur Web demarre.");
  Serial.println();
}

// ==========================================
// LOOP
// ==========================================

void loop() {

  server.handleClient();

}
