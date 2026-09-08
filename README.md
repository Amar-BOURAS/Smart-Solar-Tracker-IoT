# ☀️ Smart Solar Tracker IoT

## 📌 Présentation du projet

Le **Smart Solar Tracker IoT** est un système embarqué de suivi solaire automatique à deux axes développé autour d'un **ESP32**.

L'objectif du projet est d'orienter automatiquement un panneau photovoltaïque vers la source lumineuse afin d'améliorer son exposition.

Le système utilise **quatre capteurs LDR** pour détecter la direction de la lumière et **deux servomoteurs** pour assurer l'orientation du panneau :

- mouvement horizontal : **azimut** ;
- mouvement vertical : **élévation**.

L'ESP32 assure également la communication **Wi-Fi** et héberge une **interface Web de supervision** permettant de visualiser les informations du système.

---

## 🎯 Objectifs du projet

Les principaux objectifs du projet sont :

- détecter la direction de la source lumineuse ;
- acquérir les valeurs des quatre capteurs LDR ;
- comparer la luminosité entre les différentes zones ;
- commander automatiquement les deux servomoteurs ;
- réaliser un suivi solaire sur deux axes ;
- mesurer les paramètres électriques du panneau photovoltaïque ;
- connecter le système à un réseau Wi-Fi ;
- développer un serveur Web embarqué sur l'ESP32 ;
- superviser le système depuis un PC ou un smartphone ;
- mettre en place une stratégie de tests et de validation ;
- identifier et corriger les anomalies ;
- assurer la traçabilité du développement avec Git et GitHub.

---

## 🏗️ Architecture générale

Le système est organisé autour de l'ESP32, qui constitue l'unité centrale de traitement.

```text
                    SOURCE LUMINEUSE
                           ☀️
                            │
                            ▼
                  ┌───────────────────┐
                  │   4 CAPTEURS LDR  │
                  │ HG   HD   BG   BD │
                  └─────────┬─────────┘
                            │
                            ▼
                  ┌───────────────────┐
                  │       ESP32       │
                  │                   │
                  │ Acquisition LDR   │
                  │ Calcul des écarts │
                  │ Algorithme suivi  │
                  └─────┬────────┬────┘
                        │        │
                 GPIO25 │        │ GPIO26
                        ▼        ▼
                  ┌─────────┐ ┌─────────┐
                  │ SERVO H │ │ SERVO V │
                  │ Azimut  │ │Élévation│
                  └────┬────┘ └────┬────┘
                       │           │
                       └─────┬─────┘
                             ▼
                  ┌───────────────────┐
                  │      PANNEAU      │
                  │  PHOTOVOLTAÏQUE   │
                  └─────────┬─────────┘
                            │
                            ▼
                         INA219
                    Tension / Courant
                            │
                            ▼
                          ESP32
                            │
                          Wi-Fi
                            │
                            ▼
                  INTERFACE WEB IoT
```

---

## 🔧 Matériel utilisé

| Composant | Fonction |
|---|---|
| ESP32 DevKit | Microcontrôleur principal |
| 4 × capteurs LDR | Détection de la direction lumineuse |
| Servomoteur horizontal | Orientation en azimut |
| Servomoteur vertical | Orientation en élévation |
| INA219 | Mesure des paramètres électriques |
| Panneau photovoltaïque | Production d'énergie |
| Alimentation des servomoteurs | Alimentation des actionneurs |
| PC / Smartphone | Consultation de l'interface Web |

---

## 🔌 Configuration des GPIO

### Capteurs LDR

| Capteur | Position | GPIO ESP32 |
|---|---|---:|
| LDR HG | Haut gauche | GPIO34 |
| LDR HD | Haut droite | GPIO35 |
| LDR BG | Bas gauche | GPIO32 |
| LDR BD | Bas droite | GPIO33 |

### Servomoteurs

| Servomoteur | Fonction | GPIO ESP32 |
|---|---|---:|
| Servo H | Mouvement horizontal / Azimut | GPIO25 |
| Servo V | Mouvement vertical / Élévation | GPIO26 |

### Bus I2C

| Signal | GPIO ESP32 |
|---|---:|
| SDA | GPIO21 |
| SCL | GPIO22 |

Le module **INA219** communique avec l'ESP32 à travers le bus **I2C**.

---

## 💡 Principe de détection de la lumière

Les quatre capteurs LDR sont disposés autour d'une séparation physique permettant de créer une différence d'éclairement lorsque la source lumineuse n'est pas centrée.

```text
                 HAUT
                   ↑

             HG    │    HD
                   │
            ───────┼───────
                   │
             BG    │    BD

                   ↓
                  BAS
```

Avec :

