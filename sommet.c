#include "sommet.h"

void affiche_sommet(T_SOMMET* s){
    printf("\n%s - ligne %s x:%f y:%f\n", s->nom_noeud, s->nom_ligne, s->x, s->y);
    affiche_larc(s->voisins);
}

void libere_sommet(T_SOMMET s){
    liberer(s.voisins);
}
