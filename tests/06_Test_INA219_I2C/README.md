# Test de communication I2C - INA219

## Objectif

Vérifier la communication entre l'ESP32 et le capteur de mesure électrique INA219 via le bus I2C.

Ce test permet de valider la détection du module avant son intégration pour la mesure de la tension, du courant et de la puissance du panneau photovoltaïque.

## Configuration

- Microcontrôleur : ESP32 DevKit
- Capteur : INA219
- Protocole : I2C
- SDA : GPIO21
- SCL : GPIO22
- Adresse I2C du INA219 : 0x40

## Câblage I2C

| INA219 | ESP32 |
|---|---|
| VCC | 3.3 V |
| GND | GND |
| SDA | GPIO21 |
| SCL | GPIO22 |

## Procédure de test

1. Connecter le module INA219 à l'ESP32.
2. Vérifier les connexions SDA et SCL.
3. Téléverser le programme `Test_INA219_I2C.ino`.
4. Ouvrir le moniteur série à 115200 bauds.
5. Vérifier la détection du capteur.
6. Observer l'adresse I2C détectée.

## Résultat observé

Le module INA219 est correctement détecté par l'ESP32.

Adresse détectée :

`0x40`

Le moniteur série affiche régulièrement :

`INA219 : OK`

La communication I2C entre l'ESP32 et le module INA219 est donc fonctionnelle.

## Remarque

Ce test valide uniquement la communication I2C avec le INA219.

Les mesures réelles de tension, courant et puissance du panneau photovoltaïque feront l'objet d'un test séparé.

## Conclusion

La communication I2C entre l'ESP32 et le module INA219 est validée.

Le capteur peut maintenant être intégré à la chaîne de mesure électrique du Smart Solar Tracker IoT.

**Résultat : TEST VALIDÉ**