- **HG** : Haut Gauche ;
- **HD** : Haut Droite ;
- **BG** : Bas Gauche ;
- **BD** : Bas Droite.

Les valeurs des quatre capteurs sont acquises par les entrées analogiques de l'ESP32.

Les essais ont également montré que les capteurs peuvent présenter des différences de sensibilité. Ce comportement est pris en compte lors du réglage de l'algorithme de suivi.

---

## 🧠 Algorithme de suivi solaire

Le principe du tracking repose sur la comparaison des quatre zones lumineuses.

### Axe horizontal

```text
Gauche = moyenne(HG, BG)
Droite = moyenne(HD, BD)
```

La différence entre les valeurs gauche et droite permet de déterminer la correction à appliquer au servomoteur horizontal.

### Axe vertical

```text
Haut = moyenne(HG, HD)
Bas  = moyenne(BG, BD)
```

La différence entre les valeurs haut et bas permet de déterminer la correction à appliquer au servomoteur vertical.

Une **zone de tolérance** est utilisée afin d'éviter les mouvements permanents des servomoteurs lorsque les différences de luminosité sont faibles.

L'objectif est d'obtenir un équilibre entre les différentes zones afin d'orienter le panneau vers la source lumineuse.

---

## ⚙️ Commande des servomoteurs

Deux servomoteurs assurent le déplacement mécanique du panneau.

### Servomoteur horizontal

- GPIO : **25**
- Fonction : orientation en **azimut**

### Servomoteur vertical

- GPIO : **26**
- Fonction : orientation en **élévation**

Les deux servomoteurs ont été testés individuellement avant leur intégration dans l'algorithme de suivi automatique.

---

## ⚡ Mesure électrique – INA219

Le projet utilise un module **INA219** pour la mesure des paramètres électriques du panneau.

Communication avec l'ESP32 :

```text
INA219          ESP32

VCC   ────────► 3V3
GND   ────────► GND
SDA   ────────► GPIO21
SCL   ────────► GPIO22
```

Le module a été détecté sur le bus I2C à l'adresse :

```text
0x40
```

L'objectif est de permettre la récupération des paramètres électriques suivants :

- tension ;
- courant ;
- puissance calculée.

À ce stade, la **communication I2C avec l'INA219 est validée**. La validation complète des mesures électriques sera réalisée séparément.

---

## 📡 Communication Wi-Fi

L'ESP32 utilise sa connectivité Wi-Fi pour communiquer avec l'interface de supervision.

Le réseau utilisé doit être compatible **Wi-Fi 2,4 GHz**.

Le test Wi-Fi permet de vérifier :

- la détection du réseau ;
- la connexion de l'ESP32 ;
- l'obtention d'une adresse IP ;
- la qualité du signal ;
- la communication avec le navigateur Web.

Pour des raisons de sécurité, les véritables identifiants Wi-Fi ne sont pas publiés dans le dépôt.

Exemple :

```cpp
const char* ssid = "TON_RESEAU_WIFI";
const char* password = "TON_MOT_DE_PASSE";
```

---

## 🌐 Serveur Web ESP32

Un serveur HTTP est directement hébergé sur l'ESP32.

L'architecture de communication est la suivante :

```text
CAPTEURS
   │
   ▼
 ESP32
   │
   ▼
TRAITEMENT
   │
   ▼
SERVEUR WEB
   │
   ▼
 Wi-Fi
   │
   ▼
PC / SMARTPHONE
   │
   ▼
DASHBOARD IoT
```

L'utilisateur peut accéder à l'interface depuis un navigateur Web lorsque son appareil et l'ESP32 sont connectés au même réseau.

---

## 📊 Interface de supervision

Une interface Web a été développée pour superviser le **Smart Solar Tracker IoT**.

Le dashboard permet notamment de visualiser :

- la position horizontale / azimut ;
- la position verticale / élévation ;
- la valeur du LDR Haut Gauche ;
- la valeur du LDR Haut Droite ;
- la valeur du LDR Bas Gauche ;
- la valeur du LDR Bas Droite ;
- l'état général du système ;
- les données disponibles provenant de l'ESP32.

Les données sont transmises par le serveur Web embarqué et actualisées dans le navigateur.

---

## 🧪 Stratégie de tests et de validation

Le développement suit une approche progressive.

Chaque composant ou fonction importante est testé individuellement avant son intégration dans le système complet.

Cette méthode permet :

- d'identifier les anomalies ;
- d'isoler l'origine d'un problème ;
- de vérifier chaque composant ;
- de documenter les résultats ;
- de faciliter les corrections ;
- d'assurer la traçabilité des validations.

Les différents programmes de test sont disponibles dans :

```text
tests/
```

---

## ✅ Tests du projet

