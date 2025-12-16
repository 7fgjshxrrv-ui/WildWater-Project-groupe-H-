#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

#define BUFFER_SIZE 1024 


void charger_donnees(const char* nom_fichier, PtrNodeAVL* racine_usines, PtrNodeAVL* racine_noeuds) {
    
    FILE* fichier = fopen(nom_fichier, "r");
    if (fichier == NULL) {
        perror("Erreur d'ouverture du fichier");
        exit(1); 
    }

    char ligne[BUFFER_SIZE];
    char* token; 

    while (fgets(ligne, BUFFER_SIZE, fichier) != NULL) {
        
        ligne[strcspn(ligne, "\n")] = 0;
        if (strlen(ligne) == 0) continue;
        char* type_str = strtok(ligne, ";");
        if (type_str == NULL) continue;
        // --- CAS 1 : C'est une USINE ---
        if (strcmp(type_str, "USINE") == 0) {
            // Création de la structure Usine
            Usine* u = (Usine*)malloc(sizeof(Usine));
            // Col 2 : ID de l'usine
            token = strtok(NULL, ";");
            if (token) strcpy(u->id, token);
            // Col 3 : Capacité (conversion string -> long)
            token = strtok(NULL, ";");
            u->capacite = (token) ? atol(token) : 0;
            // Initialisation des compteurs
            u->vol_source = 0;
            u->vol_traite = 0;
            // Insertion dans l'AVL des Usines (appel à la fonction avl.c)
            int h_change = 0;
            *racine_usines = insertionAVL(*racine_usines, u->id, u, &h_change);
        }
        
        else if (strcmp(type_str, "TRONCON") == 0) {
            char* id_depart = strtok(NULL, ";");
            char* id_arrivee = strtok(NULL, ";");
        }
        
        else {
            
        }
    }

    // 4. Fermeture du fichier
    // fclose obligatoire pour libérer le descripteur
    fclose(fichier);
    
    printf("Chargement terminé.\n");
}