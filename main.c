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

	int timer = clock();

	char* nom_fichier = argv[1];
    printf("\nlecture du fichier %s et création du graphe ...\n", nom_fichier);
	GRAPHE g = lecture_fichier(nom_fichier);
	//affiche_graphe(g);
    printf("création de la table de hachage ...\n");
	H_TABLE ht = ht_make_graphe(g);

	printf("recherche du plus court chemin entre deux sommets du graphe\n");
	char ns1[100] = " ";
	char ns2[100] = " ";
	H_SOMMET hs1 = NULL;
	while (!hs1){
		/* réupération de la chaine de manière sécurisée */
		printf("\nentrez le nom du 1er sommet: ");                           /* IL FAUDRAIT DEMANDER NUM DE SOMMET OU NOM DE SOMMET => (pas besoin d'utiliser table de hachage si l'utilisisateur renseigne num sommet)*/
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
		printf("\nentrez le nom du 2nd sommet: ");                           /* IL FAUDRAIT DEMANDER NUM DE SOMMET OU NOM DE SOMMET => (pas besoin d'utiliser table de hachage si l'utilisisateur renseigne num sommet)*/
		scanf ("%99[^\n]s", ns2);	// 99 caractères, tout sauf \n
		scanf ("%*[^\n]");	// si buffer éxcédent on le vide
		getchar (); 	// on vide le \n du buffer
		/* recherche dans la table */
		hs2 = ht_search(ht, hs_getn, ns2);
	}

    /* gestion des correspondance */

	printf("\ngestion des correspondances sur les stations d'arrivée et de départ...\n");
    corresp_set_zero(g, ht, hs1);  // correspondance station de départ
    corresp_set_zero(g, ht, hs2);  // correspondance station de arrivée


	/* plus court chemin */
	printf("calcul du plus court chemin en cours...\n");
    printf("index s1: %d\nindex s2: %d\n", hs_geti(hs1), hs_geti(hs2));

    L_ARC chemin = pcc(g, hs_geti(hs1), hs_geti(hs2));
    double cout_total = cout_chemin(chemin);

    if (chemin) {    // Si pas de chemin possible entre les 2 sommets => annule l'affichage du pcc
        printf("\n\nPlus Court Chemin : Index %d (%s)  -->  Index %d (%s)\n", hs_geti(hs1), g.tab_s[hs_geti(hs1)].nom_noeud, hs_geti(hs2), g.tab_s[hs_geti(hs2)].nom_noeud);
        liste_print(arc_print, chemin);
        printf("\nCout Total : %lf\n", cout_total);
    }

	/* libération des structures */
	liste_del(NULL, chemin);	// ici, on ne libère pas les éléments de la
								// liste d'arcs, c'est fait dans libère graphe!
	ht_del(hs_del, ht);	// hs1 et hs2 se libèrent déjà ici
	libere_graphe(g);

	/* timer éxecution */
    printf("\nFIN TIMER : %fs\n", (double)(clock() - timer)/CLOCKS_PER_SEC);
    return EXIT_SUCCESS;
}
