#include "erreurctrl.h"

/*
Si le pointeur recuperé est NULL, il y a un soucis et on exit 2.
Affichage de l'erreur.
    Exemple d'utilisation:
err_ctrl(p, "erreur malloc!", __FILE__, __func__, __LINE__, "");
*/
void err_ctrl(void* tst, char* msg, char* file, const char* function, int line, char* data){
    if (tst == NULL){
        printf("\n//////////\n//ERREUR//\n//////////\nfichier: %s\nfonction: %s\nligne: %d\n%s%s\n", file, function, line, msg, data);
        exit(2);
    }
}
