#ifndef DEF_HASH
#define DEF_HASH

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char* nom;
    int index;} H_SOM;

//définir ailleur ce qu'est ELEMENT!
struct celluleh {
	H_SOM val;
	struct celluleh* suiv;};
typedef struct celluleh* Listeh;

Listeh creer_Listeh();
int Liste_videh(Listeh l);
Listeh ajout_teteh(H_SOM e, Listeh l);
Listeh supprimer_teteh(Listeh l) ;
void libererh(Listeh l);
Listeh ajout_queueh(H_SOM e, Listeh l);
Listeh concathListeh(Listeh l1, Listeh l2);
Listeh copieh(Listeh l);
Listeh supprimenh(int n, Listeh l);

#endif
