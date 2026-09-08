# Test du serveur Web ESP32

## Objectif

Vérifier le fonctionnement du serveur Web embarqué sur l'ESP32 pour la supervision du système Smart Solar Tracker IoT.

Ce test permet de valider la communication entre l'ESP32 et un navigateur Web via le réseau Wi-Fi local.

## Configuration

- Microcontrôleur : ESP32 DevKit
- Communication : Wi-Fi 2,4 GHz
- Protocole : HTTP
- Port du serveur : 80
- Bibliothèques :
  - WiFi.h
  - WebServer.h
- Interface : navigateur Web

## Principe de fonctionnement

L'ESP32 se connecte au réseau Wi-Fi puis démarre un serveur HTTP sur le port 80.

Une adresse IP locale est attribuée à l'ESP32.

Depuis un ordinateur connecté au même réseau, cette adresse IP peut être saisie dans un navigateur afin d'accéder à l'interface Web du système.

La page Web est directement hébergée dans la mémoire de l'ESP32.

## Procédure de test

1. Connecter l'ESP32 à l'ordinateur.
2. Renseigner localement le SSID et le mot de passe Wi-Fi.
3. Téléverser le programme dans l'ESP32.
4. Ouvrir le moniteur série à 115200 bauds.
5. Vérifier la connexion au réseau Wi-Fi.
6. Relever l'adresse IP attribuée à l'ESP32.
7. Connecter l'ordinateur au même réseau Wi-Fi.
8. Saisir l'adresse IP de l'ESP32 dans le navigateur.
9. Vérifier l'affichage de la page Web.

## Résultat observé

L'ESP32 se connecte correctement au réseau Wi-Fi et obtient une adresse IP locale.

Le serveur HTTP démarre correctement et l'interface Web est accessible depuis le navigateur de l'ordinateur.

La page de supervision du Smart Solar Tracker peut ainsi être hébergée directement par l'ESP32.

## Conclusion

La communication :

ESP32 → Wi-Fi → serveur HTTP → navigateur Web

est fonctionnelle.

Cette architecture peut être utilisée pour la supervision en temps réel du Smart Solar Tracker IoT.

**Résultat : TEST VALIDÉ**
