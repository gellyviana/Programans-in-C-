#ifndef AUX_H_INCLUDED
#define AUX_H_INCLUDED


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 10000

using namespace std;


bool buscaSeqInt (int[], int, int, int*);
bool buscaSeqRec (int[], int, int, int*);
bool buscaBinInt (int[], int, int, int*);
bool buscaBinRec (int[], int, int, int*);
bool buscaBinRecAux (int[], int, int, int, int*);

void lerArquivo(const char*, int[]);
bool buscaSelecionada(const char* op, bool(**busca)(int[], int, int, int*));



#endif //AUX_H_INCLUDED
