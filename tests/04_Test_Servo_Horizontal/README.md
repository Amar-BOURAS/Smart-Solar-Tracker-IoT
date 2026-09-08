# Test du servomoteur horizontal

## Objectif

Vérifier le fonctionnement du servomoteur responsable du déplacement horizontal (azimut) du panneau photovoltaïque.

## Configuration

- Microcontrôleur : ESP32 DevKit
- Signal du servomoteur : GPIO25
- Fonction : orientation horizontale du panneau
- Bibliothèque : ESP32Servo

## Procédure de test

1. Connecter le signal du servomoteur horizontal au GPIO25.
2. Alimenter correctement le servomoteur.
3. Relier la masse de l'alimentation du servo à la masse de l'ESP32.
4. Téléverser le programme `Test_Servo_Horizontal.ino`.
5. Ouvrir le moniteur série à 115200 bauds.
6. Observer les déplacements successifs demandés :
   - 60°
   - 90°
   - 120°
7. Vérifier que le servomoteur répond aux différentes consignes.

## Résultat observé

Le servomoteur horizontal reçoit les différentes consignes de position envoyées par l'ESP32 via le GPIO25.

Les essais permettent de vérifier le déplacement du mécanisme horizontal du suiveur solaire.

## Conclusion

La commande du servomoteur horizontal par l'ESP32 sur le GPIO25 est fonctionnelle.

Ce servomoteur pourra être utilisé par l'algorithme de suivi solaire pour corriger l'orientation gauche/droite du panneau.

**Résultat : TEST VALIDÉ**
