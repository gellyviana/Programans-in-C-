#include <iostream>
#define TAM 50
using namespace std;

typedef struct Lista
{
	int elemento[TAM];
	int inicio;
	int fim; 
	int tamanho;
}Lista;
/* Funcao que cria uma lista*/
void criarLista (Lista &lista)
{
	lista.inicio=0;
	lista.fim=0;
	lista.tamanho=0;
}
/*Funcao que inseri no fim do array.*/
void inserirFim (Lista &lista, int numero)
{
	if(lista.tamanho==TAM)
	{
		cout<<"Lista cheia"<<endl;
	}
		else
		{
            lista.fim= lista.fim+1;
			lista.elemento[lista.fim]=numero;
			lista.tamanho+=1;
	    }
}
/*Funcao que inseri no inicio do array*/
void inserirInicio(Lista &lista, int numero)
{
	if(lista.tamanho==TAM)
	{
		cout<<"Lista esta cheia"<<endl;
	}
	int aux=lista.fim;
	while(lista.inicio<=aux)
	{
		lista.elemento[aux+1]=lista.elemento[aux];
		aux--;
	}
	lista.elemento[lista.inicio+1]=numero;
	lista.fim+=1;
	lista.tamanho+=1;
}
/* Funcao que inseri pelo indice passado como parametro*/
void inserir (Lista &lista, int numero, int indice)
{
	if(lista.tamanho==TAM)
	{
		cout<<"Lista esta cheia"<<endl;
	}
	int aux = lista.fim;
	while(aux >= indice)
	{
		lista.elemento[aux+1]=lista.elemento[aux];
		aux--;
	}
	lista.elemento[indice]=numero;
	lista.fim+=1;
	lista.tamanho+=1;
}
/* Funcao que remove o elemento pelo indice */
int removerIndice(Lista &lista, int indice)
{
	if(lista.tamanho==1)
	{
		cout<<"Lista esta vazia"<<endl;
	}
	int removido, aux = indice;
	while(lista.fim >= aux)
	{
		lista.elemento[aux] = lista.elemento[aux+1];
		removido = lista.elemento[indice];
		aux++;
	}
	lista.fim--;
	lista.tamanho--;
	return removido;
}
/*Funcao que remove no inicio do array*/
void removerInicio(Lista &lista)
{
	if(lista.tamanho==1)
	{
		cout<<"Lista esta vazia"<<endl;
	}
	int aux= lista.inicio;
	while(lista.fim >= aux)
	{
		lista.elemento[aux]=lista.elemento[aux+1];
		aux++;
	}
	lista.fim--;
	lista.tamanho--;
}
/* Funcao que remove no fim do array*/
void removerFim(Lista &lista)
{
	if(lista.tamanho==1)
	{
		cout<<"Lista esta vazia"<<endl;
	}
	lista.elemento[lista.fim]= lista.elemento[lista.fim-1];
	lista.fim--;
	lista.tamanho--;
}
/*Funcao que retorna verdadeiro caso a busca pelo elemento tenha exito*/
bool buscaElemento(Lista &lista, int numero)
{
	while(lista.inicio+1 <= lista.fim)
	{
		if(lista.elemento[lista.inicio] == numero)
		{
			return true;
		}
		lista.inicio++;
	}
	return false;
}
/* FUncao que imprime o conteudo do array*/
void imprimirLista(Lista &lista)
{
	int print=1;
	while(print<=lista.tamanho)
	{
		cout<<"Elemento: "<<lista.elemento[print]<<endl;
		print++;
	}
}

int main()
{
	Lista lista;
	criarLista(lista);
	inserirFim(lista, 10);
	inserirFim(lista, 20);
	inserirFim(lista, 30);
	inserirFim(lista, 40);
	inserirInicio(lista, 50);
	inserirInicio(lista, 60);
	inserir(lista, 70, 5);
	inserir(lista, 80, 6);
	cout<<"Valor removido: "<<removerIndice(lista, 5)<<endl;
	removerInicio(lista);
	removerFim(lista);
	cout<<"Resultado da busca: "<<buscaElemento(lista, 90)<<endl;
	imprimirLista(lista);
	return 0;
}
