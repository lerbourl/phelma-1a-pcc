/*
construit une table de hachage depuis un tableau d'elements
(structure de données abstraites)
*/

#ifndef _HASH_H_
#define _HASH_H_

#include <ctype.h>
#include <string.h>
#include "liste.h"
#include "callbacks.h"

struct ht_t;
typedef struct ht_t *H_TABLE;

unsigned int hachage(unsigned char* mot, int dim_tab_hach);

//INTERFACE ET ACCESEURS
H_TABLE ht_new(void);
int ht_del(action, void*);
int ht_print(action, void*);
H_TABLE ht_make_empty(int dim);
int ht_getd(H_TABLE);
void ht_fill(H_TABLE ht, void* element, char* label);
void* ht_search(H_TABLE ht, action_s e_string, char* label);
Liste find_l_hs(H_TABLE ht, char* nom_noeud);

#endif
