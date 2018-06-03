#include "hach.h"
#include <stdlib.h>
#include <stdio.h>

struct ht_t{
    Liste* table;
    int d_table;
};

/*renvoie l'indice de hachage*/
unsigned int hachage(unsigned char* mot_non_alloue, int dim_tab_hach){
    int i = 0;
    unsigned char* mot = (unsigned char*)strdup((char*) mot_non_alloue);
    while(mot[i] != 0){
        mot[i] = tolower(mot[i]);
        i++;
    }
    i = 0;
    int h = mot[0];
    while(mot[i]){
        h = (h*31 + mot[i]) % dim_tab_hach;
        i++;
    }
    if (h<0) printf("%s %d\n", mot, h);
    free(mot);
    return h;
}

H_TABLE ht_new(void){
    H_TABLE ht = calloc(1, sizeof(*ht));
    return ht;
}

int ht_del(action element_del, void* ht_ambigu){
    H_TABLE ht = (H_TABLE)ht_ambigu;
    int i;
    for (i = 0 ; i<ht->d_table ; i++) liste_del(element_del, ht->table[i]);
    free(ht->table);
    free(ht);
    return 0;
}

int ht_print(action element_print, void* ht_ambigu){
    H_TABLE ht = (H_TABLE)ht_ambigu;
    int i;
    printf("TABLE DE HACHAGE\n");
    for (i = 0 ; i<ht->d_table ; i++){
        printf("%d", i);
        liste_print(element_print, ht->table[i]);
        printf("\n");
    }
    return 0;
}

H_TABLE ht_make_empty(int dim){
    H_TABLE ht = ht_new();
    ht->d_table = dim;
    ht->table = calloc(dim, sizeof(Liste));
    return ht;
}

int ht_getd(H_TABLE ht){
    return ht->d_table;
}
/*  remplit une table de hachage avec un element indexé par un label */
void ht_fill(H_TABLE ht, void* element, char* label){
    int h = hachage((unsigned char*)label, ht_getd(ht));
    ht->table[h] = ajout_tete(element, ht->table[h]);
}

/*  retourne un élément de la table de hachage en log(n) en le recherchant par
    son label   */
void* ht_search(H_TABLE ht, action_s e_string, char* label){
    /* ATTENTION renvoie que la 1ere itération du label trouvé
    si station avec meme nom => en revoie qu'une */
    int h = hachage((unsigned char*)label, ht_getd(ht));
    Liste l = ht->table[h];
    while (!liste_vide(l)){
        if (strcasecmp(label, e_string(lgetval(l)))){
            l = lgetsuiv(l);
        }
        else{
            return lgetval(l);
        }
    }
    printf("\nélément non répertorié dans la table de hachage: %s\n", label);
    return NULL;
}

/*  retourne toute la liste à l'index du label*/
Liste find_l_hs(H_TABLE ht, char* nom_noeud) {
	unsigned int hash = hachage((unsigned char*)nom_noeud, ht_getd(ht));
	return ht->table[hash];
}
