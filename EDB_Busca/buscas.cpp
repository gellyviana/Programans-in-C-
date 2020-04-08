#include <iostream>
#include <algorithm> 
#include "buscas.h"

using namespace std;

void particao(int vet[], int esq, int dir, int *a, int *b)
{
	int pivo = vet[esq];
	int k = esq, i = esq, j = dir;
	while(vet[k] < pivo)
	{
		if (vet[k] < pivo)
		{
			swap(vet[i], vet[k]);
			i++;
			k++;
		}
		if (vet[k] > pivo)
		{
			swap(vet[j],vet[k]);
			j--;
		}
		if (vet[k] == pivo)
		{
			k++;
		}
	}
	*a = i;
	*b = j;
}

void quickSort(int vet[], int esq, int dir)
{
	int a, b;
	if (esq < dir)
	{
		particao(vet, esq, dir, &a, &b);
		quickSort(vet, esq, a - 1);
		quickSort(vet, b + 1, dir);
	}
}


bool buscaSeqInt (int vet[], int tam, int chave, int *contador)
{
	for (int i = 0; i < tam; ++i)
	{
		(*contador)++;
		if (vet[i] == chave)
		{
			return true;
		}
	}
	return false;
}


bool buscaSeqRec (int vet[], int tam, int chave, int *contador)
{
	(*contador)++;
	if (tam < 0)
	{
		return false;
	}
	else if (vet[tam] == chave)
	{
		return true;
	}
	else
		return buscaSeqRec(vet, tam-1, chave, contador);
}


bool buscaBinInt (int vet[], int tam, int chave, int *contador)
{
	int meio, esq = 0, dir = tam;
	while (esq < dir)
	{
		(*contador)++;
		meio = (dir + esq)/2;
		if (vet[meio] == chave)
		{
			return true;
		}
		else if (vet[meio] < chave)
		{
			esq = meio + 1;
		}
		else
		{
			dir = meio - 1;
		}
	}
	return false;
}


bool buscaBinRec (int vet [], int dir, int chave, int *contador)
{
	return buscaBinRecAux(vet, 0, dir, chave, contador);
}

bool buscaBinRecAux (int vet [], int esq, int dir, int chave, int *contador)
{
	(*contador)++;
	int meio = (dir + esq)/2;
	if (esq < dir)
	{
		if (vet[meio] == chave)
		{
			return true;
		}
		else if (vet[meio] < chave)
		{
			return buscaBinRecAux(vet, meio + 1, dir, chave, contador);
		}
		else if (vet[meio] > chave)
		{
			return buscaBinRecAux(vet, esq, meio, chave, contador);
		}
	}else{
		return false;
	}	
}