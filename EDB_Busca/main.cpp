#include <iostream>
#include <fstream>
#include <stdio.h>
#include <sys/time.h>
#include "buscas.h"
#include "_aux.h"
#include <stdlib.h>
using namespace std;

const char* mensagemErro = "O programa precisa como parametro a opcao:\n - 'BSI' para Busca Sequencial Iterativa.\n- 'BSR' para Busca Sequencia Recursiva.\n  - 'BBI' para Busca Binária Iterativa.\n- 'BBR' para Busca Binária Recursiva.";
const char* nomeArquivo = "teste.txt";

int main(int argc, char const *argv[])
{
	int *contador;
	int sorteio;
	if (argc != 2)
	{
		cout<<mensagemErro<<endl;
		exit(-1);
	}

	bool(*Bbusca)(int[], int, int, int*);

	const char* escolha = argv[1];
	bool selecionouBusca = buscaSelecionada(escolha, &Bbusca);

	if (!selecionouBusca)
	{
		cout<<"Digite novamente para selecionar a busca!!!"<<mensagemErro<<endl;
		exit(-1);
	}

	int vet[TAM];
	lerArquivo(nomeArquivo, vet);
	quickSort(vet, 0, TAM - 1);
	int tamanhoVet = 50;
	double tr0, tr1, resultado, resultadoFinal = 0.0;
	struct timeval t0, t1;

	while(tamanhoVet <= 10000 ){

		for (int i = 0; i < 100; ++i)
		{
			gettimeofday (&t0, NULL);
			srand(time(NULL));
			sorteio = rand() % tamanhoVet;
			(*Bbusca)(vet, tamanhoVet, sorteio, contador);
			cout >> contador;
			gettimeofday (&t1, NULL);
			
			tr1 = (double)t1.tv_usec + ((double)t1.tv_sec * (1000000.0));
			tr0 = (double)t0.tv_usec + ((double)t0.tv_sec * (1000000.0));

			resultado = (tr1-tr0)/1000000;
			resultadoFinal += resultado;
		}
		resultadoFinal = resultadoFinal/100.0;
		char enderecoArquivo[] = "resDasBuscas.txt";
		FILE *arquivo;
		arquivo = fopen(enderecoArquivo, "a+");
		if (arquivo == NULL)
		{
			printf("Erro na abertura do Arquivo \n");
		}
		else{
			fprintf(arquivo, "%c%c%c\t %d\t %.10f\n", escolha[0],escolha[1],escolha[2] , tamanhoVet, resultadoFinal);
		}
		fclose(arquivo);
		
		tamanhoVet += 50;
	}

	return 0;
}
