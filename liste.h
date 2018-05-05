/*
Structure de liste
dans le champ val est en fait stocké un pointeur sur l'élément que l'on veut
ranger dans la liste.
aff_liste attend que l'on passe en paramètre une fonction de callback
*/
#ifndef _LISTE_H_
#define _LISTE_H_

#include "callbacks.h"

struct Liste_t {
	void* val;
	struct Liste_t* suiv;
};
typedef struct Liste_t* Liste;

Liste creer_liste();
int liste_vide(Liste l);
void aff_liste(action, Liste);
Liste ajout_tete(void*, Liste);
Liste supprimer_tete(Liste l) ;
void lib_liste(Liste l);
Liste ajout_queue(void*, Liste);
Liste concat(Liste l1, Liste l2);
Liste copie(Liste l);
Liste supprimen(int n, Liste l);

#endif
