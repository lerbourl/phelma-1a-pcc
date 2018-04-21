#
# Le makefile du projet 1a phelma. Tapper "make" cree l'executable "pcc". Tapper
# "make clean" efface les .o et l'exécutable.

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
SRCS = main.c fichier.c arc_sommet.c

# les objets C
OBJS = $(SRCS:.c=.o)

# l'executable
EXC = pcc

#
# build generique
all:	$(EXC)
		@echo executable pcc est compilé avec succès!!

$(EXC): $(OBJS)
		$(CC) $(CFLAGS) -o $(EXC) $(OBJS) $(LIBS)

clean:
		$(RM) *.o *~ $(EXC)
