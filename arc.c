#include "arc.h"

void affiche_arc(T_ARC* a){
    printf(" ARC arrivee:%d cout:%f\n", a->arrivee, a->cout);
}

void affiche_element(T_ARC* a){
    affiche_arc(a);
}
