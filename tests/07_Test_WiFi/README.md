# Test de connexion Wi-Fi ESP32

## Objectif

Vérifier la capacité de l'ESP32 à se connecter à un réseau Wi-Fi 2,4 GHz.

Ce test permet également de vérifier l'obtention d'une adresse IP et la qualité du signal Wi-Fi avant l'intégration du serveur Web de supervision du Smart Solar Tracker IoT.

## Configuration

- Microcontrôleur : ESP32 DevKit
- Communication : Wi-Fi 2,4 GHz
- Bibliothèque : WiFi.h
- Moniteur série : 115200 bauds

## Procédure de test

1. Configurer le SSID et le mot de passe du réseau Wi-Fi dans le programme local.
2. Téléverser le programme dans l'ESP32.
3. Ouvrir le moniteur série à 115200 bauds.
4. Attendre la tentative de connexion.
5. Vérifier l'état de la connexion.
6. Vérifier l'adresse IP attribuée à l'ESP32.
7. Vérifier la valeur RSSI du signal Wi-Fi.

## Résultat observé

L'ESP32 se connecte correctement au réseau Wi-Fi 2,4 GHz.

Lors du test réalisé, une adresse IP locale a été attribuée à l'ESP32.

La valeur RSSI observée confirme également la réception correcte du réseau Wi-Fi.

Le programme continue ensuite à surveiller l'état de la connexion.

## Sécurité

Les identifiants Wi-Fi réels ne sont pas publiés dans le dépôt GitHub.

Le programme disponible dans ce dépôt utilise uniquement des valeurs génériques :

```cpp
const char* ssid = "TON_RESEAU_WIFI";
const char* password = "TON_MOT_DE_PASSE";
