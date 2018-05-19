#
# Le makefile du projet 1a phelma. Tapper "make" cree l'executable "pcc". Tapper
# "make clean" efface les .o, l'exécutable et permet de recharger les .h.
# make tests génère un éxécuable de tests

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
SRCS = arc.c sommet.c liste.c erreurctrl.c hach.c graphe.c chemin.c tasC.c

# les objets C
OBJS_pcc = $(SRCS:.c=.o main.o)
OBJS_tests = $(SRCS:.c=.o tests.o)

# l'executable
EXC = pcc
TST = tests

#
# build generique
all:	$(EXC)
		@echo executable pcc est compilé avec succès!!

pcc: $(OBJS_pcc)
		$(CC) -o $@ $^ $(LIBS)

tests: $(OBJS_tests)
		$(CC) -o $@ $^ $(LIBS)

%.o: %.c
		$(CC) -o $@ -c $< $(CFLAGS)

clean:
		$(RM) *.o *~ $(EXC) $(TST)
