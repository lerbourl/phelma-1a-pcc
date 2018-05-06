#include "liste.h"
#include <stdlib.h>
#include <stdio.h>

struct Liste_t{
	void* val;
	struct Liste_t* suiv;
};

Liste liste_new(){
	return NULL;
}
int liste_vide(Liste l){
	return !l;
}
void liste_print(action element_print, Liste l){
	if (!liste_vide(l)){
		element_print(l->val);
		liste_print(element_print, l->suiv);
	}
}
Liste ajout_tete(void* e, Liste l){
	Liste p = calloc(1,sizeof(*p));
	if (p == NULL){
		printf("\nerreur malloc %s %s", __FILE__, __func__);
		exit(2);
	}
	p->val = e;
	p->suiv = l;
	return p;
}
Liste liste_tete_del(action element_del, Liste l){
	if(liste_vide(l)) return liste_new();
	else{
		Liste p;
		p = l->suiv;
		element_del(l->val);
		free(l);
		return p;
	}
}
void liste_del(action element_del, Liste l){
	if (liste_vide(l)) free(l);
	else{
		liste_del(element_del, l->suiv);
		element_del(l->val);
		free(l);
	}
}
Liste ajout_queue(void* e, Liste l){
	if (liste_vide(l)){
		l = calloc(1,sizeof(*l));
		if (l == NULL){
			printf("\nerreur malloc %s %s", __FILE__, __func__);
			exit(3);
		}
		l->val = e;
		l->suiv = liste_new();
		return l;
	}
	else{
		l->suiv = ajout_queue(e, l->suiv);
		return l;
	}
}
Liste concat(Liste l1, Liste l2){
	if (liste_vide(l1)){
		return l2;
	}
	else{
		l1->suiv = concat(l1->suiv, l2);
		return l1;
	}
}
Liste copie(Liste l){
	if (liste_vide(l)) return liste_new();
	Liste p = calloc(1, sizeof(*p));
	if (p == NULL){
		printf("\nerreur malloc %s %s", __FILE__, __func__);
		exit(4);
	}
	p->val = l->val;
	p->suiv = copie(l->suiv);
	return p;
}
Liste supprimen(action element_del, int n, Liste l){
	if (liste_vide(l)) return NULL;
	if (n == 1){
		l->suiv = liste_tete_del(element_del, l);
	}
	else{
		supprimen(element_del, n - 1, l->suiv);
	}
	return l;
}

void* lgetval(Liste l){
	return l->val;
}
Liste lgetsuiv(Liste l){
	return l->suiv;
}
