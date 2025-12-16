#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

void charger_donnees(const char* nom_fichier, PtrNodeAVL* racine_usines, PtrNodeAVL* racine_noeuds);

PtrNodeAVL insertionAVL(PtrNodeAVL a, char* id, void* data, int* h_change);

void afficher_usines_triees(PtrNodeAVL n) {
    if (n != NULL) {
        
        afficher_usines_triees(n->left);

        
        Usine* u = (Usine*)n->data; 
        printf("Usine ID: %s | Capacité: %ld\n", u->id, u->capacite);

        
        afficher_usines_triees(n->right);
    }
}
int main(int argc, char* argv[]) {
    
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <fichier_csv>\n", argv[0]);
        return 1;
    }

    PtrNodeAVL avl_usines = NULL;
    PtrNodeAVL avl_noeuds = NULL; 

    printf("--- Debut du chargement ---\n");
    
    charger_donnees(argv[1], &avl_usines, &avl_noeuds);

    printf("--- Chargement termine. Affichage trie par ID : ---\n");
    
    if (avl_usines == NULL) {
        printf("Attention : L'arbre est vide. Vérifiez le nom du fichier ou le parsing.\n");
    } else {
        afficher_usines_triees(avl_usines);
    }

    return 0;
}