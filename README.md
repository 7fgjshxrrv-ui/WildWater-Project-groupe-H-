# Projet C-WildWater

**Cadre :** Pré-Ing2 CY Tech - Projet d'Informatique
**Auteurs :** Groupe H

---

## 1. Description du Projet

Ce projet s'inscrit dans le cadre du traitement de données massives issues d'un réseau de distribution d'eau potable. L'objectif est de développer une chaîne de traitement logicielle capable d'analyser un fichier CSV décrivant la topologie et les flux d'un réseau hydraulique.

L'application permet de répondre à deux besoins critiques :
1.  **Analyse Statistique :** Génération d'histogrammes comparatifs pour identifier les stations selon leur capacité, leur production ou leur consommation.
2.  **Détection de Pertes (Leaks) :** Modélisation du réseau sous forme de graphe pour calculer le volume cumulé des pertes d'eau en aval d'une station spécifique.

## 2. Architecture Technique

Le projet repose sur une architecture modulaire combinant trois technologies :

* **Langage C (Back-end) :** Assure les performances de calcul et la gestion des structures de données.
    * *Structure de données :* Utilisation d'un **Arbre Binaire de Recherche Équilibré (AVL)** pour garantir une complexité de recherche en O(log n).
    * *Modélisation :* Les connexions entre stations sont représentées par un système de pointeurs dynamiques (Graphe orienté).
* **Shell Script (Orchestration) :** Interface utilisateur unifiée gérant la compilation, la vérification des fichiers et l'exécution des flux.
* **Gnuplot (Visualisation) :** Génération automatisée des graphiques de sortie.

### Arborescence des Fichiers

* `src/` : Codes sources (.c) contenant la logique métier et les algorithmes.
* `include/` : Fichiers d'en-tête (.h) définissant les structures et prototypes.
* `data/` : Contient le fichier de données `wildwater.csv`.
* `out/` : Répertoire généré contenant les résultats d'analyse (.dat et .png).
* `Makefile` : Script de compilation et de nettoyage.
* `script.sh` : Point d'entrée unique de l'application.

## 3. Prérequis et Compilation

L'environnement d'exécution doit disposer des outils standards : `gcc`, `make` et `gnuplot`.

### Procédure de Compilation

La compilation est automatisée via un Makefile respectant les standards (cibles `all`, `clean`).

1.  **Construction de l'exécutable :**
    ```bash
    make
    ```
    Cela génère l'exécutable binaire à la racine du projet.

2.  **Nettoyage de l'environnement :**
    ```bash
    make clean
    ```
    Cette commande supprime les fichiers objets (`.o`), l'exécutable et vide le répertoire de sortie `out/`.

## 4. Manuel d'Utilisation

Toutes les fonctionnalités doivent être exécutées via le script `script.sh` qui assure l'intégrité du processus.

### Mode Histogramme (Analyse des flux)

Ce mode génère un graphique représentant les stations triées selon le critère choisi. Pour la lisibilité, seules les valeurs les plus pertinentes sont affichées.

* **Syntaxe :** `./script.sh histo <mode>`
* **Arguments disponibles :**
    * `max` : Trie selon la capacité maximale des stations.
    * `src` : Trie selon le volume d'eau capté (production).
    * `reel` : Trie selon le volume réellement consommé.

*Exemple d'exécution :*
```bash
./script.sh histo max
