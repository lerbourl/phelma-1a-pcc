#include "chemin.h"
#include <stdlib.h>
#include <stdio.h>


double cout_chemin(L_ARC chemin) {
    L_ARC larc;
	double somme = 0;
	for (larc=chemin ; !liste_vide(larc) ; larc=lgetsuiv(larc)) {
		somme += arc_getc((T_ARC)lgetval(larc));
	}
	return somme;
}

void affiche_chemin(L_ARC chemin, GRAPHE g){
    printf("\nsuivre l'itinéraire:");
    if (chemin) {    // Si pas de chemin possible entre les 2 sommets => annule l'affichage du pcc
        L_ARC larc;
    	for (larc=chemin; (larc) ; larc=lgetsuiv(larc)){
            printf("\n--%s--> %s\n", g.tab_s[arc_geta(lgetval(larc))].nom_ligne, g.tab_s[arc_geta(lgetval(larc))].nom_noeud);
            arc_print(lgetval(larc));
        }
    }
}

void corresp_set_zero(GRAPHE g, H_TABLE ht, H_SOMMET hs) {
	Liste l_hs;
	Liste l_voisins;

	// parcours de la liste de hash coorespondante au nom du nom_noeud
	for (l_hs=find_l_hs(ht, hs_getn(hs)) ; !liste_vide(l_hs) ; l_hs=lgetsuiv(l_hs)) {
		// selection les sommets en correspondance (vérif si c'est pas une colision dans la table de hachage)
		if (!strcmp(hs_getn(lgetval(l_hs)), hs_getn(hs) ) ) {
			// parcours de la liste des voisins pour chaque sommet de la correspondance
			for (l_voisins=g.tab_s[hs_geti(lgetval(l_hs))].voisins ; !liste_vide(l_voisins) ; l_voisins=lgetsuiv(l_voisins)) {
//				printf("DEBUG CORRESP  ALL i: %d (%s) --> i: %d (%s)\nCOUT : %lf  a: %d\n", hs_geti(lgetval(l_hs)) , g.tab_s[hs_geti(lgetval(l_hs))].nom_noeud , arc_geta(lgetval(l_voisins)) , g.tab_s[arc_geta(lgetval(l_voisins))].nom_noeud , arc_getc(lgetval(l_voisins)) , arc_geta(lgetval(l_voisins)) );
				// si voisin est dans la m^eme station => cout de l'arc mis à 0
				if (!strcmp( g.tab_s[arc_geta(lgetval(l_voisins))].nom_noeud, g.tab_s[hs_geti(hs)].nom_noeud ) ) {  // utilisation de g.tab_s[hs_geti(hs)].nom_noeud plutot que (hs_getn(hs) pour régler les problèmes de MAJ/min
					// IL FAUT TEST COUT == 360 POUR ETRE SUR QUE ÇA MARCH
//					printf("       ==>   DEBUG CORRESP SET0 i: %d (%s) --> i: %d (%s)\n       COUT : %lf  a: %d\n", hs_geti(lgetval(l_hs)) , g.tab_s[hs_geti(lgetval(l_hs))].nom_noeud , arc_geta(lgetval(l_voisins)) , g.tab_s[arc_geta(lgetval(l_voisins))].nom_noeud , arc_getc(lgetval(l_voisins)) , arc_geta(lgetval(l_voisins)) );
					arc_setc(lgetval(l_voisins), 0);
//					printf("       ==>   DEBUG CORRESP SET0 i: %d (%s) --> i: %d (%s)\n       COUT : %lf  a: %d\n", hs_geti(lgetval(l_hs)) , g.tab_s[hs_geti(lgetval(l_hs))].nom_noeud , arc_geta(lgetval(l_voisins)) , g.tab_s[arc_geta(lgetval(l_voisins))].nom_noeud , arc_getc(lgetval(l_voisins)) , arc_geta(lgetval(l_voisins)) );
				}
			}
		}
	}
}

L_ARC chemin_supr_zero(L_ARC chemin, int* pd, int* pa){
    // on supprime le premier élément si le coût est 0
    while(arc_getc(lgetval(chemin)) == 0){
        *pd = arc_geta(lgetval(chemin));
        chemin = liste_tete_del(NULL, chemin);
    }
    L_ARC larc = chemin;
    while (larc){ //on veut supprimer le dernier élément si le coût est 0!
        if (lgetsuiv(larc) && arc_getc(lgetval(lgetsuiv(larc))) == 0){
            *pa = arc_geta(lgetval(larc));
            liste_del(NULL, lgetsuiv(larc));
            lsetsuiv(larc, liste_new());
            larc = lgetsuiv(larc);
        }
        else{
            larc = lgetsuiv(larc);
        }
    }

    return chemin;
}

