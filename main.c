#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "arc.h"
#include "sommet.h"
#include "larc.h"
#include "graphe.h"
#include "chemin.h"
#include "hash.h"

int main(int argc, char* argv[]){
	/* A FAIRE :
	*/

	int timer = clock();
    //int n = 3;
    //T_ARC a1;
	//T_ARC a2;
    //L_ARC l = NULL;
    //GRAPHE g = cree_graphe(n);
    GRAPHE g1 = lecture_fichier(argv[1]);
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
    //affiche_graphe(g);
    affiche_graphe(g1);

    //test PCC
//    L_ARC chemin;
    //chemin = pcc(g1, 0, 6);
    //printf("\n\nPCC :\n");
    //affiche_larc(chemin);

    //libere_graphe(g);
    libere_graphe(g1);
    //libere_sommet(s);


    // timer éxecution
    printf("\nFIN TIMER : %fs\n", (double)(clock() - timer)/CLOCKS_PER_SEC);
    return EXIT_SUCCESS;
}