| N° | Test | Objectif | État |
|---:|---|---|---|
| 01 | ESP32 | Vérifier le fonctionnement de la carte | ✅ Validé |
| 02 | LDR unitaire | Vérifier la lecture d'un capteur LDR | ✅ Validé |
| 03 | 4 LDR | Vérifier les quatre capteurs | ✅ Validé |
| 04 | Servo horizontal | Vérifier le mouvement en azimut | ✅ Validé |
| 05 | Servo vertical | Vérifier le mouvement en élévation | ✅ Validé |
| 06 | INA219 I2C | Vérifier la communication I2C | ✅ Validé |
| 07 | Wi-Fi | Vérifier la connexion réseau | ✅ Validé |
| 08 | Serveur Web | Vérifier l'accès au serveur ESP32 | ✅ Validé |
| 09 | Tracking automatique | Tester le suivi de la source lumineuse | 🔧 En cours |

---

## 🧪 Test 01 – ESP32

Le premier test vérifie le fonctionnement général de la carte ESP32 :

- compilation du programme ;
- téléversement ;
- communication série ;
- fonctionnement général du microcontrôleur.

**Résultat : TEST VALIDÉ**

---

## 🧪 Test 02 – LDR unitaire

Un capteur LDR est testé indépendamment afin de vérifier sa réaction aux variations lumineuses.

La valeur analogique évolue lorsque l'éclairage reçu par le capteur est modifié.

**Résultat : TEST VALIDÉ**

---

## 🧪 Test 03 – Quatre LDR

Les quatre capteurs sont connectés simultanément :

```text
HG → GPIO34
HD → GPIO35
BG → GPIO32
BD → GPIO33
```

Une source lumineuse est déplacée dans différentes directions afin de vérifier la réaction des quatre capteurs.

Les essais ont également permis d'observer des différences de sensibilité entre les LDR.

**Résultat : TEST VALIDÉ**

---

## 🧪 Test 04 – Servomoteur horizontal

Le servomoteur horizontal est connecté au **GPIO25**.

Plusieurs positions angulaires sont commandées afin de vérifier son déplacement.

**Résultat : TEST VALIDÉ**

---

## 🧪 Test 05 – Servomoteur vertical

Le servomoteur vertical est connecté au **GPIO26**.

Plusieurs positions sont commandées afin de vérifier le fonctionnement de l'axe d'élévation.

**Résultat : TEST VALIDÉ**

---

## 🧪 Test 06 – Communication INA219

Le module INA219 est connecté au bus I2C :

```text
SDA → GPIO21
SCL → GPIO22
```

Le scanner I2C détecte le module à l'adresse :

```text
0x40
```

Ce test valide la **communication I2C** entre l'ESP32 et l'INA219. Il ne constitue pas encore la validation complète des mesures électriques.

**Résultat : COMMUNICATION I2C VALIDÉE**

---

## 🧪 Test 07 – Wi-Fi

Le test vérifie la capacité de l'ESP32 à se connecter à un réseau Wi-Fi 2,4 GHz.

Les points vérifiés sont :

- détection du réseau ;
- connexion ;
- attribution d'une adresse IP ;
- communication réseau.

**Résultat : TEST VALIDÉ**

---

## 🧪 Test 08 – Serveur Web

Après validation du Wi-Fi, un serveur HTTP est lancé directement sur l'ESP32.

Le test vérifie :

- le démarrage du serveur ;
- l'accès à l'adresse IP de l'ESP32 ;
- l'affichage de la page Web ;
- la communication entre l'ESP32 et le navigateur.

**Résultat : TEST VALIDÉ**

---

## 🧪 Test 09 – Tracking automatique

Cette étape intègre :

- les quatre capteurs LDR ;
- le servomoteur horizontal ;
- le servomoteur vertical ;
- l'algorithme de comparaison de luminosité.

L'objectif est de vérifier que le panneau s'oriente automatiquement en fonction du déplacement de la source lumineuse.

Les paramètres étudiés concernent notamment :

- le sens de rotation des servomoteurs ;
- la zone de tolérance ;
- la stabilité des mesures LDR ;
- les différences de sensibilité entre les capteurs ;
- les limites mécaniques ;
- la stabilité du suivi.

**État : TEST EN COURS DE RÉGLAGE ET DE VALIDATION**

---

## 📁 Organisation du dépôt

