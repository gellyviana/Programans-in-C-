/*
 *
 *   Este é o único arquivo que você irá modificar durante toda esta atividade.
 *
 */


#include <stdlib.h>
#include <iostream>
#include "Lista.h"

#define VALOR_QUALQUER -10000

No CriarNo(int);
bool DestruirNo(No);

/**
    Função que aloca memória para uma instância da estrutura Lista e inicializa os seus campos.
 */
Lista LIS_Criar()
{
    Lista lista = (Lista)malloc(sizeof(tpLista));
    if( lista == NULL )
    {
        return NULL;
    }
    
    lista->cabeca = CriarNo(VALOR_QUALQUER);
    if( lista->cabeca == NULL )
    {
        return NULL;
    }
    lista->cauda = CriarNo(VALOR_QUALQUER);
    if( lista->cauda == NULL )
    {
	return NULL;
    }
    lista->cabeca->proximo  = lista->cauda;
    lista->cabeca->anterior = NULL;
    lista->cauda->anterior = lista->cabeca;
    lista->cauda->proximo = NULL;
    lista->tamanho=0;	
    
    return lista;
}

/*
    Função que busca a posição de uma determinada chave numa lista.
    @param lista - lista em que será feita a busca
    @param chave - chave a ser buscada na lista
    @return índice que indica a posição do elemento cujo valor é igual a chave. Retorna -1 caso a chave não seja encontrada na lista.
 */
int LIS_Buscar(Lista lista, int chave)
{
    No tmp = lista->cabeca->proximo;
    int indice = 1;	
    while(tmp->proximo != NULL)
    {
       if(tmp->valor == chave)
       {   
          return indice;
       }
	indice += 1;
	tmp = tmp->proximo;
    }         
    return -1;
}

/*
 Função que retorna o valor de um elemento na lista que está na posição indicada pelo parâmetro i.
 @param lista - lista em que será feita a busca
 @param i - indica a posição do elemento cujo valor se deseja retornar
 @return valor do elemento na i-esima posição da lista. Retorna -1 se não existir elemento na i-esima posição
 */
int LIS_PegarValor(Lista lista, int i)
{
	if(lista->cabeca->proximo == lista->cauda || i > lista->tamanho || i <= 0)
	{
        return -1;
     } 
     No tmp = lista->cabeca->proximo;
     
     for(int j=1; tmp->proximo != lista->cauda && j< i ; tmp=tmp->proximo, j++);
	 return tmp->valor;
     
}

/*
 Função que insere um valor no início da lista. Após a execução desta função, o elemento inserido será o primeiro elemento da lista.
 @param lista - lista em que será feita a inserção
 @param v - valor a ser inserido na lista
 @return true se inseriu com sucesso, false caso contrário
 */
bool LIS_InserirInicio(Lista lista, int v)
{
    No no = CriarNo(v);
    if( no == NULL )
    {
        return false;
    }
    
    no->proximo = lista->cabeca->proximo;
    no->anterior = lista->cabeca;
    lista->cabeca->proximo = no;
    no->proximo->anterior = no;
    lista->tamanho++;

    return true;
}

/*
 Função que insere um valor no fim da lista. Após a execução desta função, o elemento inserido será o último elemento da lista.
 @param lista - lista em que será feita a inserção
 @param v - valor a ser inserido na lista
 @return true se inseriu com sucesso, false caso contrário
 */
bool LIS_InserirFim(Lista lista, int v)
{
   No no = CriarNo(v);
    if( no == NULL)
    {
	return false;
    }
    lista->cauda->anterior->proximo = no;
    no->anterior =lista->cauda->anterior;
    lista->cauda->anterior = no;
    no->proximo=lista->cauda;
    
    lista->tamanho++;
    return true;
}

/*
 Função que insere um valor numa determinada posição da lista. Após a execução desta função, o elemento inserido será o i-esimo elemento da lista.
 @param lista - lista em que será feita a inserção
 @param v - valor a ser inserido na lista
 @param i - indica a posição que o novo elemento ocupará após a inserção
 @return true se inseriu com sucesso, false caso contrário
 */
