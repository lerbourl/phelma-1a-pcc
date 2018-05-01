#
# Le makefile du projet 1a phelma. Tapper "make" cree l'executable "pcc". Tapper
# "make clean" efface les .o, l'exécutable et permet de recharger les .h.

#
# definition de variables
# le compilateur
CC = gcc

# flags
# -g ajoute les informations de debug (gdb par exemple)
# -Wall active tous les warnings (aide à un code plus propre)
CFLAGS = -Wall -g

# librairies
LIBS = -lm

# les sources C
SRCS = main.c graphe.c arc.c sommet.c larc.c liste.c chemin.c erreurctrl.c

# les objets C
OBJS = $(SRCS:.c=.o)

# l'executable
EXC = pcc

#
# build generique
all:	$(EXC)
		@echo executable pcc est compilé avec succès!!

pcc: $(OBJS)
		$(CC) -o $@ $^ $(LIBS)

%.o: %.c
		$(CC) -o $@ -c $< $(CFLAGS)

clean:
		$(RM) *.o *~ $(EXC)
