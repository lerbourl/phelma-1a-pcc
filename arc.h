#ifndef _ARC_H_ //evitons les inclusions infinies
#define _ARC_H_

#include "liste.h"

// DEFINITION DE STRUCTURE
// arcs
typedef struct {
    int arrivee;
    double cout;
} T_ARC;

// liste d'arcs
typedef Liste L_ARC;

// PROTOTYPES
int affiche_arc(void*);

#endif
