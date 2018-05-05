#include "arc.h"
#include <stdlib.h>
#include <stdio.h>

//passer un pointeur sur arc
//doit être de la forme "int print(void*)" (compatibilité avec le fichier liste)
int affiche_arc(void* pa_ambigu){
    T_ARC* pa = (T_ARC*) pa_ambigu;
    return printf("  ARC arrivee:%d cout:%f\n", pa->arrivee, pa->cout);
}
