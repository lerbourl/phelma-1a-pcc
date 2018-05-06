/*
construit une table de hachage depuis un tableau d'elements
*/

#ifndef _HASH_H_
#define _HASH_H_

#include "ctype.h"
#include "liste.h"
#include "callbacks.h"
#include "graphe.h"

typedef struct {
    Liste* table;
    int d_table;
} H_TABLE;


unsigned int hachage(unsigned char* mot, int dim_tab_hach);
H_TABLE tableh_constr_graphe(GRAPHE g);
void tableh_affiche(action f, H_TABLE th);
void tableh_libere(H_TABLE th);

#endif