bool LIS_Inserir(Lista lista, int v, int i)
{
	if(i<=0 || i> lista->tamanho +1)
	{
		return false;
	}
	No tmp = lista->cabeca->proximo;
	for(int j=1; tmp->proximo != NULL && j<i; tmp=tmp->proximo, j++);
	No novo = CriarNo(v);
	tmp->anterior->proximo = novo;
	novo->anterior = tmp->anterior;
	tmp->anterior = novo;
	novo->proximo = tmp;
	lista->tamanho ++;
	return true;
	
}

/*
 Função que remove um valor no início da lista.
 @param lista - lista em que será feita a remoção
 @return retorna o valor do elemento removido. Retorna -1 caso a lista esteja vazia.
 */
int LIS_RemoverInicio(Lista lista)
{
    int resultado;
    No excluido = lista->cabeca->proximo;
    if(excluido == lista->cauda)
    {
        return -1;
    }
    resultado = excluido->valor;
    lista->cabeca->proximo->proximo->anterior = lista->cabeca;
    lista->cabeca->proximo = excluido->proximo;
    lista->tamanho -= 1;
    DestruirNo(excluido);
        return resultado;
}

/*
 Função que remove um valor no fim da lista.
 @param lista - lista em que será feita a remoção
 @return retorna o valor do elemento removido. Retorna -1 caso a lista esteja vazia.
 */
int LIS_RemoverFim(Lista lista)
{
	int removido;
	if(lista->cabeca->proximo == lista->cauda)
	{ 
		return -1;
	}
	
	No excluso = lista->cauda->anterior;
	removido = excluso->valor;
	excluso->anterior->proximo = lista->cauda;
	lista->cauda->anterior = excluso->anterior;
	lista->tamanho --;
	DestruirNo(excluso);
	
	return removido;
}

/*
 Função que remove um valor numa determinada posição da lista.
 @param lista - lista em que será feita a remoção
 @param indice - indica a posição na lista do elemento que se deseja remover
 @return retorna o valor do elemento removido. Retorna -1 caso a lista esteja vazia, ou caso o índice não aponte para uma posição válida da lista.
 */
int LIS_Remover(Lista lista, int indice)
{
	int removido;
	No tmp = lista->cabeca->proximo;

        if( tmp == lista->cauda || (lista->tamanho < indice) || indice <= 0)
        {
           return -1;
        }

        else if( indice == 0)
	{
	   removido = LIS_RemoverInicio(lista);
	   return removido; 
	}
	else if (indice == lista->tamanho)
	{
	    removido = LIS_RemoverFim(lista);
	    return removido;
	}
	else
	{
        for(int i=1; tmp->proximo != NULL && i< indice; tmp=tmp->proximo, i++);
		removido = tmp->valor;
		tmp->proximo->anterior = tmp->anterior;
		tmp->anterior->proximo = tmp->proximo;
		lista->tamanho-= 1;
		DestruirNo( tmp);
		return removido;
        }
 }

/*
    Função que ordena a lista. (Obs.: Implemente os algoritmos: selection sort, insertion sort e bubble sort.)
 */
void LIS_Ordenar(Lista lista)
{
	No tmp1 = lista->cabeca->proximo;
	for( ; tmp1->proximo->proximo != lista->cauda; tmp1=tmp1->proximo){
		for(No tmp2=tmp1->proximo; tmp2->proximo!=lista->cauda; tmp2=tmp2->proximo){
			if( tmp1->valor > tmp2->valor){
				std::swap(tmp1->valor, tmp2->valor);
			}
		}
	}
}

/*
    Função que intercala duas listas ordenadas, retornando uma nova lista contendo a intercalação das duas listas de entrada.
 */
Lista LIS_Intercalar(Lista lista1, Lista lista2)
{
	
	Lista list;
	list=LIS_Criar();
	No tmp1 = lista1->cabeca->proximo;
	No tmp2 = lista2->cabeca->proximo;
	while(1)
	{ 
		if(tmp1->proximo==NULL){
			for(; tmp2->proximo!=NULL; tmp2=tmp2->proximo ){
				LIS_InserirFim(list, tmp2->valor);
			}
			break;
		}
		if(tmp2->proximo==NULL){
			for(;tmp1->proximo!=NULL; tmp1=tmp1->proximo){
				LIS_InserirFim(list, tmp1->valor);
			}
			break;
		}
		LIS_InserirFim(list, tmp1->valor);
		tmp1=tmp1->proximo;
		LIS_InserirFim(list, tmp2->valor);
		tmp2=tmp2->proximo;
	}
	LIS_Ordenar(list);
    return list;
}

