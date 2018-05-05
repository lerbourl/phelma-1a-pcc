#ifndef _SOMMET_H_ //evitons les inclusions infinies
#define _SOMMET_H_

#include "arc.h"

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
