#ifndef DEF_LISTE
#define DEF_LISTE

#include <stdio.h>
#include <stdlib.h>
#include "arc.h"
#include "erreurctrl.h"

//définir ailleur ce qu'est ELEMENT!
struct cellule {
	ELEMENT val;
	struct cellule* suiv;};
typedef struct cellule* Liste;

Liste creer_liste();
int liste_vide(Liste l);
void visualiser(Liste l);
Liste ajout_tete(ELEMENT c, Liste l);
Liste supprimer_tete(Liste l) ;
void liberer(Liste l);
Liste ajout_queue(ELEMENT c, Liste l);
Liste concat(Liste l1, Liste l2);
Liste copie(Liste l);
Liste supprimen(int n, Liste l);

#endif
