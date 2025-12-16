#ifndef STRUCTURES_H
#define STRUCTURES_H
#define ID_MAX 50 

typedef struct NodeAVL {
    char id[ID_MAX];      
    void* data;           
    int hauteur;          
    struct NodeAVL* left;
    struct NodeAVL* right;
} NodeAVL, *PtrNodeAVL;

// structure utile a Liam
typedef struct {
    char id[ID_MAX];
    long capacite;        
    long vol_source;      
    long vol_traite;      
} Usine;

// structure utile a Brayan 
typedef struct ChainonEnfant {
    struct NoeudReseau* cible;
    struct ChainonEnfant* suivant;
} ChainonEnfant;

typedef struct NoeudReseau {
    char id[ID_MAX];
    ChainonEnfant* liste_enfants; 
} NoeudReseau;

#endif