#ifndef _ERREURCTRL_H_//évitons les inclusions infinies
#define _ERREURCTRL_H_

#include <stdio.h>
#include <stdlib.h>

// PROTOTYPES
void err_ctrl(void* tst, char* msg, char* file, const char* function, int line, char* data);

#endif
