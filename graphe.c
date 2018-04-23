#include "graphe.h"

void affiche_graphe(GRAPHE g){
    int n = g.nb_s;
    int i;
    for (i = 0; i < n; i++) affiche_sommet(&g.tab_s[i]);
}

GRAPHE cree_graphe(int n){
    GRAPHE g;
    g.nb_s = n;
    g.tab_s = malloc(n * sizeof(T_SOMMET));
    return g;
}

GRAPHE lecture_fichier(char* nom_fichier){
    GRAPHE g;
    T_SOMMET s;
    T_ARC a;
    int numero, ns, na, i, sdep, sarr;
    double lat, longi, cout;
    char line[128] ;
    char mot[512] ;
    FILE* f = NULL;
    f = fopen(nom_fichier, "r");
    if (!f) exit(2);
    fscanf(f, "%d %d", &ns, &na); //nombre de sommets et arcs
    g = cree_graphe(ns);
    fgets(mot,511,f); //?
    fgets(mot,511,f);//ligne "Sommets du graphe" ignorée
    s.voisins = creer_liste();
    for (i = 0; i < ns; i++){
        fscanf(f,"%d %lf %lf %s", &(numero), &(lat), &(longi), line);
        /* numéro contient alors l’entier, lat et longi la position, line le nom de la ligne */
        fgets(mot,511,f);
        if (mot[strlen(mot)-1]<32) mot[strlen(mot)-1]=0;
        /* mot contient le nom du sommet. */
        s.x = lat;
        s.y = longi;
        s.nom_ligne = strdup(line);
        s.nom_noeud = strdup(mot);
        g.tab_s[numero] = s;
    }
    fgets(mot,511,f);//ligne "arc du graphe : départ arrivée valeur " ignorée
    for (i = 0; i < na; i++){
        fscanf(f,"%d %d %lf", &(sdep), &(sarr), &(cout));
        /* numéro contient alors l’entier, lat et longi la position, line le nom de la ligne */
        fgets(mot,511,f); //?
        a.arrivee = sarr;
        a.cout = cout;
        g.tab_s[sdep].voisins = ajout_tete(a, g.tab_s[sdep].voisins);
    }
    libere_sommet(s);
    fclose(f);
    return g;
}

void libere_graphe(GRAPHE g){
    int i;
    for (i = 0; i < g.nb_s ; i++) libere_sommet(g.tab_s[i]);
    free(g.tab_s);
}
