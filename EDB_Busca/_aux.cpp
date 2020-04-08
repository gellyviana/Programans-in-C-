#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "_aux.h"

#define TAM 10000

using namespace std;

void lerArquivo(const char* nomeArquivo, int vet[])
{
	FILE *f = fopen(nomeArquivo, "r");
    
    for( int i = 0; i < TAM; i++){
        fscanf(f, "%d;", &vet[i]);
    }
    
    fclose(f);
}

bool buscaSelecionada(const char* op, bool(**Bbusca)(int[], int, int, int*))
{
	if (strcmp("BSI", op) == 0)
	{
		cout<<"buscaSeqInt"<<endl;
		*Bbusca = &buscaSeqInt;
		return true;
	}
	else if (strcmp("BSR", op ) == 0)
	{
		cout<<"buscaSeqRec"<<endl;
		*Bbusca = &buscaSeqRec;
		return true;
	}
	else if (strcmp("BBI", op) == 0)
	{
		cout<<"buscaBinInt"<<endl;
		*Bbusca = &buscaBinInt;
		return true;
	}
	else if (strcmp("BBR", op) == 0)
	{
		cout<<"buscaBinRec"<<endl;
		*Bbusca = &buscaBinRec;
		return true;
	}
	else{
		return false;
	}
}
