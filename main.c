#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "arc.h"
#include "sommet.h"
#include "liste.h"
#include "graphe.h"
#include "chemin.h"
#include "hash.h"

int main(int argc, char* argv[]){

	int timer = clock();
/*

PARTIE DEDIEE AUX TESTS

*/
	/*
	//test interface sommets pour hachage
	H_SOMMET hs = hs_make(3, "Paris");
	hs_print(hs);
	hs_del(hs);
	*/

	/*
	//test interface arcs
	T_ARC arc = arc_make(3, 7.89);
	arc_print(arc);
	arc_del(arc);
	*/

	/*
	//test liste d'arcs
	T_ARC a1 = arc_make(3, 7.89);
	T_ARC a2 = arc_make(5, 9.42);
	L_ARC l = liste_new();
	l = ajout_tete(a1, l);
	l = ajout_tete(a2, l);
	liste_print(arc_print, l);
	liste_del(arc_del, l);
	*/

	/*
	//test liste de hach-sommets
	H_SOMMET hs1 = hs_make(3, "Paris");
	H_SOMMET hs2 = hs_make(5, "Lyon");
	L_ARC l = liste_new();
	l = ajout_tete(hs1, l);
	l = ajout_tete(hs2, l);
	liste_print(hs_print, l);
	liste_del(hs_del, l);
	*/

	/*
	//test Sommet
	//test graphe
	*/

	/*
	//test lecture fichier graphe
	GRAPHE g = lecture_fichier(argv[1]);
	affiche_graphe(g);
	libere_graphe(g);
	*/

	/*
	//test pcc
	GRAPHE g = lecture_fichier(argv[1]);
	L_ARC chemin = pcc(g, 10, 8);
	liste_print(arc_print, chemin);
	libere_graphe(g);
	*/

	
    //int n = 3;
    //T_ARC a1;
	//T_ARC a2;
    //L_ARC l = NULL;
    //GRAPHE g = cree_graphe(n);
    //GRAPHE g1 = lecture_fichier(argv[1]);
/*
    a1.arrivee = 7;
    a1.cout = 2.8;
    a2.arrivee = 3;
    a2.cout = 42.666;

    l = creer_liste();
    l = ajout_tete(&a1, l);
    l = ajout_tete(&a2, l);
	T_SOMMET s = {"paris", 2.4, 2.5, "rerB", l};
	s.nom_noeud = strdup("pari");
	s.nom_ligne = strdup("M1");
	g.tab_s[0] = s;
    s.nom_noeud = strdup("bla");
	s.nom_ligne = strdup("M1");
    g.tab_s[1] = s;
    s.nom_noeud = strdup("john");
	s.nom_ligne = strdup("M1");
    g.tab_s[2] = s;
*/

	//H_TABLE table_de_hachage = tableh_constr_graphe(g1);

	//printf("%d", hachage((unsigned char*)g1.tab_s[5].nom_noeud, 10*g1.nb_s));

	//affiche_graphe(g);
    //affiche_graphe(g1);

    //test PCC
//    L_ARC chemin;
    //chemin = pcc(g1, 0, 6);
    //printf("\n\nPCC :\n");
    //affiche_larc(chemin);

    //libere_graphe(g);
    //libere_graphe(g1);
    //libere_sommet(s);
/*

MAIN EFFECTIF

*/
    // timer éxecution
    printf("\nFIN TIMER : %fs\n", (double)(clock() - timer)/CLOCKS_PER_SEC);
    return EXIT_SUCCESS;
}
