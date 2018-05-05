#include "liste.h"

Liste creer_liste(){
	return NULL;
}
int liste_vide(Liste l){
	return !l;
}
void visualiser(action affiche_element, Liste l){
	if (!liste_vide(l)){
		affiche_element(l->val);
		visualiser(affiche_element, l->suiv);
	}
}
Liste ajout_tete(void* e, Liste l){
	Liste p = malloc(sizeof(*p));
	if (p == NULL){
		printf("\nerreur malloc %s %s", __FILE__, __func__);
		exit(2);
	}
	p->val = e;
	p->suiv = l;
	return p;
}
Liste supprimer_tete(Liste l){
	if(liste_vide(l)) return creer_liste();
	else{
		Liste p;
		p = l->suiv;
		free(l);
		return p;
	}
}
void liberer(Liste l){
	if (liste_vide(l)) free(l);
	else{
		liberer(l->suiv);
		free(l);
	}
}
Liste ajout_queue(void* e, Liste l){
	if (liste_vide(l)){
		l = malloc(sizeof(*l));
		if (l == NULL){
			printf("\nerreur malloc %s %s", __FILE__, __func__);
			exit(3);
		}
		l->val = e;
		l->suiv = creer_liste();
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
	if (liste_vide(l)) return creer_liste();
	Liste p = malloc(sizeof(*p));
	if (p == NULL){
		printf("\nerreur malloc %s %s", __FILE__, __func__);
		exit(4);
	}
	p->val = l->val;
	p->suiv = copie(l->suiv);
	return p;
}
Liste supprimen(int n, Liste l){
	if (liste_vide(l)) return NULL;
	if (n == 1){
		l->suiv = supprimer_tete(l);
	}
	else{
		supprimen(n - 1, l->suiv);
	}
	return l;
}