L_ARC pcc(GRAPHE g, int d, int a) {
	int i;

	/* INIT */
	double* tab_pcc = malloc(g.nb_s * sizeof(double));
	err_ctrl(tab_pcc, "erreur tableau dynamique tab_pcc", __FILE__, __func__, __LINE__, "");
	
	int* pere = malloc(g.nb_s * sizeof(int));
	err_ctrl(pere, "erreur tableau dynamique pere", __FILE__, __func__, __LINE__, "");
	
	/* s_atteint = tableau des sommets atteint :
	   if s_atteint[j]==0 : j dans C (ensemble des sommets qui restent a visiter)
	   if s_atteint[j]==1 : j dans S (ensemble des sommets dont on connait le ppc en partant de d) */
	int* tas_C = calloc(g.nb_s, sizeof(int)); 
	err_ctrl(tas_C, "erreur tableau dynamique tas_C", __FILE__, __func__, __LINE__, "");

	int* pcc_to_tas = calloc(g.nb_s, sizeof(int));
	err_ctrl(pcc_to_tas, "erreur tableau dynamique pcc_to_tas", __FILE__, __func__, __LINE__, "");
	
	for(i=0; i<g.nb_s; i++) {
		tab_pcc[i] = INFINITY;
		pere[i] = -1;
	}
	tab_pcc[d]=0;
	
	int len_tas=g.nb_s;
	for(i=0; i<g.nb_s; i++) {
		tas_C[i] = i;
		pcc_to_tas[i] = i;
	}
	constructiontas(tas_C, tab_pcc, pcc_to_tas, g.nb_s);
	/* FIN INIT */

	/* Algo */
	int j;
	int k;

	L_ARC v;
	
	do {
		/* recherche du sommet j dans C avec la val de tab_pcc la plus petite */
		j = tas_C[0];   // la min est à la racine du tas
		
/**/	if (tab_pcc[j] == INFINITY) {		// pas de min != INF non atteint trouvé			///////////////////////////////////////////////////////////
											// cas pas de solution    equivalent au test pcc[j]!= +inf de l'énoncé   ///////////////////////////////////////////////////////////
			printf("\nPas de chemin possible, les voitures ne roulent pas sur l'eau (ou à contre-sens)\n");
			/* Libération */
			free(tab_pcc);
			free(pere);
			free(tas_C);
			free(pcc_to_tas);
			return NULL;
		}
		suppressiontas(tas_C, tab_pcc, pcc_to_tas, len_tas);   //j devient atteint
		len_tas--;    // L'ensemble C perd 1 élémént
/*
printf("DEBUG tas\n");
for(i=0;i<g.nb_s;i++)  {
printf("tas  %d  %d  %lf     %d\n", i,tas_C[i], tab_pcc[tas_C[i]], pcc_to_tas[tas_C[i]]);
}*/		
		/* maj du pcc pour tous les voisins de j */
		for(v=g.tab_s[j].voisins ; !liste_vide(v) ; v=lgetsuiv(v)) {
			k = arc_geta((T_ARC)lgetval(v));			
			if (tab_pcc[k] > tab_pcc[j] + arc_getc((T_ARC)lgetval(v))) {
				tab_pcc[k] = tab_pcc[j] + arc_getc((T_ARC)lgetval(v));
/*
printf("DEBUG tas0\n");
for(i=0;i<g.nb_s;i++)  {
printf("tas0 %d  %d  %lf     %d\n", i,tas_C[i], tab_pcc[tas_C[i]], pcc_to_tas[tas_C[i]]);
}*/
				
				// maj tas   il faut:  index k dans pcc => index dans tas
				augmentetas(tas_C, tab_pcc, pcc_to_tas, pcc_to_tas[k]);
/*
printf("DEBUG tasX\n");
for(i=0;i<g.nb_s;i++)  {
printf("tasX %d  %d  %lf     %d\n", i,tas_C[i], tab_pcc[tas_C[i]], pcc_to_tas[tas_C[i]]);
}*/

				pere[arc_geta((T_ARC)lgetval(v))] = j;
			}
		}		
	} while ( pcc_to_tas[a] < len_tas );    // SI pcc_to_tas[a] > len_tas-1  ALORS on a atteint l'arrivée

	/* Creation de chemin a partir de pere */
	L_ARC chemin = liste_new();
	for (i=a; i!=d; i=pere[i]) {
		chemin = ajout_tete(trouve_arc(g.tab_s[pere[i]].voisins, i), chemin);
	}
	
	/* Libération */
	free(tab_pcc);
	free(pere);
	free(tas_C);
	free(pcc_to_tas);
	
	return chemin;
}

