#ifndef OUTILS_H
#define OUTILS_H


void couper_fin_ligne(char *s);


void decouper_csv_5(char *ligne, char *cols[5]);


int commence_par(const char *s, const char *prefix);


int est_tiret(const char *s);


int lire_double(const char *s, double *out);

#endif
