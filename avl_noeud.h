#ifndef AVL_NOEUD_H
#define AVL_NOEUD_H

#include "noeud.h"

typedef struct AVLNoeud {
    char *cle;
    Noeud *valeur;
    int hauteur;
    struct AVLNoeud *gauche;
    struct AVLNoeud *droite;
} AVLNoeud;

AVLNoeud *avl_noeud_inserer_ou_get(AVLNoeud *racine, const char *cle, Noeud **out);
Noeud    *avl_noeud_trouver(AVLNoeud *racine, const char *cle);
void      avl_noeud_liberer(AVLNoeud *racine);

#endif
