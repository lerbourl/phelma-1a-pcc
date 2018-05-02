#include "hash.h"


Listeh creer_Listeh(){
	return NULL;
}
int Liste_videh(Listeh l){
	return !l;
}

Listeh ajout_teteh(H_SOM e, Listeh l){
	Listeh p = malloc(sizeof(*p));
	if (p == NULL){
		printf("\nerreur malloc %s %s", __FILE__, __func__);
		exit(2);
	}
	p->val = e;
	p->suiv = l;
	return p;
}
Listeh supprimer_teteh(Listeh l){
	if(Liste_videh(l)) return creer_Listeh();
	else{
		Listeh p;
		p = l->suiv;
		free(l);
		return p;
	}
}
void libererh(Listeh l){
	if (Liste_videh(l)) free(l);
	else{
		libererh(l->suiv);
		free(l);
	}
}
Listeh ajout_queueh(H_SOM e, Listeh l){
	if (Liste_videh(l)){
		l = malloc(sizeof(*l));
		if (l == NULL){
			printf("\nerreur malloc %s %s", __FILE__, __func__);
			exit(3);
		}
		l->val = e;
		l->suiv = creer_Listeh();
		return l;
	}
	else{
		l->suiv = ajout_queueh(e, l->suiv);
		return l;
	}
}
Listeh concath(Listeh l1, Listeh l2){
	if (Liste_videh(l1)){
		return l2;
	}
	else{
		l1->suiv = concath(l1->suiv, l2);
		return l1;
	}
}
Listeh copieh(Listeh l){
	if (Liste_videh(l)) return creer_Listeh();
	Listeh p = malloc(sizeof(*p));
	if (p == NULL){
		printf("\nerreur malloc %s %s", __FILE__, __func__);
		exit(4);
	}
	p->val = l->val;
	p->suiv = copieh(l->suiv);
	return p;
}
Listeh supprimenh(int n, Listeh l){
	if (Liste_videh(l)) return NULL;
	if (n == 1){
		l->suiv = supprimer_teteh(l);
	}
	else{
		supprimenh(n - 1, l->suiv);
	}
	return l;
}
