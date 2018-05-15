#ifndef _ARC_H_ //evitons les inclusions infinies
#define _ARC_H_

#include "liste.h"

// DEFINITION DE STRUCTURE
// arcs TYPE ABSTRAIT
struct arc_t;
typedef struct arc_t *T_ARC;

// liste d'arcs
typedef Liste L_ARC;

//INTERFACE ARCS ET ACCESSEURS
T_ARC arc_new(void);
int arc_del(void*);
int arc_print(void*);
T_ARC arc_make(int arr, float c);

int arc_geta(T_ARC);
int arc_getc(T_ARC);

T_ARC trouve_arc(L_ARC larc_d, int a);    //func utile dans la recherche du pcc

#endif
