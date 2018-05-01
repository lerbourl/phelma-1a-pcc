#ifndef DEF_ERREURCTRL//évitons les inclusions infinies
#define DEF_ERREURCTRL

#include <stdio.h>
#include <stdlib.h>

// PROTOTYPES
void err_ctrl(void* tst, char* msg, char* file, const char* function, int line, char* data);

#endif
