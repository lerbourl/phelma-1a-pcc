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

    printf("test 1 interface sommets pour hachage\n");
	H_SOMMET hs = hs_make(3, "Paris");
	hs_print(hs);
	hs_del(hs);

    getchar();

	printf("test 2 interface arcs\n");
	T_ARC arc = arc_make(3, 7.89);
	arc_print(arc);
	arc_del(arc);

    getchar();

	printf("test 3 liste d'arcs\n");
	T_ARC a1 = arc_make(3, 7.89);
	T_ARC a2 = arc_make(5, 9.42);
	L_ARC l = liste_new();
	l = ajout_tete(a1, l);
	l = ajout_tete(a2, l);
	liste_print(arc_print, l);
	liste_del(arc_del, l);

    getchar();

	printf("test 4 liste de hach-sommets\n");
	H_SOMMET hs1 = hs_make(3, "Paris");
	H_SOMMET hs2 = hs_make(5, "Lyon");
	l = liste_new();
	l = ajout_tete(hs1, l);
	l = ajout_tete(hs2, l);
	liste_print(hs_print, l);
	liste_del(hs_del, l);

    getchar();

	printf("test 5 Sommet\n");
	a1 = arc_make(3, 7.89);
	a2 = arc_make(5, 9.42);
	l = liste_new();
	l = ajout_tete(a1, l);
	l = ajout_tete(a2, l);
	T_SOMMET s;
	s.nom_noeud = strdup("Paris");
	s.x = 6.8;
	s.y = 7.3;
	s.nom_ligne = strdup("M1");
	s.voisins = l;
	affiche_sommet(&s);
	//libere_sommet(s);

    getchar();

	printf("test 6 graphe\n");
	GRAPHE g = cree_graphe(1);
	g.tab_s[0] = s;
	affiche_graphe(g);
	libere_graphe(g);

    getchar();

	printf("test 7 lecture fichier graphe\n");
    g = lecture_fichier(argv[1]);
	affiche_graphe(g);
	libere_graphe(g);

    getchar();

	printf("test 8 pcc\n");
	printf("test pcc graphe2 de 10 à 8...\n");
	g = lecture_fichier(argv[1]);
    L_ARC chemin = pcc(g, 10, 8);
	liste_print(arc_print, chemin);
	libere_graphe(g);
	liste_del(NULL, chemin);
    printf("vérifier dans le graphe, c'est juste ! ;)\n");

    getchar();

	printf("test 9 table de hachage\n");
	H_TABLE ht = ht_make_empty(10);
	printf("tble vide:\n");
	ht_print(hs_print, ht);
	hs1 = hs_make(1, "Paris");
	hs2 = hs_make(2, "Lyon");
	H_SOMMET hs3 = hs_make(3, "Grenoble");
	H_SOMMET hs4 = hs_make(4, "Paris");
	ht_fill(ht, hs1, hs_getn(hs1));
	ht_fill(ht, hs2, hs_getn(hs2));
	ht_fill(ht, hs3, hs_getn(hs3));
	ht_fill(ht, hs4, hs_getn(hs4));
	printf("table remplie:\n");
	ht_print(hs_print, ht);
	ht_del(hs_del, ht);

    getchar();

	printf("test 10 remplissage table de hachage depuis graphe\n");
	g = lecture_fichier(argv[1]);
	affiche_graphe(g);
	ht = ht_make_graphe(g);
	ht_print(hs_print, ht);
	ht_del(hs_del, ht);
	libere_graphe(g);

    getchar();

	printf("test 11 recherche d'un hs dans la table (avec graphe3!)\n");
    g = lecture_fichier(argv[1]);
	ht = ht_make_graphe(g);
	printf("\nrecherche GrenZZZble:");
	hs = ht_search(ht, hs_getn, "GrenZZZble");
	if (hs) hs_print(hs);
	printf("\nrecherche Grenoble:");
	hs = ht_search(ht, hs_getn, "Grenoble");
	if (hs) hs_print(hs);
	ht_del(hs_del, ht);
	libere_graphe(g);

    getchar();

    return EXIT_SUCCESS;
}
