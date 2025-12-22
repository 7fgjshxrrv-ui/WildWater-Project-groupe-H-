#!/bin/bash

DEBUT=$(date +%s)

afficher_duree() {
  FIN=$(date +%s)
  echo "Durée totale: $((FIN - DEBUT)) s"
}

erreur() {
  echo "Erreur: $1" 1>&2
  afficher_duree
  exit "$2"
}

CSV="data/wildwater.csv"
EXEC="./wildwater"
OUTDIR="out"

if [ ! -f "$CSV" ]; then
  erreur "CSV introuvable: $CSV" 10
fi

if [ ! -d "$OUTDIR" ]; then
  mkdir "$OUTDIR" || erreur "Impossible de créer $OUTDIR" 11
fi

if [ ! -x "$EXEC" ]; then
  echo "[INFO] Compilation (make)..."
  make || erreur "Compilation échouée" 12
fi

if [ $# -lt 2 ]; then
  echo "Usage:"
  echo "  $0 histo max|src|reel"
  echo "  $0 leaks \"Facility complex #...\""
  erreur "Commande incomplète" 20
fi

if [ "$1" = "histo" ]; then
  MODE="$2"
  if [ "$MODE" != "max" ] && [ "$MODE" != "src" ] && [ "$MODE" != "reel" ]; then
    erreur "Mode invalide: $MODE" 21
  fi

  DAT="$OUTDIR/histo_${MODE}.dat"
  PNG="$OUTDIR/histo_${MODE}.png"

  "$EXEC" histo "$MODE" "$CSV" "$DAT" || erreur "C a échoué (histo)" 30

  gnuplot <<EOF2
set terminal png
set output "${PNG}"
set datafile separator ";"
set style data histograms
set style fill solid
set xtics rotate by -45
set title "Histogramme - ${MODE}"
plot "${DAT}" using 2:xtic(1) title "${MODE}"
EOF2

  [ $? -ne 0 ] && erreur "Gnuplot a échoué" 31

  echo "[OK] ${DAT} et ${PNG}"
  afficher_duree
  exit 0
fi

if [ "$1" = "leaks" ]; then
  ID="$2"
  DAT="$OUTDIR/leaks.dat"
  "$EXEC" leaks "$ID" "$CSV" "$DAT" || erreur "C a échoué (leaks)" 40
  echo "[OK] Ajout dans ${DAT}"
  afficher_duree
  exit 0
fi

erreur "Commande inconnue: $1" 60
