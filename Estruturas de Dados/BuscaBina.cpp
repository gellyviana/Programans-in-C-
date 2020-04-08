#include <iostream>
#include <cstdlib>

using namespace std;

int BuscaBin(int vet[], int esq, int dir, int chave)
{

	int meio = (dir+esq)/2;//Inteiro que recebe o indice correspondente ao meio do vetor.

	if(esq < dir){//Condicional de parada.

		if(vet[meio] == chave){//Caso em que meio é igual a chave, retorna índice.
			return meio;
		}

		else if(vet[meio] > chave){//Caso em que a chave esta esta na primeira parte do vetor.
			return BuscaBin(vet, esq, meio-1, chave);//Chama recursivamente a primeira parte do vetor.
		}

		else if(vet[meio] < chave){//Caso em que a chave esta na segunda metade do vetor.
			return BuscaBin(vet, meio+1, dir, chave);//Chama recursivamente a segunda parte do vetor.
		}

	}else{
		return -1;//Caso que não encontre a chave no vetor.
	}
}

int main (int argc, char **argv)
{
	int chave;
	chave = atoi(argv[1]);//Converte o vetor de Char em Inteiro.
	int vet[] = {1,2,3,4,5,6,7,8,9,10};
	int tam = 10;

	cout<<" INDICE: "<<BuscaBin(vet, 0, tam, chave)<<endl;//Chama a função.

	return 0;
}
