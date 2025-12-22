#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graphe.h"

int main(int argc, char **argv) {
    if (argc < 5) {
        fprintf(stderr, "Usage: %s <histo|leaks> <mode|id> <csv> <out>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "leaks") == 0) {
        int trouve = 0;
        double pertes = calculer_fuites_km3(argv[3], argv[2], &trouve);

        if (!trouve || pertes < 0.0) {
            fprintf(stderr, "Erreur: usine non trouvée ou calcul impossible\n");
            return 2;
        }

        FILE *out = fopen(argv[4], "w");
        if (!out) {
            perror("fopen");
            return 3;
        }

        fprintf(out, "%.6f\n", pertes);
        fclose(out);
        return 0;
    }

    fprintf(stderr, "Mode non supporté\n");
    return 4;
}
