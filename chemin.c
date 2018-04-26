#include "chemin.h"


// a mettre dans larc.c ???
T_ARC trouve_arc(GRAPHE g, int d, int a) {
	L_ARC larc;
	for (larc=g.tab_s[d].voisins ; larc->val.arrivee!=a ; larc=larc->suiv);
	return larc->val;
}


L_ARC pcc(GRAPHE g, int d, int a) {
	// CAS SI PAS DE CHEMIN ??? A VERIF
	
	int i;

	/* INIT */
	double* t_pcc = malloc(g.nb_s * sizeof(double));
	if (t_pcc==NULL) exit(3);
	int* pere = malloc(g.nb_s * sizeof(int));
	if (pere==NULL) exit(3);
	// s_atteint = tableau des sommets atteint :
	// if s_atteint[j]==0 : j dans C (ensemble des sommets qui restent a visiter)
	// if s_atteint[j]==1 : j dans S (ensemble des sommets dont on connait le ppc en partant de d)
	int* s_atteint = calloc(g.nb_s, sizeof(int));   //utilisation de calloc pour initialiser 0
	if (s_atteint==NULL) exit(3);
	
	for(i=0; i<g.nb_s; i++) {
		t_pcc[i] = INFINITY;
		pere[i] = -1;
	}
	t_pcc[d]=0;
	/* FIN INIT */

	//Algo
	double min;
	int j;
	L_ARC v;
	do {
		/* recherche du sommet j dans C avec le pcc */
		min = INFINITY;
		for(i=0; i<g.nb_s; i++) {
			if (!s_atteint[i]) {
				if (t_pcc[i] < min) {
					j = i;
					min = t_pcc[i];
				}
			}
		}
		s_atteint[j] = 1;   //j devient atteint
		
		/* maj du pcc pour tous les voisins de j */
		for(v=g.tab_s[j].voisins ; v!=NULL ; v=v->suiv) {
			if (t_pcc[v->val.arrivee] > t_pcc[j] + v->val.cout) {
				t_pcc[v->val.arrivee] = t_pcc[j] + v->val.cout;
				pere[v->val.arrivee] = j;
			}
		}
		//DEBUG
		/*for(i=0;i<g.nb_s;i++)  {
			printf("s_atteint %d %d\n", i,s_atteint[i]);
		}
		printf("\n");*/
		// FIN DEBUG
	} while ( s_atteint[a]==0 && t_pcc[j] != INFINITY);    // fin si arrivee atteinte OU pas de solution
	//DEBUG
	/*printf("DEBUG2\n");
	for(i=0;i<g.nb_s;i++)  {
		printf("pere %d %d\n", i,pere[i]);
	}*/
	// FIN DEBUG
	
	/* Creation de chemin a partir de pere */
	L_ARC chemin = creer_liste();
	for (i=a; i!=d; i=pere[i]) {
		chemin = ajout_tete(trouve_arc(g, pere[i], i), chemin);
	}
	return chemin;
}