L_ARC pcc_sans_tas(GRAPHE g, int d, int a) {
	int i;

	/* INIT */
	double* tab_pcc = malloc(g.nb_s * sizeof(double));
	err_ctrl(tab_pcc, "erreur tableau dynamique tab_pcc", __FILE__, __func__, __LINE__, "");
	
	int* pere = malloc(g.nb_s * sizeof(int));
	err_ctrl(pere, "erreur tableau dynamique pere", __FILE__, __func__, __LINE__, "");
	
	// s_atteint = tableau des sommets atteint :
	// if s_atteint[j]==0 : j dans C (ensemble des sommets qui restent a visiter)
	// if s_atteint[j]==1 : j dans S (ensemble des sommets dont on connait le ppc en partant de d)
	int* s_atteint = calloc(g.nb_s, sizeof(int));   //utilisation de calloc pour initialiser 0
	err_ctrl(s_atteint, "erreur tableau dynamique s_atteint", __FILE__, __func__, __LINE__, "");

	for(i=0; i<g.nb_s; i++) {
		tab_pcc[i] = INFINITY;
		pere[i] = -1;
	}
	tab_pcc[d]=0;
	/* FIN INIT */

	/* Algo */
	double min;
	int j;
	int old_j = -1;	// sert dans la détection du cas ou il n'y a pas de solution
					// =-1 pour qu'il soit bien initialisé avant d'être comparé
	L_ARC v;
	
	do {
		/* recherche du sommet j dans C avec la val de tab_pcc la plus petite */
		min = INFINITY;
		for(i=0; i<g.nb_s; i++) {
			if (!s_atteint[i]) {
				if (tab_pcc[i] < min) {
					j = i;
					min = tab_pcc[i];
				}
			}
		}
		if (old_j==j) {		// pas de min != INF non atteint trouvé			///////////////////////////////////////////////////////////
							// cas pas de solution    equivalent au test pcc[j]!= +inf    ///////////////////////////////////////////////////////////
			printf("\nPas de chemin possible, les voitures ne roulent pas sur l'eau (ou à contre-sens)\n");

			/* Libération */
			free(tab_pcc);
			free(pere);
			free(s_atteint);
			return NULL;
		} 
		s_atteint[j] = 1;   //j devient atteint

		/* maj du pcc pour tous les voisins de j */
		for(v=g.tab_s[j].voisins ; v!=NULL ; v=lgetsuiv(v)) {
			if (tab_pcc[arc_geta((T_ARC)lgetval(v))] > tab_pcc[j] + arc_getc((T_ARC)lgetval(v))) {
				tab_pcc[arc_geta((T_ARC)lgetval(v))] = tab_pcc[j] + arc_getc((T_ARC)lgetval(v));
				pere[arc_geta((T_ARC)lgetval(v))] = j;
			}
		}
		old_j = j;    ////////////////////////////////////////////////////
		//DEBUG
		/*for(i=0;i<g.nb_s;i++)  {
			printf("s_atteint %d %d\n", i,s_atteint[i]);
		}
		printf("\n");*/
		// FIN DEBUG
	} while ( s_atteint[a]==0); ///////////////////////////////////////// && tab_pcc[j] != INFINITY);    // fin si arrivee atteinte OU pas de solution
	//DEBUG
	/*printf("DEBUG2\n");
	for(i=0;i<g.nb_s;i++)  {
		printf("pere %d %d\n", i,pere[i]);
	}*/
	// FIN DEBUG

	/* Creation de chemin a partir de pere */
	L_ARC chemin = liste_new();
	for (i=a; i!=d; i=pere[i]) {
		chemin = ajout_tete(trouve_arc(g.tab_s[pere[i]].voisins, i), chemin);
	}
	
	/* Libération */
	free(tab_pcc);
	free(pere);
	free(s_atteint);
	return chemin;
}
