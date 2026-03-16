#include "graphe.h"
#include "outils.h"
#include <stdio.h>
#include <string.h>

double calculer_fuites_km3(const char *csv, const char *id, int *out_trouve) {
    if (out_trouve) *out_trouve = 0;

    FILE *f = fopen(csv, "r");
    if (!f) return -1.0;

    double pertes_km3 = 0.0;
    int trouve = 0;

    char ligne[1024];

    while (fgets(ligne, sizeof(ligne), f)) {
        couper_fin_ligne(ligne);

        char *cols[5];
        decouper_csv_5(ligne, cols);

        
        if (commence_par(cols[1], "Spring #") && strcmp(cols[2], id) == 0) {
            double vol, fuite;
            if (lire_double(cols[3], &vol) && lire_double(cols[4], &fuite)) {
                if (fuite < 0.0) fuite = 0.0;
                if (fuite > 100.0) fuite = 100.0;

                pertes_km3 += vol * (fuite / 100.0);
                trouve = 1;
            }
        }
    }

    fclose(f);

    if (!trouve) {
        return -1.0;
    }

    if (out_trouve) *out_trouve = 1;
    return pertes_km3;
}
