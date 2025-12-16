#include "noeud.h"
#include <stdlib.h>
#include <string.h>

Noeud *noeud_creer(const char *id) {
    Noeud *n = (Noeud*)calloc(1, sizeof(Noeud));
    if (!n) return NULL;
    n->id = strdup(id);
    if (!n->id) { free(n); return NULL; }
    n->enfants = NULL;
    n->nb_enfants = 0;
    n->en_cours = 0;
    return n;
}

void noeud_liberer(Noeud *n) {
    if (!n) return;
    Arete *a = n->enfants;
    while (a) {
        Arete *nx = a->suivant;
        free(a);
        a = nx;
    }
    free(n->id);
    free(n);
}

int noeud_ajouter_enfant(Noeud *parent, Noeud *enfant, double fuite_pct) {
    if (!parent || !enfant) return 0;
    Arete *a = (Arete*)calloc(1, sizeof(Arete));
    if (!a) return 0;
    a->enfant = enfant;
    a->fuite_pct = fuite_pct;
    a->suivant = parent->enfants;
    parent->enfants = a;
    parent->nb_enfants++;
    return 1;
}
