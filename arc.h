#ifndef DEF_ARC //evitons les inclusions infinies
#define DEF_ARC

#include <stdlib.h>
#include <stdio.h>

// DEFINITION DE STRUCTURE
// arcs
typedef struct {
    int arrivee;
    double cout;} T_ARC;

// PROTOTYPES
void affiche_arc(T_ARC*);

// en vue de L_ARC
void affiche_element(T_ARC*);
typedef T_ARC ELEMENT;

#endif
