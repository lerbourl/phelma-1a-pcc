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

	char* nom_fichier = argv[1];
    printf("\nLecture du fichier %s et création du graphe ...\n", nom_fichier);

	int timer_graphe = clock();
	GRAPHE g = lecture_fichier(nom_fichier);
	printf("Temps remplissage graphe: %fs\n", (double)(clock() - timer_graphe)/CLOCKS_PER_SEC);

	int timer_hash = clock();
	printf("\nCréation de la table de hachage ...\n");
	H_TABLE ht = ht_make_graphe(g);
	printf("Temps remplissage table de hachage: %fs\n", (double)(clock() - timer_hash)/CLOCKS_PER_SEC);

	H_SOMMET hs1;
	H_SOMMET hs2;
	char ns1[100] = " ";
	char ns2[100] = " ";
	int i1, i2;
	int timer_pcc;
	int depart, arrivee;
	double cout_total;
	L_ARC chemin;
	int choix2;

	do{
		printf("\n//nouvelle recherche//\n");
		int choix1 = -1;
		do{
			printf("\nMode de choix des sommmets:\n0 index\n1 nom\n");
			scanf("%1d", &choix1); //1 caractère
			getchar(); 	// on vide le \n du buffer
		}while(!(choix1 == 0 || choix1 == 1));

		hs1 = NULL;
		hs2 = NULL;
		if (choix1){ // demande par le nom
			printf("\nNote: la casse n'importe pas, sauf pour les lettres avec accent!");
			while (!hs1){
				/* réupération de la chaine de manière sécurisée */
				printf("\nEntrez le nom du sommet de départ : ");                           /* IL FAUDRAIT DEMANDER NUM DE SOMMET OU NOM DE SOMMET => (pas besoin d'utiliser table de hachage si l'utilisisateur renseigne num sommet)*/
				scanf("%99[^\n]s", ns1);	// 99 caractères, tout sauf \n
				scanf("%*[^\n]");	// si buffer éxcédent on le vide
				getchar (); 	// on vide le \n du buffer
				/* recherche dans la table */
				hs1 = ht_search(ht, hs_getn, ns1);
			}
			/* idem sommet 2 */
			while (!hs2){
				/* réupération de la chaine de manière sécurisée */
				printf("\nEntrez le nom du sommet d'arrivée : ");                           /* IL FAUDRAIT DEMANDER NUM DE SOMMET OU NOM DE SOMMET => (pas besoin d'utiliser table de hachage si l'utilisisateur renseigne num sommet)*/
				scanf("%99[^\n]s", ns2);	// 99 caractères, tout sauf \n
				scanf("%*[^\n]");	// si buffer éxcédent on le vide
				getchar(); 	// on vide le \n du buffer
				/* recherche dans la table */
				hs2 = ht_search(ht, hs_getn, ns2);
			}
		}
		else{ // demande par l'index
			i1 = -1;
			i2 = -1;
			do{
				printf("\nEntrez l'indice du sommet de depart (0 <= id <= %d): ", g.nb_s - 1);
				scanf("%16d", &i1);
				scanf("%*[^\n]");
				getchar(); 	// on vide le \n du buffer
			}while(i1>g.nb_s || i1 < 0);
			do{
				printf("\nEntrez l'indice du sommet d'arrivee (0 <= ia <= %d): ", g.nb_s - 1);
				scanf("%16d", &i2);
				scanf("%*[^\n]");
				getchar(); 	// on vide le \n du buffer
			}while(i2>g.nb_s || i2 < 0);
			hs1 = ht_search(ht, hs_getn, g.tab_s[i1].nom_noeud);
			hs2 = ht_search(ht, hs_getn, g.tab_s[i2].nom_noeud);
		}

	    /* gestion des correspondances */

		printf("\nGestion des correspondances sur les stations d'arrivée et de départ...");
	    corresp_set_zero(g, ht, hs1);  // correspondance station de départ
	    corresp_set_zero(g, ht, hs2);  // correspondance station de arrivée

		/* plus court chemin */
		printf("\nCalcul du plus court chemin en cours...\n");

		timer_pcc = clock();
		chemin = pcc(g, hs_geti(hs1), hs_geti(hs2));
		printf("Temps de calcul du pcc: %fs\n", (double)(clock() - timer_pcc)/CLOCKS_PER_SEC);

		if (chemin){
		    printf("\n///\n///  Plus court chemin entre %s et %s:\n///\n", g.tab_s[hs_geti(hs1)].nom_noeud, g.tab_s[hs_geti(hs2)].nom_noeud);
			/*gestion des correspondances*/
			depart = hs_geti(hs1);
			arrivee = hs_geti(hs2);
			chemin = chemin_supr_zero(chemin, &depart, &arrivee);
			/*affichage de l'itinéraire*/
			printf("\nDépart: %s, ligne %s\n", g.tab_s[depart].nom_noeud, g.tab_s[depart].nom_ligne);
			printf("Arrivee: %s, ligne %s\n", g.tab_s[arrivee].nom_noeud, g.tab_s[arrivee].nom_ligne);
			printf("\n ENTREE pour continuer");
			getchar();
			affiche_chemin(chemin, g);
			/*cout du chemin*/
			cout_total = cout_chemin(chemin);
			printf("\nCout Total : %lf\n", cout_total);
			/* on remet les correspondances à 360 */
			corresp_set_360(g, ht, hs1);  // correspondance station de départ
		    corresp_set_360(g, ht, hs2);  // correspondance station de arrivée
		}
		do{
			printf("\nChercher encore:\n0 non\n1 oui\n");
			scanf("%1d", &choix2); //1 caractère
			scanf("%*[^\n]");
			getchar(); 	// on vide le \n du buffer
		}while(!(choix2 == 0 || choix2 == 1));
		liste_del(NULL, chemin); // ici, on ne libère pas les éléments de la
								 // liste d'arcs, c'est fait dans libère graphe!
	}while(choix2);

	/* libération des structures */
	ht_del(hs_del, ht);	// hs1 et hs2 se libèrent déjà ici
	libere_graphe(g);

    return EXIT_SUCCESS;
}
