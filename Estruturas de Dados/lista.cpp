#include <iostream>

using namespace std;

typedef struct No{
	int dado;
	No* proximo;
}No;

typedef struct Lista{
	int quantidade;
	No* inicio;
	No* fim;
}Lista;

No* Criar_no(int valor)
{	
	No* no = new No;
	no->dado = valor;
	no->proximo = NULL;
	return no;
}
Lista* Criarlista()
{
	Lista* lista;
	lista = new Lista;
	lista->inicio = NULL;
	lista->fim = NULL;
	lista->quantidade = 0;
	return lista;
}

bool inserirInicio(Lista* lista, int valor)
{
	No* nosinho = Criar_no(valor);

	if(lista == NULL)
	{
		return false;
	}
	if(lista->inicio == NULL)
	{
		lista->inicio = nosinho;
		lista->fim = nosinho;
		lista-> quantidade += 1;
		return true;
	}
	else
	{
		nosinho->proximo = lista->inicio;
		lista->inicio = nosinho;
		lista->quantidade +=1;
		return true; 
	}

}

bool inserirFim(Lista* lista, int valor)
{ 	
	No* nosinho = Criar_no(valor);

	if(lista == NULL)
	{
		return false;
	}

	if(lista->inicio == NULL)
	{
		lista->inicio = nosinho;
		lista->fim = nosinho;
		lista-> quantidade += 1;
		return true;
	}
	else{
		lista->fim->proximo = nosinho;
		lista->fim = nosinho;
		lista->quantidade += 1;
		return true;
	}			
}

bool removerInicio(Lista* lista)
{
	if(lista->inicio == NULL)
	{
		return false;
	}

	No* removido = lista->inicio;
	lista->inicio = removido->proximo;
	lista->quantidade -= 1;
	delete(removido);
	return true;
}

bool removerFim(Lista* lista)
{
	if(lista->fim == NULL)
	{
		return false;
	}
	
	No* penultimo = lista->inicio;
	No* ultimo = lista->inicio->proximo;
	while (penultimo->proximo != lista->fim)
	{
		penultimo = penultimo->proximo;
		ultimo = ultimo->proximo;
	}
	penultimo->proximo = NULL;
	lista->fim = penultimo;
	lista->quantidade -=1;
	delete(ultimo);
	return true;
}

bool buscaDado(Lista* lista, int procurado)
{
	for(No* no = lista->inicio; no != NULL; no = no->proximo)
	{
		if(no->dado == procurado)
		{
			return true;
		}
	}
	return false;
}

void printLista(Lista* lista)
{
	for(No* no = lista->inicio; no != NULL; no = no->proximo)
	{
		cout<<"Valor No "<<no->dado<<endl;
	}
}

int main (int argc, char** argv)
{
	Lista* lista = Criarlista();
	for(int i = 1; i <= 10; i++)
	{
		if(!inserirInicio(lista, i))
		{
			cout<<"Não inseriu!"<<endl;
		}	
	}
	printLista(lista);

	if(!removerInicio(lista))
	{
		cout<<"Não removeu no inicio!"<<endl;
	}
	printLista(lista);
	
	if(!removerFim(lista))
	{
		cout<<"Não removeu no fim!"<<endl;
	}
	printLista(lista);

	if(!buscaDado(lista, 5))
	{
		cout<<"Valor não encontrado!"<<endl;
	}

	return 0;
}
