#include <stdlib.h>
#include <stdio.h>
#include "arc.h"
#include "sommet.h"
#include "larc.h"
#include "graphe.h"

int main(int argc, char* argv[]){
    int n = 3;
    T_ARC a1, a2;
    L_ARC l = NULL;
    GRAPHE g = cree_graphe(n);
    //GRAPHE g1 = lecture_fichier(argv[1]);

    a1.arrivee = 7;
    a1.cout = 2.8;
    a2.arrivee = 3;
    a2.cout = 42.666;
    l = creer_liste();
    l = ajout_tete(a1, l);
    l = ajout_tete(a2, l);
    T_SOMMET s = {6, 2.4, 2.5, "rerB", "paris", l};
    g.tab_s[0] = s;
    s.num = 9;
    g.tab_s[1] = s;
    s.num = 12;
    g.tab_s[2] = s;

    affiche_graphe(g);//commentaire
    //affiche_graphe(g1);
    libere_graphe(g);
    //libere_graphe(g1);
    libere_sommet(s);

    return EXIT_SUCCESS;
}
