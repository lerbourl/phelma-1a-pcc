#include "arc.h"
#include <stdlib.h>
#include <stdio.h>

struct arc_t{
    int arrivee;
    double cout;
};

T_ARC arc_new(void){
    T_ARC a = malloc(1 * sizeof(*a));
    return a;
}
int arc_del(void* a){
    free(a);
    return 0;
}
int arc_print(void* a_ambigu){
    T_ARC a = (T_ARC)a_ambigu;
    return printf("  ARC arrivee:%d cout:%f\n", a->arrivee, a->cout);
}
T_ARC arc_make(int arr, float c){
    T_ARC a = arc_new();
    a->arrivee = arr;
    a->cout = c;
    return a;
}

T_ARC trouve_arc(L_ARC larc_d, int a) {
	L_ARC larc;
	for (larc=larc_d ; ((T_ARC)larc->val)->arrivee!=a ; larc=larc->suiv);
	return larc->val;
}

int arc_geta(T_ARC a){
    return a->arrivee;
}
int arc_getc(T_ARC a){
    return a->cout;
}
