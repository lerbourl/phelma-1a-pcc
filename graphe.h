#ifndef DEF_GRAPHE //evitons les inclusions infinies
#define DEF_GRAPHE

#include <stdlib.h>
#include <stdio.h>
#include "arc.h"
#include "sommet.h"
#include "larc.h"
#include <string.h>

// DEFINITION DE STRUCTURE
// graphes
typedef T_SOMMET* L_SOMMET;
typedef struct {
    L_SOMMET tab_s;
    int nb_s;} GRAPHE;

// PROTOTYPES
void affiche_graphe(GRAPHE);
GRAPHE cree_graphe(int);
GRAPHE lecture_fichier(char*);
void libere_graphe(GRAPHE);

#endif
