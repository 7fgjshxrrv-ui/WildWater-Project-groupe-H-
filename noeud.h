#ifndef NOEUD_H
#define NOEUD_H

typedef struct Noeud Noeud;

typedef struct Arete {
    Noeud *enfant;
    double fuite_pct;
    struct Arete *suivant;
} Arete;

struct Noeud {
    char *id;
    Arete *enfants;
    int nb_enfants;
    int en_cours; /* anti-boucle simple */
};

Noeud *noeud_creer(const char *id);
void   noeud_liberer(Noeud *n);

int    noeud_ajouter_enfant(Noeud *parent, Noeud *enfant, double fuite_pct);

#endif
