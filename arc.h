#ifndef _ARC_H_ //evitons les inclusions infinies
#define _ARC_H_

#include <stdlib.h>
#include <stdio.h>

// DEFINITION DE STRUCTURE
// arcs
typedef struct {
    int arrivee;
    double cout;
} T_ARC;

// PROTOTYPES
int affiche_arc(void*);

#endif
