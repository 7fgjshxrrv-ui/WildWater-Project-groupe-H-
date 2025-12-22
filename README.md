Projet C – WildWater (préING2)

##Description générale#
Ce projet a pour objectif de développer une application permettant d’analyser des données issues
d’un système de distribution d’eau potable.
À partir d’un fichier CSV représentant un réseau de distribution, le programme permet de générer
des histogrammes de performance des usines
et de calculer le volume d’eau perdu sur le réseau aval d’une usine donnée.
Organisation du projet
Le projet est composé d’un programme en langage C, d’un script shell servant de point d’entrée,
et d’un Makefile pour la compilation.
Compilation
La compilation se fait uniquement via make.
Commande :
make
Nettoyage :
make clean
Exécution
Toutes les fonctionnalités sont accessibles via le script shell.
Commandes :
./script.sh histo max
./script.sh histo src
./script.sh histo real
./script.sh leaks "Facility complex #IDENTIFIANT"
Résultats
Les résultats sont générés dans le dossier tests sous forme de fichiers .dat et .png.
Les histogrammes affichent uniquement les valeurs extrêmes afin de garantir la lisibilité.
Gestion des erreurs
Si une usine n’est pas trouvée, la valeur -1 est retournée conformément au cahier des charges.
Choix techniques
Utilisation d’arbres AVL pour des recherches efficaces.
Les calculs sont effectués exclusivement en langage C.
Le script shell se limite à l’orchestration.
Conformité
Le projet respecte les exigences du cahier des charges :
- Compilation via make
- Séparation en modules
- Utilisation d’AVL
- Gestion des erreurs
- Résultats reproductibles
