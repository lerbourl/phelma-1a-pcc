#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "arc.h"
#include "sommet.h"
#include "liste.h"
#include "graphe.h"
#include "chemin.h"
#include "hach.h"

int main(int argc, char* argv[]){
	int timer_graphe = clock();
	char* nom_fichier = argv[1];
    printf("\nlecture du fichier %s et création du graphe ...\n", nom_fichier);
	GRAPHE g = lecture_fichier(nom_fichier);

    printf("création de la table de hachage ...\n");
	H_TABLE ht = ht_make_graphe(g);

	printf("\nTemps remplissage graphe/hashtable: %fs\n", (double)(clock() - timer_graphe)/CLOCKS_PER_SEC);

	printf("recherche du plus court chemin entre deux sommets du graphe\n");
	char ns1[100] = " ";
	char ns2[100] = " ";
	H_SOMMET hs1 = NULL;
	while (!hs1){
		/* réupération de la chaine de manière sécurisée */
		printf("\nentrez le nom du sommet de départ: ");                           /* IL FAUDRAIT DEMANDER NUM DE SOMMET OU NOM DE SOMMET => (pas besoin d'utiliser table de hachage si l'utilisisateur renseigne num sommet)*/
		scanf ("%99[^\n]s", ns1);	// 99 caractères, tout sauf \n
		scanf ("%*[^\n]");	// si buffer éxcédent on le vide
		getchar (); 	// on vide le \n du buffer
		/* recherche dans la table */
		hs1 = ht_search(ht, hs_getn, ns1);
	}
	/* idem sommet 2 */
	H_SOMMET hs2 = NULL;
	while (!hs2){
		/* réupération de la chaine de manière sécurisée */
		printf("\nentrez le nom du sommet d'arrivée: ");                           /* IL FAUDRAIT DEMANDER NUM DE SOMMET OU NOM DE SOMMET => (pas besoin d'utiliser table de hachage si l'utilisisateur renseigne num sommet)*/
		scanf ("%99[^\n]s", ns2);	// 99 caractères, tout sauf \n
		scanf ("%*[^\n]");	// si buffer éxcédent on le vide
		getchar (); 	// on vide le \n du buffer
		/* recherche dans la table */
		hs2 = ht_search(ht, hs_getn, ns2);
	}

    /* gestion des correspondances */

	printf("\ngestion des correspondances sur les stations d'arrivée et de départ...\n");
    corresp_set_zero(g, ht, hs1);  // correspondance station de départ
    corresp_set_zero(g, ht, hs2);  // correspondance station de arrivée

	/* plus court chemin */
	printf("calcul du plus court chemin en cours...\n");

	int timer_pcc = clock();
	L_ARC chemin = pcc(g, hs_geti(hs1), hs_geti(hs2));
	printf("\nTemps remplissage graphe/hashtable: %fs\n", (double)(clock() - timer_pcc)/CLOCKS_PER_SEC);

	if (chemin){
	    printf("\n///\n///  Plus Court Chemin entre %s et %s:\n///\n", g.tab_s[hs_geti(hs1)].nom_noeud, g.tab_s[hs_geti(hs2)].nom_noeud);
		/*gestion des correspondances*/
		int depart = hs_geti(hs1), arrivee = hs_geti(hs2);
		chemin = chemin_supr_zero(chemin, &depart, &arrivee);
		/*affichage de l'itinéraire*/
		printf("\ndépart: %s, ligne %s\n", g.tab_s[depart].nom_noeud, g.tab_s[depart].nom_ligne);
		printf("arrivee: %s, ligne %s\n", g.tab_s[arrivee].nom_noeud, g.tab_s[arrivee].nom_ligne);
		affiche_chemin(chemin, g);
		/*cout du chemin*/
		double cout_total = cout_chemin(chemin);
		printf("\nCout Total : %lf\n", cout_total);
		/* libération des structures */
	}
	liste_del(NULL, chemin);	// ici, on ne libère pas les éléments de la
								// liste d'arcs, c'est fait dans libère graphe!
	ht_del(hs_del, ht);	// hs1 et hs2 se libèrent déjà ici
	libere_graphe(g);
	/* timer éxecution */

    return EXIT_SUCCESS;
}
