#include "graphe.h"

void affiche_graphe(GRAPHE g){
    int n = g.nb_s;
    int i;
    for (i = 0; i < n; i++){
        printf("\n  SOMMET %d",i);
        affiche_sommet(&g.tab_s[i]);
    }
}

GRAPHE cree_graphe(int n){
    GRAPHE g;
    g.nb_s = n;
    g.tab_s = malloc(n * sizeof(T_SOMMET));
    return g;
}

GRAPHE lecture_fichier(char* nom_fichier){
    GRAPHE g; // le graphe destiné à être renvoyé
    T_ARC a; // c'est un buffer qui remplira les voisins des sommets
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
    for (i = 0; i < ns; i++){
        fscanf(f,"%d %lf %lf %s", &(numero), &(lat), &(longi), line);
        fseek(f, 1, SEEK_CUR); // on ne veut pas récuperer le séparateur
        /* numéro contient alors l’entier, lat et longi la position, line le nom de la ligne */
        fgets(mot,511,f);
        if (mot[strlen(mot)-1]<32) mot[strlen(mot)-1]=0;
        /* mot contient le nom du sommet. */
        g.tab_s[numero].x = lat;
        g.tab_s[numero].y = longi;
        g.tab_s[numero].nom_ligne = strdup(line);
        g.tab_s[numero].nom_noeud = strdup(mot);
        g.tab_s[numero].voisins = creer_liste();
    }
    fgets(mot,511,f);//ligne "arc du graphe : départ arrivée valeur " ignorée
    for (i = 0; i < na; i++){
        fscanf(f,"%d %d %lf", &(sdep), &(sarr), &(cout));
        /* numéro contient alors l’entier, lat et longi la position, line le nom de la ligne */
        fgets(mot,511,f);
        a.arrivee = sarr;
        a.cout = cout;
        g.tab_s[sdep].voisins = ajout_tete(a, g.tab_s[sdep].voisins);
    }
    fclose(f);
    return g;
}

void libere_graphe(GRAPHE g){
    int i;
    for (i = 0; i < g.nb_s ; i++) libere_sommet(g.tab_s[i]);
    free(g.tab_s);
}
