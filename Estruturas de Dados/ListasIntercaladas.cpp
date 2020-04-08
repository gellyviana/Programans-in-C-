#include <iostream>

using namespace std;

typedef struct No
{
	int conteudo;
	No* proximo;
	No* anterior;
}No;

typedef struct Lista
{
	No* cabeca;
	No* cauda; 
	int tamanho;
}Lista;

Lista* Criar(Lista* lista)
{
	lista = new Lista;
	lista->cabeca= NULL;
	lista->cauda= NULL;
	lista->tamanho= 0;
	return lista;
}

void Inserir(Lista* lista, int valor)
{
	No* novo= new No;
	novo->conteudo= valor;
	if(lista->cabeca->proximo== lista->cauda)
	{
		novo->proximo= lista->cabeca->proximo;
		novo->anterior= lista->cabeca;
		lista->cabeca->proximo= novo;
		lista->cabeca= novo;
	}
		else if (lista->cabeca->proximo!=lista->cabeca)
		{
			lista->cauda->anterior->proximo= novo;
			novo->anterior= lista->cauda->anterior;
			lista->cauda->anterior= novo;
			novo->proximo= lista->cauda;
		}
	lista->tamanho++;
}

void Intercala(Lista* lista1, Lista* lista2)
{
	Lista* inter;
	No* tmp1= lista1->cabeca->proximo;
	No* tmp2= lista2->cabeca->proximo;
	while(1)
	{
		if(tmp1->conteudo > tmp2->conteudo)
		{
			for(; tmp1!=lista1->cauda; tmp1=tmp1->proximo)
			{	
				Inserir(inter, tmp2->conteudo);
			}
			break;
		}
		if (tmp2->conteudo > tmp1->conteudo)
		{
			for (; tmp2!=lista2->cauda; tmp2=tmp2->proximo)
			{
				Inserir(inter, tmp1->conteudo);
			}
			break;	
		}
		Inserir(inter, tmp1->conteudo);
		tmp1=tmp1->proximo;
		Inserir(inter, tmp2->conteudo);
		tmp2=tmp2->proximo;
	}
}

void Ordenar(Lista* lista)
{
	int valor;
	No* maior= lista->cabeca->proximo;
	No* menor= lista->cabeca->proximo->proximo;
	No* kevin= lista->cabeca;
	for (int i = lista->tamanho; i >=1; --i)
	{
		while(maior!=lista->cauda)
		{
			if(maior->conteudo > menor->conteudo)
			{
				valor= maior->conteudo;
				kevin= maior->proximo;
				menor->anterior= maior->anterior;

				maior->conteudo= valor;
				maior->proximo= menor->proximo;
				maior->anterior= menor;
				menor->proximo= maior;
				menor= maior;
			}
			maior=maior->proximo;
		}
	}
}

void Imprime(Lista* lista)
{
	No* aux= lista->cabeca->proximo;
	while(aux!=lista->cauda)
	{
		cout<<"Conteudo: "<<aux->conteudo<<endl;
		aux=aux->proximo;
	}
}

int main()
{
	Lista* lista= Criar(lista);
	Inserir(lista, 10);
	Inserir(lista, 0);
	Inserir(lista, 1);
	Inserir(lista, 6);
	Inserir(lista, 2);
	Imprime(lista);
	return 0;
}













