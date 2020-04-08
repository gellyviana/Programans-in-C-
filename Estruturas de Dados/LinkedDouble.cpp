#include <iostream>
#include <cstddef>

using namespace std;

typedef struct No{
	int dado;
	No* anterior;
	No* proximo;
}No;

typedef struct List{
	No* inicio;
	No* fim;
	int cont;
}List;

List* creation(List* lista){
	lista= new List;
	lista->inicio= nullptr;
	lista->fim= nullptr;
	lista->cont= 0;
	return lista;
}

void insertionEnd (List* lista, int valor){
	No* novo= new No;
	if(lista->inicio== nullptr){
		novo->dado= valor;
		novo->proximo= nullptr;
		novo->anterior= nullptr;
		lista->inicio= novo;
		lista->fim= novo;
		lista->cont+= 1;
	}
	else
	    {
		novo->dado= valor;
		novo->proximo= nullptr;
		novo->anterior= lista->fim;
		lista->fim->proximo= novo->anterior;
		lista->fim= novo;
		lista->cont+= 1;
	}
}

void printLinked(List* lista){
	No* existe= lista->inicio;
	while(existe->proximo!= nullptr){
		cout<<"Valor: "<<existe->dado<<endl;
		existe= existe->proximo;
	}
}

int main(){
	List* start= creation(start);
	insertionEnd(start, 10);
	insertionEnd(start, 20);
	insertionEnd(start, 30);
	insertionEnd(start, 40);
	printLinked(start);
	
	return 0;
}

