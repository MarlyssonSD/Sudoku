#ifndef DIFICULDADE_H
#define DIFICULDADE_H

#include <time.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h> //para o memset
#define TAMTAB 9

int geraNumRandom()
{
    return rand() % 9 + 1;
}

#endif