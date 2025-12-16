#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

int h(PtrNodeAVL n) {
    if (n == NULL) return 0;
    return n->hauteur;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

PtrNodeAVL rotationGauche(PtrNodeAVL a) {
    PtrNodeAVL pivot = a->right;  
    a->right = pivot->left;       
    pivot->left = a;             
    a->hauteur = max(h(a->left), h(a->right)) + 1;
    pivot->hauteur = max(h(pivot->left), h(pivot->right)) + 1;

    return pivot; 
}

PtrNodeAVL rotationDroite(PtrNodeAVL a) {
    PtrNodeAVL pivot = a->left;
    a->left = pivot->right;
    pivot->right = a;

    a->hauteur = max(h(a->left), h(a->right)) + 1;
    pivot->hauteur = max(h(pivot->left), h(pivot->right)) + 1;

    return pivot;
}

PtrNodeAVL rotationDoubleDroite(PtrNodeAVL a) {

    a->left = rotationGauche(a->left);

    return rotationDroite(a);
}

PtrNodeAVL rotationDoubleGauche(PtrNodeAVL a) {
    a->right = rotationDroite(a->right);
    return rotationGauche(a);
}

int getEquilibre(PtrNodeAVL n) {
    if (n == NULL) return 0;
    return h(n->left) - h(n->right);
}

PtrNodeAVL insertionAVL(PtrNodeAVL a, char* id, void* data, int* h_change) {
    
    if (a == NULL) {
        PtrNodeAVL nouveau = malloc(sizeof(NodeAVL));
        strcpy(nouveau->id, id);
        nouveau->data = data;
        nouveau->hauteur = 1;
        nouveau->left = NULL;
        nouveau->right = NULL;
        *h_change = 1; 
        return nouveau;
    }

    int cmp = strcmp(id, a->id);
    if (cmp < 0) {
        a->left = insertionAVL(a->left, id, data, h_change);
    } else if (cmp > 0) {
        a->right = insertionAVL(a->right, id, data, h_change);
    } else {
        
        return a; 
    }

    a->hauteur = 1 + max(h(a->left), h(a->right));

    int equilibre = getEquilibre(a);

    if (equilibre > 1 && strcmp(id, a->left->id) < 0)
        return rotationDroite(a);

    if (equilibre < -1 && strcmp(id, a->right->id) > 0)
        return rotationGauche(a);

    if (equilibre > 1 && strcmp(id, a->left->id) > 0)
        return rotationDoubleDroite(a);

    if (equilibre < -1 && strcmp(id, a->right->id) < 0)
        return rotationDoubleGauche(a);

    return a;
}