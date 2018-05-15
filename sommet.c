#include "sommet.h"
#include <stdlib.h>
#include <stdio.h>

struct hs_t{
    int index;
    char* nom_noeud;
};

void affiche_sommet(T_SOMMET* s){
    printf("\n%s - ligne %s x:%f y:%f\n", s->nom_noeud, s->nom_ligne, s->x, s->y);
    liste_print(arc_print, s->voisins);
}

void libere_sommet(T_SOMMET s){
    free(s.nom_noeud);
    free(s.nom_ligne);
    liste_del(arc_del, s.voisins);
}

H_SOMMET hs_new(void){
    H_SOMMET hs = calloc(1, sizeof(*hs));
    return hs;
}
int hs_del(void* hs_ambigu){
    H_SOMMET hs = (H_SOMMET)hs_ambigu;
    free(hs->nom_noeud);
    free(hs);
    return 0;
}
int hs_print(void* hs_ambigu){
    H_SOMMET hs = (H_SOMMET)hs_ambigu;
    return printf("  Sommet Hachage index:%d nom noeud:%s\n", hs->index, hs->nom_noeud);
}
H_SOMMET hs_make(int id, char* nom){
    H_SOMMET hs = hs_new();
    hs->index = id;
    hs->nom_noeud = strdup(nom);
    return hs;
}

int hs_geti(H_SOMMET hs){
    return hs->index;
}
char* hs_getn(void* hs_ambigu){
    H_SOMMET hs = (H_SOMMET)hs_ambigu;
    return hs->nom_noeud;
}
