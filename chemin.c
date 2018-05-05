#include "chemin.h"


// a mettre dans larc.c ??? OUI CE SERAIT BIEN
T_ARC* trouve_arc(GRAPHE g, int d, int a) {
	L_ARC larc;
	for (larc=g.tab_s[d].voisins ; ((T_ARC*)larc->val)->arrivee!=a ; larc=larc->suiv);
	return larc->val;
}


L_ARC pcc(GRAPHE g, int d, int a) {
	int i;

	/* INIT */
	double* t_pcc = malloc(g.nb_s * sizeof(double));
	err_ctrl(t_pcc, "erreur tableau dynamique t_pcc", __FILE__, __func__, __LINE__, "");
	int* pere = malloc(g.nb_s * sizeof(int));
	err_ctrl(pere, "erreur tableau dynamique pere", __FILE__, __func__, __LINE__, "");
	// s_atteint = tableau des sommets atteint :
	// if s_atteint[j]==0 : j dans C (ensemble des sommets qui restent a visiter)
	// if s_atteint[j]==1 : j dans S (ensemble des sommets dont on connait le ppc en partant de d)
	int* s_atteint = calloc(g.nb_s, sizeof(int));   //utilisation de calloc pour initialiser 0
	err_ctrl(s_atteint, "erreur tableau dynamique s_atteint", __FILE__, __func__, __LINE__, "");

	for(i=0; i<g.nb_s; i++) {
		t_pcc[i] = INFINITY;
		pere[i] = -1;
	}
	t_pcc[d]=0;
	/* FIN INIT */

	//Algo
	double min;
	int j;
	int old_j;   //////////////////////////////////////////////// sert dans la détection du cas ou il n'y a pas de solution
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
		if (old_j==j) {		// pas de min != INF nonn atteint trouvé			///////////////////////////////////////////////////////////
			// cas pas de solution    equivalent au test pcc[j]!= +inf    ///////////////////////////////////////////////////////////
			printf("\nPas de chemin possible, les voitures ne roulent pas sur l'eau\n");
			return NULL;
		}      										///////////////////////////////////////////////////////////
		s_atteint[j] = 1;   //j devient atteint

		/* maj du pcc pour tous les voisins de j */
		for(v=g.tab_s[j].voisins ; v!=NULL ; v=v->suiv) {
			if (t_pcc[((T_ARC*)v->val)->arrivee] > t_pcc[j] + ((T_ARC*)v->val)->cout) {
				t_pcc[((T_ARC*)v->val)->arrivee] = t_pcc[j] + ((T_ARC*)v->val)->cout;
				pere[((T_ARC*)v->val)->arrivee] = j;
			}
		}
		old_j = j;    ////////////////////////////////////////////////////
		//DEBUG
		/*for(i=0;i<g.nb_s;i++)  {
			printf("s_atteint %d %d\n", i,s_atteint[i]);
		}
		printf("\n");*/
		// FIN DEBUG
	} while ( s_atteint[a]==0); ///////////////////////////////////////// && t_pcc[j] != INFINITY);    // fin si arrivee atteinte OU pas de solution
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
