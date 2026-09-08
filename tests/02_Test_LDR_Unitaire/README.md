# Test LDR unitaire

## Objectif

Vérifier le fonctionnement d'un capteur LDR connecté à l'ESP32 et observer sa réaction aux variations de luminosité.

## Matériel utilisé

- ESP32 DevKit
- Module LDR
- Lampe torche d'un téléphone
- Arduino IDE
- Câbles de connexion

## Connexion

- Signal du LDR : GPIO34
- Microcontrôleur : ESP32
- Résolution ADC : 12 bits (0 à 4095)

## Procédure de test

1. Connexion du LDR au GPIO34 de l'ESP32.
2. Téléversement du programme de test.
3. Ouverture du moniteur série à 115200 bauds.
4. Éclairage du LDR avec la lampe torche d'un téléphone.
5. Masquage du LDR pour simuler une faible luminosité.
6. Observation des valeurs ADC.

## Résultats observés

Les mesures obtenues pendant les essais sont approximativement :

- Forte luminosité : 5 à 34 ADC
- LDR couvert / obscurité : 3390 à 3440 ADC

La valeur ADC diminue lorsque la luminosité augmente.

## Conclusion

Le test confirme que le capteur LDR réagit correctement aux variations de luminosité.

Le capteur peut donc être utilisé pour la détection de la direction de la source lumineuse dans le système Smart Solar Tracker IoT.

**Résultat : TEST VALIDÉ**