bool LIS_InserirOrdenado(Lista lista, int valor)
{
	No novo = CriarNo(valor);
	No tmp = lista->cabeca;
	int contador = 0; 
	if(tmp->proximo == lista->cauda)
	{
		return LIS_InserirInicio(lista, valor);
	}
	while(tmp != lista->cauda)
	{
		if(tmp->valor < valor)
		{
			contador +=1;
		}
		tmp = tmp->proximo;
	}
	return LIS_Inserir(lista, valor, contador);

}

No LIS_BuscarMF(Lista lista, int v)
{
    No tmp = lista->cabeca;
    bool retirou, colocou;
    int contador = 0;
    while(tmp->proximo != lista->cauda)
    {
        if(tmp->valor != v)
        {
            contador ++;
        }
        tmp = tmp->proximo;
    }
    retirou = LIS_Remover(lista, contador);
    colocou = LIS_InserirInicio(lista, v);
    No tmp2 = lista->cabeca->proximo;
    return tmp2;
}

No LIS_BuscarCF(Lista lista, int v)
{
	No tmp = lista->cabeca;
    while(tmp->proximo != lista->cauda && tmp->valor != v)
    {
        tmp = tmp->proximo;
    }
    tmp->contadorAcessos ++;
    No aux = LIS_BuscarMF(lista, tmp->valor);
    return aux;
}
/*
    Função que verifica se uma determinda instância da estrutura lista obedece a todas suas invariantes.
 */
LIS_tpVerificacao LIS_Verificar(Lista lista)
{
    if( lista->cabeca == NULL )
    {
        return LIS_CabecaNula;
    }
    
    if( lista->cauda == NULL )
    {
        return LIS_CaudaNula;
    }
    
    if( lista->cabeca->anterior != NULL )
    {
        return LIS_CabecaAnterior;
    }
    
    
    if( lista->cauda->proximo != NULL )
    {
        return LIS_CaudaProximo;
    }
    
    if(lista->tamanho == 0)
    {
        if( lista->cabeca->proximo != lista->cauda )
        {
            return LIS_CabecaCauda;
        }
        
        if( lista->cabeca != lista->cauda->anterior )
        {
            return LIS_CabecaCauda;
        }
    }
    else
    {
        for(No i = lista->cabeca->proximo; i != lista->cauda; i=i->proximo)
        {
            if( i->proximo->anterior != i )
            {
                return LIS_EncadeamentoErrado;
            }
            if( i->anterior->proximo != i )
            {
                return LIS_EncadeamentoErrado;
            }
        }
    }
    
    return LIS_OK;
}

/*
    Função que imprime todos os elementos de uma lista.
 */
void LIS_Imprimir(Lista lista)
{
    std::cout << "Tamanho " << lista->tamanho << std::endl;
    for(No i = lista->cabeca->proximo; i != lista->cauda; i = i->proximo)
    {
        std::cout << "[" << i->valor << "]->";
    }
    std::cout << std::endl;
}

/**
 Função que libera a memória de uma instância da estrutura Lista, liberando a memória de todos os nós encadeados na lista, incluindo os nós cabeça e cauda.
 */
void LIS_Destruir(Lista lista)
{
    No atual = lista->cabeca;
    while( atual != NULL )
    {
        No destruido = atual;
        atual = atual->proximo;
        DestruirNo(destruido);
    }
    free(lista);
}

/*
 Função que aloca a memória para um nó e inicializa os atributos do nó.
 */
No CriarNo(int v)
{
    No no = (No) malloc( sizeof( tpNo ) );
    if( no == NULL )
    {
        return NULL;
    }
    
    no->proximo = NULL;
    no->anterior = NULL;
    
    no->valor = v;
    no->contadorAcessos +=1;
    
    return no;
}

/*
 Função que libera a memória alocada para um nó.
 */
bool DestruirNo(No no)
{
    free(no);
    return true;
}


