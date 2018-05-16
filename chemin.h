#ifndef _CHEMIN_H_//evitons les inclusions infinies
#define _CHEMIN_H_

#include <math.h>
#include "graphe.h"
#include "erreurctrl.h"

L_ARC pcc(GRAPHE, int, int);

double cout_chemin(L_ARC chemin);

#endif
