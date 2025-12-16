# WildWater-Project
Projet C-WildWater – CY Tech préIng2
## Description
Ce projet est réalisé dans le cadre du cursus de pré-ingénieur (CY Tech).
L'objectif est de développer une application en **Langage C** optimisée pour traiter de grands volumes de données (Big Data) issus d'un réseau de distribution d'eau.

Le programme analyse un fichier CSV massif décrivant l'architecture du réseau (usines, stations, consommateurs, tronçons) pour répondre à deux problématiques :
1. **Synthèse de production :** Analyse des capacités et consommations par centrale.
2. **Détection de fuites :** Identification des tronçons défectueux via l'analyse des débits entrants/sortants.

## 👥 Équipe de Développement
* **Membre 1 :** [Benjemia Melek]- *Architecte C & Structures de Données* ** Melek-avl_core
* **Membre 2 :** [Shilling Liam] - *Shell, Intégration & Histogrammes*
* **Membre 3 :** [Khalil Brayan] - *Algorithmique Graphe & Calcul des Fuites*

## 🛠️ Choix Techniques & Contraintes
Le projet respecte des contraintes strictes d'implémentation :
* **Langage :** C (Standard) pour tout le traitement de données.
* **Structures de Données :** Utilisation obligatoire d'**Arbres AVL** (Arbres Binaires de Recherche Équilibrés) pour le stockage et la recherche rapide des identifiants stations/usines.
* **Interdiction :** Aucun usage d'outils de traitement de texte (sed, awk, grep) n'est autorisé pour le parsing du CSV. Tout est géré par le programme C.
* **Scripting :** Un script Shell (`c-wire.sh`) pilote la compilation (`Makefile`), l'exécution et la génération des graphiques (`Gnuplot`).

## 📂 Architecture du Projet

```text
Projet_C-Wire/
├── c-wire.sh           # Script principal (Point d'entrée utilisateur)
├── codeC/              # Codes sources C
│   ├── main.c          # Programme principal
│   ├── avl.c           # Implémentation des arbres AVL (Rotations, Insertions)
│   ├── parsing.c       # Lecture et découpage du fichier CSV
│   └── structures.h    # Définition des structures (Usine, Tronçon, AVL)
├── input/              # Dossier pour les fichiers de données (.csv)
├── output/             # Dossier pour les résultats (.dat, images)
├── tests/              # Scripts et fichiers de tests unitaires
├── makefile            # Instructions de compilation
└── README.md           # Documentation du projet
