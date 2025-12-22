CC=gcc
CFLAGS=-Wall -Wextra -O2 -std=c11

SRC=src/main.c src/outils.c src/usine.c src/avl_usine.c src/noeud.c src/avl_noeud.c src/graphe.c
OBJ=$(SRC:.c=.o)

all: wildwater

wildwater: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

clean:
	rm -f $(OBJ) wildwater
