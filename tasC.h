#ifndef _TASC
#define _TASC


void switch_val(int* tas, int* pcc_to_tas, int i, int j);

int p(int i);
int fg(int i);
int fd(int i);

void augmentetas(int* tas, double* tab_pcc, int* pcc_to_tas, int i);
void constructiontas(int* tas, double* tab_pcc, int* pcc_to_tas, int n);
void descendretas(int* tas, double* tab_pcc, int* pcc_to_tas, int i);
void suppressiontas(int* tas, double* tab_pcc, int* pcc_to_tas, int i);


#endif
