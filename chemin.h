#ifndef _CHEMIN_H_//evitons les inclusions infinies
#define _CHEMIN_H_

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "graphe.h"
#include "erreurctrl.h"

T_ARC* trouve_arc(GRAPHE g, int d, int a);
L_ARC pcc(GRAPHE, int, int);


#endif
