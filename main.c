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
/*

PARTIE DEDIEE AUX TESTS

*/
	/*
	//test 1 interface sommets pour hachage
	H_SOMMET hs = hs_make(3, "Paris");
	hs_print(hs);
	hs_del(hs);
	*/

	/*
	//test 2 interface arcs
	T_ARC arc = arc_make(3, 7.89);
	arc_print(arc);
	arc_del(arc);
	*/

	/*
	//test 3 liste d'arcs
	T_ARC a1 = arc_make(3, 7.89);
	T_ARC a2 = arc_make(5, 9.42);
	L_ARC l = liste_new();
	l = ajout_tete(a1, l);
	l = ajout_tete(a2, l);
	liste_print(arc_print, l);
	liste_del(arc_del, l);
	*/

	/*
	//test 4 liste de hach-sommets
	H_SOMMET hs1 = hs_make(3, "Paris");
	H_SOMMET hs2 = hs_make(5, "Lyon");
	L_ARC l = liste_new();
	l = ajout_tete(hs1, l);
	l = ajout_tete(hs2, l);
	liste_print(hs_print, l);
	liste_del(hs_del, l);
	*/

	/*
	//test 5 Sommet
	T_ARC a1 = arc_make(3, 7.89);
	T_ARC a2 = arc_make(5, 9.42);
	L_ARC l = liste_new();
	l = ajout_tete(a1, l);
	l = ajout_tete(a2, l);
	T_SOMMET s;
	s.nom_noeud = strdup("Paris");
	s.x = 6.8;
	s.y = 7.3;
	s.nom_ligne = strdup("M1");
	s.voisins = l;
	//affiche_sommet(&s);
	//libere_sommet(s);

	//test 6 graphe
	GRAPHE g = cree_graphe(1);
	g.tab_s[0] = s;
	affiche_graphe(g);
	libere_graphe(g);
	*/

	/*
	//test 7 lecture fichier graphe
	GRAPHE g = lecture_fichier(argv[1]);
	affiche_graphe(g);
	libere_graphe(g);
	*/

	/*
	//test 8 pcc
	GRAPHE g = lecture_fichier(argv[1]);
	L_ARC chemin = pcc(g, 10, 8);
	liste_print(arc_print, chemin);
	libere_graphe(g);
	liste_del(arc_del, chemin);
	*/

	/*
	//test 9 table de hachage
	H_TABLE ht = ht_make_empty(10);
	ht_print(hs_print, ht);
	H_SOMMET hs1 = hs_make(1, "Paris");
	H_SOMMET hs2 = hs_make(2, "Lyon");
	H_SOMMET hs3 = hs_make(3, "Grenoble");
	H_SOMMET hs4 = hs_make(4, "Paris");
	ht_fill(ht, hs1, hs_getn(hs1));
	ht_fill(ht, hs2, hs_getn(hs2));
	ht_fill(ht, hs3, hs_getn(hs3));
	ht_fill(ht, hs4, hs_getn(hs4));
	ht_print(hs_print, ht);
	ht_del(hs_del, ht);
	*/

	/*
	//test 10 remplissage table de hachage depuis graphe
	GRAPHE g = lecture_fichier(argv[1]);
	//affiche_graphe(g);
	H_TABLE ht = ht_make_graphe(g);
	ht_print(hs_print, ht);
	ht_del(hs_del, ht);
	libere_graphe(g);
	*/

	/*
	//test 11 recherche d'un hs dans la table
	GRAPHE g = lecture_fichier(argv[1]);
	H_TABLE ht = ht_make_graphe(g);
	printf("\nrecherche:");
	H_SOMMET hs = ht_search(ht, hs_getn, "GrenZZZble");
	if (hs) hs_print(hs);
	ht_del(hs_del, ht);
	libere_graphe(g);
	*/

/*
MAIN EFFECTIF
*/
	char* nom_fichier = argv[1];
    printf("\nlecture du fichier %s et création du graphe ...", nom_fichier);
	GRAPHE g = lecture_fichier(nom_fichier);
	//affiche_graphe(g);
    printf("\ncréation de la table de hachage ...");
	H_TABLE ht = ht_make_graphe(g);
	
    printf("\nrecherche du plus court chemin entre deux sommets du graphe");
	char ns1[100];
	char ns2[100];
	/* réupération de la chaine de manière sécurisée */
	printf("\nentrez le nom du 1er sommet:");                           /* IL FAUDRAIT DEMANDER NUM DE SOMMET OU NOM DE SOMMET => (pas besoin d'utiliser table de hachage si l'utilisisateur renseigne num sommet)*/
	scanf ("%99[^\n]s", ns1);	// 99 caractères, tout sauf \n
	scanf ("%*[^\n]");	// si buffer éxcédent on le vide
	getchar (); 	// on vide le \n du buffer
	/* recherche dans la table */
	H_SOMMET hs1 = ht_search(ht, hs_getn, ns1);
	err_ctrl(hs1, "sommet non trouvé", __FILE__, __func__, __LINE__, "");
	/* idem sommet 2 */
	printf("\nentrez le nom du 2nd sommet:");
	scanf ("%99[^\n]s", ns2);
	scanf ("%*[^\n]");
	getchar ();
	H_SOMMET hs2 = ht_search(ht, hs_getn, ns2);
	err_ctrl(hs2, "sommet non trouvé", __FILE__, __func__, __LINE__, "");

	/* plus court chemin */
	printf("\ncalcul du plus court chemin en cours...");
    printf("\nindex s1: %d\nindex s2: %d\n", hs_geti(hs1), hs_geti(hs2));
    
    L_ARC chemin = pcc(g, hs_geti(hs1), hs_geti(hs2));
    double cout_total = cout_chemin(chemin);
    
    if (chemin) {    // Si pas de chemin possible entre les 2 sommets => annule l'affichage du pcc
        printf("\n\nPlus Court Chemin : Index %d (%s)  -->  Index %d (%s)\n", hs_geti(hs1), hs_getn(hs1), hs_geti(hs2), hs_getn(hs2));
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
