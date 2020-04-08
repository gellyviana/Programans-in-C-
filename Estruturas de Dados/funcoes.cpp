#include "funcoes.h"

bool inserir(TabelaLista tabela, Chave chave, Item item)
{
	if (tabela == NULL || chave == NULL || item == NULL)
		return false;

	int h = hash(preHash(chave), tabela.tamanho);

	if (tabela.itens[h] == NULL)
	{
		tabela.itens[h] = criarLista();
		inserirInicio(tabela.itens[h], chave, item);
		return true;	
	}

	inserirInicio(tabela.itens[h], chave, item);
	return true;
}

bool remover(TabelaLista tabela, Chave chave)
{
	if (tabela == NULL || chave == NULL)
		return false;

	int h = hash(preHash(chave), tabela.tamanho);

	if (tabela.itens[h] == NULL)
	{
		return false;
	}

	return remover(tabela.itens[h], chave);
}

Item buscar(TabelaLista tabela, Chave chave)
{
	if (tabela == NULL || chave == NULL)
		return NULL;

	int h = hash(preHash(chave), tabela.tamanho);

	if (tabela.itens[h] == NULL)
	{
		return NULL;
	}

	return buscar(tabela.itens[h], chave);
}

TabelaLista redimensionar(TabelaLista tabela, int novoTamanho)
{
	TabelaLista nova = criarTabelaLista(novoTamanho);

	for (int i = 0; i < tabela.tamanho; i++)
	{
		if (tabela.itens[i] != NULL)
		{
			Lista lista = tabela.itens[i];
			for (No p = lista->cabeca->proximo; p != lista->cauda; p = p->proximo)
			{
				inserir(nova, p->item, p->chave);
			}
		}
	}
	tabela = nova;
	return tabela;
}