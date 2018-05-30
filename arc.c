#include "arc.h"
#include <stdlib.h>
#include <stdio.h>

struct arc_t{
    int arrivee;
    double cout;
};

/*
Interface GENERIQUE
*/

T_ARC arc_new(void){
    T_ARC a = calloc(1, sizeof(*a));
    return a;
}
int arc_del(void* a){
    free(a);
    return 0;
}
int arc_print(void* a_ambigu){
    T_ARC a = (T_ARC)a_ambigu;  // a est bien un T_ARC, l'ambiguité du void* est levée
    return printf("    INFO ARC - arrivee:%d cout:%f\n", a->arrivee, a->cout);
}
T_ARC arc_make(int arr, float c){
    T_ARC a = arc_new();
    a->arrivee = arr;
    a->cout = c;
    return a;
}

// trouve dans la liste larc_d, l'arc d'indice a et le retourne. (l'arrivée)
T_ARC trouve_arc(L_ARC larc_d, int a) {
    /* ATTENTION pas de gestion du cas sommet d n'a pas de voisins
	=> pas grave pour son utilisation dans ppc */
	L_ARC larc;
	for (larc=larc_d ; ((T_ARC)lgetval(larc))->arrivee!=a ; larc=lgetsuiv(larc));       //arc_geta((T_ARC)lgetval(larc))!=a
	return (T_ARC)lgetval(larc);
}

int arc_geta(T_ARC a){
    return a->arrivee;
}
double arc_getc(T_ARC a){
    return a->cout;
}

void arc_setc(T_ARC a, double new_cout) {
    a->cout = new_cout;
}
