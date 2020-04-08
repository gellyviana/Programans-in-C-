#ifndef funcoes_h
#define funcoes_h

#include <iostream>
#define N 10

using namespace std;

typedef struct Chave
{
	char * conteudo;
};

typedef struct Item
{
	Chave item;
};

typedef struct TabelaLista
{
	int tamanho;
	int qtdItens;
	Lista itens[N];
	Lista chaves[N];
};

bool inserir(TabelaLista, Chave, Item);
bool remover(TabelaLista, Chave);
Item buscar(TabelaLista, Chave);
TabelaLista redimensionar(Tabela, int);

#endif