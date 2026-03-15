#ifndef USINE_H
#define USINE_H

typedef struct {
    char *id;         
    int   max_km3;    
    double src_km3;   
    double reel_km3;
} Usine;

Usine *usine_creer(const char *id);
void   usine_liberer(Usine *u);

#endif
