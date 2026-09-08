# Test du servomoteur vertical

## Objectif

Vérifier le fonctionnement du servomoteur responsable du déplacement vertical (élévation) du panneau photovoltaïque.

## Configuration

- Microcontrôleur : ESP32 DevKit
- Signal du servomoteur : GPIO26
- Fonction : orientation verticale du panneau
- Bibliothèque utilisée : ESP32Servo

## Procédure de test

1. Connecter le signal du servomoteur vertical au GPIO26.
2. Alimenter correctement le servomoteur.
3. Relier la masse de l’alimentation du servo à la masse de l’ESP32.
4. Téléverser le programme `Test_Servo_Vertical.ino`.
5. Ouvrir le moniteur série à 115200 bauds.
6. Observer les déplacements successifs demandés :
   - 80°
   - 90°
   - 100°
7. Vérifier que le servomoteur suit correctement les consignes.

## Résultat observé

Le servomoteur vertical répond correctement aux différentes consignes envoyées par l’ESP32.

Le mouvement observé suit correctement la séquence :

80° → 90° → 100° → 80° → ...

Le signal de commande envoyé sur le GPIO26 permet donc de contrôler correctement l’axe vertical.

## Conclusion

Le servomoteur vertical et la commande par l’ESP32 sur le GPIO26 sont fonctionnels.

Ce servomoteur peut être utilisé par l’algorithme de suivi solaire pour ajuster l’élévation du panneau photovoltaïque.

**Résultat : TEST VALIDÉ**
