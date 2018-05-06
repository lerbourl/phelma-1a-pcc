#include "hach.h"
#include <stdlib.h>
#include <stdio.h>

struct ht_t{
    Liste* table;
    int d_table;
};

unsigned int hachage(unsigned char* mot, int dim_tab_hach){
    int h = tolower(mot[0]), i = 1;
    while(tolower(mot[i])){
        h = (h*31 + tolower(mot[i])) % dim_tab_hach;
        i++;
    }
    return h;
}

H_TABLE ht_new(void){
    H_TABLE ht = malloc(1 * sizeof(*ht));
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
    ht->table = malloc(dim * sizeof(Liste));
    return ht;
}

int ht_getd(H_TABLE ht){
    return ht->d_table;
}

void ht_fill(H_TABLE ht, void* element, char* label){
    int h = hachage((unsigned char*)label, ht_getd(ht));
    ht->table[h] = ajout_tete(element, ht->table[h]);
}