```text
Smart-Solar-Tracker-IoT/
│
├── README.md
│
└── tests/
    │
    ├── 01_Test_ESP32/
    │   └── Test_ESP32.ino
    │
    ├── 02_Test_LDR_Unitaire/
    │   ├── Test_LDR_Unitaire.ino
    │   └── README.md
    │
    ├── 03_Test_4_LDR/
    │   ├── Test_4_LDR.ino
    │   └── README.md
    │
    ├── 04_Test_Servo_Horizontal/
    │   ├── Test_Servo_Horizontal.ino
    │   └── README.md
    │
    ├── 05_Test_Servo_Vertical/
    │   ├── Test_Servo_Vertical.ino
    │   └── README.md
    │
    ├── 06_Test_INA219_I2C/
    │   ├── Test_INA219_I2C.ino
    │   └── README.md
    │
    ├── 07_Test_WiFi/
    │   ├── Test_WiFi.ino
    │   └── README.md
    │
    ├── 08_Test_Serveur_Web/
    │   ├── Test_Serveur_Web.ino
    │   └── README.md
    │
    └── 09_Test_Tracking_Automatique/
        └── Test_Tracking_Automatique.ino
```

---

## 💻 Technologies utilisées

### Système embarqué

- ESP32
- Arduino IDE
- C / C++
- ADC
- PWM
- I2C

### IoT et supervision

- Wi-Fi
- HTTP
- WebServer ESP32
- HTML
- CSS
- JavaScript
- JSON

### Gestion du projet

- Git
- GitHub

---

## 🔄 Gestion des versions

Le projet utilise **Git et GitHub** pour assurer :

- la sauvegarde du code source ;
- la traçabilité des modifications ;
- l'historique des tests ;
- la documentation des différentes étapes ;
- le suivi des corrections et améliorations.

Les commits sont réalisés progressivement en fonction des tests et fonctionnalités ajoutés.

---

## 🔍 Méthode de validation

```text
Développement
      │
      ▼
Test unitaire
      │
      ▼
Observation
      │
      ▼
Détection d'anomalie
      │
      ▼
Analyse de la cause
      │
      ▼
Correction
      │
      ▼
Nouveau test
      │
      ▼
Validation
      │
      ▼
Intégration
```

Cette démarche permet de vérifier chaque fonction avant la validation globale du prototype.

---

## 🚨 Gestion des anomalies

Pendant le développement, plusieurs points peuvent nécessiter des ajustements :

- différences de sensibilité entre les LDR ;
- sens de rotation des servomoteurs ;
- limites mécaniques ;
- stabilité des mesures analogiques ;
- réglage de la zone de tolérance ;
- alimentation des actionneurs ;
- communication Wi-Fi ;
- intégration des différents composants.

Une anomalie identifiée est analysée avant modification du programme. Un nouveau test est ensuite réalisé afin de vérifier l'efficacité de la correction.

---

## 📈 Améliorations prévues

Les prochaines évolutions concernent notamment :

- optimisation de l'algorithme de tracking ;
- calibration des quatre LDR ;
- amélioration du filtrage des mesures ;
- stabilisation des mouvements ;
- validation des mesures électriques de l'INA219 ;
- affichage de la tension ;
- affichage du courant ;
- calcul de la puissance ;
- amélioration du dashboard ;
- ajout de graphiques de supervision ;
- gestion des alertes ;
- amélioration de la reconnexion Wi-Fi ;
- tests d'intégration ;
- validation complète du prototype.

---

## 🚧 État actuel du projet

Le projet est actuellement en phase de **développement, intégration et validation**.

### Fonctions déjà testées

- ✅ ESP32
- ✅ LDR unitaire
- ✅ 4 capteurs LDR
- ✅ servomoteur horizontal
- ✅ servomoteur vertical
- ✅ communication I2C avec INA219
- ✅ connexion Wi-Fi
- ✅ serveur Web ESP32
- 🔧 tracking automatique en cours de réglage

---

## 🎓 Contexte du projet

Ce projet est réalisé dans le cadre de ma formation en **Systèmes Embarqués**.

Il permet de mettre en œuvre plusieurs compétences :

- conception d'un système embarqué ;
- programmation d'un microcontrôleur ;
- acquisition de données capteurs ;
- traitement des données ;
- commande d'actionneurs ;
- communication I2C ;
- communication Wi-Fi ;
- développement d'une interface de supervision ;
- stratégie de tests ;
- diagnostic d'anomalies ;
- validation d'un prototype ;
- documentation technique ;
- gestion de versions avec Git et GitHub.

---

## 👤 Auteur

**Amar BOURAS**

**Projet :** Smart Solar Tracker IoT

**Domaine :** Systèmes embarqués • IoT • Électronique • Énergie solaire

---

## 📌 Statut

🚧 **Projet en cours de développement et de validation**

Les différentes fonctionnalités sont testées progressivement avant la validation finale du prototype.

---

⭐ **Smart Solar Tracker IoT — ESP32 | Dual-Axis Solar Tracking | IoT Monitoring**
