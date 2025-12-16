#include "avl_noeud.h"
#include <stdlib.h>
#include <string.h>

static int max2(int a, int b) { return (a > b) ? a : b; }
static int h(AVLNoeud *n) { return n ? n->hauteur : 0; }

static void maj_hauteur(AVLNoeud *n) {
    n->hauteur = 1 + max2(h(n->gauche), h(n->droite));
}

static int facteur_equilibre(AVLNoeud *n) {
    return n ? (h(n->droite) - h(n->gauche)) : 0;
}

static AVLNoeud *rotation_gauche(AVLNoeud *a) {
    AVLNoeud *b = a->droite;
    AVLNoeud *t2 = b->gauche;
    b->gauche = a;
    a->droite = t2;
    maj_hauteur(a);
    maj_hauteur(b);
    return b;
}

static AVLNoeud *rotation_droite(AVLNoeud *a) {
    AVLNoeud *b = a->gauche;
    AVLNoeud *t2 = b->droite;
    b->droite = a;
    a->gauche = t2;
    maj_hauteur(a);
    maj_hauteur(b);
    return b;
}

static AVLNoeud *reequilibrer(AVLNoeud *n) {
    maj_hauteur(n);
    int fe = facteur_equilibre(n);

    if (fe > 1) {
        if (facteur_equilibre(n->droite) < 0) n->droite = rotation_droite(n->droite);
        return rotation_gauche(n);
    }
    if (fe < -1) {
        if (facteur_equilibre(n->gauche) > 0) n->gauche = rotation_gauche(n->gauche);
        return rotation_droite(n);
    }
    return n;
}

static AVLNoeud *noeud_map_creer(const char *cle, Noeud *val) {
    AVLNoeud *n = (AVLNoeud*)calloc(1, sizeof(AVLNoeud));
    if (!n) return NULL;
    n->cle = strdup(cle);
    if (!n->cle) { free(n); return NULL; }
    n->valeur = val;
    n->hauteur = 1;
    return n;
}

AVLNoeud *avl_noeud_inserer_ou_get(AVLNoeud *racine, const char *cle, Noeud **out) {
    if (!racine) {
        Noeud *val = noeud_creer(cle);
        if (!val) return NULL;
        AVLNoeud *n = noeud_map_creer(cle, val);
        if (!n) { noeud_liberer(val); return NULL; }
        if (out) *out = val;
        return n;
    }

    int cmp = strcmp(cle, racine->cle);
    if (cmp == 0) {
        if (out) *out = racine->valeur;
        return racine;
    } else if (cmp < 0) {
        racine->gauche = avl_noeud_inserer_ou_get(racine->gauche, cle, out);
        if (!racine->gauche) return NULL;
    } else {
        racine->droite = avl_noeud_inserer_ou_get(racine->droite, cle, out);
        if (!racine->droite) return NULL;
    }
    return reequilibrer(racine);
}

Noeud *avl_noeud_trouver(AVLNoeud *racine, const char *cle) {
    while (racine) {
        int cmp = strcmp(cle, racine->cle);
        if (cmp == 0) return racine->valeur;
        racine = (cmp < 0) ? racine->gauche : racine->droite;
    }
    return NULL;
}

void avl_noeud_liberer(AVLNoeud *racine) {
    if (!racine) return;
    avl_noeud_liberer(racine->gauche);
    avl_noeud_liberer(racine->droite);
    noeud_liberer(racine->valeur);
    free(racine->cle);
    free(racine);
}
