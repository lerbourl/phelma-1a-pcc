#ifndef DEF_SOMMET //evitons les inclusions infinies
#define DEF_SOMMET

#include <stdlib.h>
#include <stdio.h>
#include "larc.h"

// DEFINITION DE STRUCTURE
// sommets
typedef struct {
    char* nom_noeud;
    double x,y;
    char* nom_ligne; // graphe metro par exemple
    L_ARC voisins;} T_SOMMET;

// PROTOTYPES
void affiche_sommet(T_SOMMET*);
void libere_sommet(T_SOMMET);

#endif
