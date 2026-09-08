# Test des 4 capteurs LDR

## Objectif

Vérifier simultanément le fonctionnement des quatre capteurs LDR du système Smart Solar Tracker IoT.

Ces quatre capteurs permettent de détecter la direction de la source lumineuse afin de commander l'orientation du panneau photovoltaïque.

## Configuration des capteurs

| Capteur | Position | GPIO ESP32 |
|---|---|---|
| HG | Haut Gauche | GPIO34 |
| HD | Haut Droite | GPIO35 |
| BG | Bas Gauche | GPIO32 |
| BD | Bas Droite | GPIO33 |

## Matériel utilisé

- ESP32 DevKit
- 4 modules LDR
- Lampe torche d'un téléphone
- Arduino IDE
- Câbles de connexion

## Procédure de test

1. Connecter les quatre LDR à l'ESP32.
2. Téléverser le programme `Test_4_LDR.ino`.
3. Ouvrir le moniteur série à 115200 bauds.
4. Observer les valeurs des quatre capteurs.
5. Déplacer la lampe torche vers les différentes zones :
   - haut gauche ;
   - haut droite ;
   - bas gauche ;
   - bas droite.
6. Vérifier que les valeurs des capteurs évoluent en fonction de la position de la source lumineuse.

## Résultat observé

Les quatre capteurs LDR réagissent aux variations de luminosité.

Les essais avec la lampe torche permettent d'observer une variation des mesures HG, HD, BG et BD en fonction de la direction de la lumière.

Les capteurs présentent cependant des différences de valeurs entre eux pour une même condition lumineuse. Cette différence devra être prise en compte dans l'algorithme de suivi.

## Conclusion

Les quatre entrées analogiques de l'ESP32 et les quatre capteurs LDR sont fonctionnels.

Les mesures peuvent être utilisées pour calculer les différences :

- gauche / droite pour le déplacement horizontal ;
- haut / bas pour le déplacement vertical.

**Résultat : TEST VALIDÉ**
