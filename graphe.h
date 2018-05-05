#ifndef _GRAPHE_H_ //evitons les inclusions infinies
#define _GRAPHE_H_

#include <stdlib.h>
#include <stdio.h>
#include "arc.h"
#include "sommet.h"
#include "larc.h"
#include "erreurctrl.h"
#include <string.h>


// DEFINITION DE STRUCTURE
// graphes
typedef T_SOMMET* TAB_SOMMET;
typedef struct {
    int nb_s;
    TAB_SOMMET tab_s;} GRAPHE;

// PROTOTYPES
void affiche_graphe(GRAPHE);
GRAPHE cree_graphe(int);
GRAPHE lecture_fichier(char*);
void libere_graphe(GRAPHE);

#endif
