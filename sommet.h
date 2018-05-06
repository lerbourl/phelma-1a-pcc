#ifndef _SOMMET_H_ //evitons les inclusions infinies
#define _SOMMET_H_

#include "arc.h"
#include "string.h"

// DEFINITION DE STRUCTURE
// sommets
typedef struct {
    char* nom_noeud;
    double x,y;
    char* nom_ligne; // graphe metro par exemple
    L_ARC voisins;} T_SOMMET;

// sommets contenant les infos utile pour une table de hachage TYPE ABSTRAIT!
struct hs_t;
typedef struct hs_t *H_SOMMET;

// PROTOTYPES SOMMET
void affiche_sommet(T_SOMMET*);
void libere_sommet(T_SOMMET);

//INTERFACE SOMMET HACHAGE
H_SOMMET hs_new(void);
int hs_del(void*);
int hs_print(void*);
H_SOMMET hs_make(int id, char* nom);
int hs_geti(H_SOMMET);
char* hs_getn(void*);

#endif
