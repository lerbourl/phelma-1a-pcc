#include "hash.h"
#include <stdlib.h>
#include <stdio.h>

unsigned int hachage(unsigned char* mot, int dim_tab_hach){
    int h = tolower(mot[0]), i = 1;
    while(tolower(mot[i])){
        h = (h*31 + tolower(mot[i])) % dim_tab_hach;
        i++;
    }
    return h;
}

H_TABLE tableh_constr_graphe(GRAPHE g){
    H_TABLE ht;
    H_SOMMET hs;
    ht.d_table = 10 * g.nb_s;
    ht.table = malloc(ht.d_table * sizeof(Liste));
    int i, h;
    for (i = 0 ; i<g.nb_s ; i++){
        //hs->index = i;
        //hs->nom_noeud = strdup(g.tab_s[i].nom_noeud);
        //h = hachage((unsigned char*)hs->nom_noeud, ht.d_table);

    }
    return ht;
}
void tableh_affiche(action f, H_TABLE th){

}
void tableh_libere(H_TABLE th){

}
