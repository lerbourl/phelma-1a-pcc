#ifndef _CHEMIN_H_//evitons les inclusions infinies
#define _CHEMIN_H_

#include <math.h>
#include <string.h>
#include "graphe.h"
#include "erreurctrl.h"
#include "tasC.h"

L_ARC pcc(GRAPHE, int, int);

double cout_chemin(L_ARC chemin);
void corresp_set_zero(GRAPHE g, H_TABLE ht, H_SOMMET hs);
void affiche_chemin_ds_graphe(H_SOMMET, H_SOMMET, GRAPHE);


L_ARC pcc_sans_tas(GRAPHE g, int d, int a);  //a suppr un fois tas op

#endif
