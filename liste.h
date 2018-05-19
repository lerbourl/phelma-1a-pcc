/*
Structure de liste (structure de données abstraites)
dans le champ val est en fait stocké un TYPE ABSTRAIT!
C'est à dire qu'il doit respecter la forme d'un type abstrait.
liste_print et liste_del attendent que l'on passe en paramètre
une fonction de callback.
*/
#ifndef _LISTE_H_
#define _LISTE_H_

#include "callbacks.h"

struct Liste_t;
typedef struct Liste_t* Liste;

//INTERFACE LISTE ET ACCESSEURS
Liste liste_new();
void liste_print(action, Liste);
Liste liste_tete_del(action, Liste) ;
void liste_del(action, Liste);
int liste_vide(Liste l);
Liste ajout_tete(void*, Liste);
Liste ajout_queue(void*, Liste);
Liste concat(Liste l1, Liste l2);
Liste copie(Liste l);
Liste supprimen(action element_del, int n, Liste l);
void* lgetval(Liste);
Liste lgetsuiv(Liste);
void lsetsuiv(Liste l, Liste s);

#endif
