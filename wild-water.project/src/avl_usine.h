#ifndef AVL_USINE_H
#define AVL_USINE_H

#include "usine.h"


typedef struct AVLUsine {
    char *cle;
    Usine *valeur;
    int hauteur;
    struct AVLUsine *gauche;
    struct AVLUsine *droite;
} AVLUsine;

AVLUsine *avl_usine_inserer_ou_get(AVLUsine *racine, const char *cle, Usine **out);

Usine    *avl_usine_trouver(AVLUsine *racine, const char *cle);


void      avl_usine_parcours_infixe_inverse(AVLUsine *racine,
                                           void (*visiter)(Usine *u, void *ctx),
                                           void *ctx);

void      avl_usine_liberer(AVLUsine *racine);

#endif
