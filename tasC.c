#include <stdio.h>
#include <stdlib.h>
#include "tasC.h"


void switch_val(int* tas, int* pcc_to_tas, int i, int j) {
	int tmp = tas[i];
	tas[i] = tas[j];
	tas[j] = tmp;
	
	// màj de pcc_to_tas
	tmp = pcc_to_tas[tas[i]];
	pcc_to_tas[tas[i]] = pcc_to_tas[tas[j]];
	pcc_to_tas[tas[j]] = tmp;
}

int p(int i) {return (i-1)/2;}
int fg(int i) {return 2*(i+1)-1;}
int fd(int i) {return 2*(i+1);}

void augmentetas(int* tas, double* tab_pcc, int* pcc_to_tas, int i) {
	while (tab_pcc[tas[i]] < tab_pcc[tas[p(i)]]) {     // la racine se compare a elle même et stop le while         //////////
		switch_val(tas, pcc_to_tas, i, p(i));
		i = p(i);
	}
}


void constructiontas(int* tas, double* tab_pcc, int* pcc_to_tas, int n) {
	int i;
	for(i=0; i<n; i++) augmentetas(tas, tab_pcc, pcc_to_tas, i);	
}


void descendretas(int* tas, double* tab_pcc, int* pcc_to_tas, int i) {
	int z = 0;
	
	while (fg(z) < i) {     // au mois encore un fils à vérifier
		if (fd(z) > i-1)  {    // noeud z n'a pas de fils droit
			if (tab_pcc[tas[z]] > tab_pcc[tas[fg(z)]]) {                                           //////////
				switch_val(tas, pcc_to_tas, z, fg(z));
				z = fg(z);
			}
			else {   // c'est un tas
				return;
			}
		}
		// else => noeud z à 2 fils
		else if (tab_pcc[tas[fg(z)]] < tab_pcc[tas[fd(z)]]) {                           ////////////
			if (tab_pcc[tas[z]] > tab_pcc[tas[fg(z)]]) {                                ////////////
				switch_val(tas, pcc_to_tas, z, fg(z));
				z = fg(z);
			}
			else {  // c'est un tas
				return;
			}
		}
		// On à : tas[fg(z)] > tas[fd(z)]
		else if (tab_pcc[tas[z]] > tab_pcc[tas[fd(z)]]) {                      ////////////
			switch_val(tas, pcc_to_tas, z, fd(z));                       ////////////
			z = fd(z);
		}
		else {  // c'est un tas
			return;
		}
	}
}


void suppressiontas(int* tas, double* tab_pcc, int* pcc_to_tas, int i) {
	switch_val(tas, pcc_to_tas, 0, i-1);
	descendretas(tas, tab_pcc, pcc_to_tas, i-1);
}

/*
void tri(double* tas, int n) {
	constructiontas(tas, n);
	int i;
	for(i=n; i>1; i--) {      // le cas  i==1  est inutile
		suppressiontas(tas, i);
	}
	
}
*/

/*
int main() {
	int n = 8;
	
	double *t1, *t2;
	if ( (t1=calloc(n,sizeof(*t1))) == NULL) {printf("Allocation impossible\n"); exit(1); } 
	//if ( (t2=calloc(n,sizeof(*t1))) == NULL) {printf("Allocation impossible\n"); exit(1); }
	
	t1[0] = 42;
	t1[1] = 15;
	t1[2] = 78;
	t1[3] = 96;
	t1[4] = 12;
	t1[5] = 63;
	t1[6] = 24;
	t1[7] = 5;

	//tri(t1, 7);
	constructiontas(t1, n);
	
	
	int i;
	for (i=0; i<n ; i++) {
		printf("%d  %lf\n",i ,t1[i]);
	}
	
	
	
	return 0;
}*/



