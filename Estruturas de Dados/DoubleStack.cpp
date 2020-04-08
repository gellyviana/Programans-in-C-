#include <iostream>
#define MAX 5

using namespace std;

typedef struct Pilha
{
	int topo1;
	int topo2;
	int vetor[MAX];
	int tamanho;
}Pilha;

void CriarPilha(Pilha& pilha)
{
	pilha.topo1= 0;
	pilha.topo2=MAX;
	pilha.tamanho= 0;
}

void PushDown(Pilha& pilha, int valor)
{
	if(pilha.topo1 == pilha.topo2)
	{
		cout<<"Estorou a Pilha"<<endl;
	}
	pilha.topo1+=1;
    pilha.vetor[pilha.topo1]=valor;
    pilha.tamanho++;
}

void PushUp(Pilha& pilha, int valor)
{
	if (pilha.topo1==pilha.topo2)
	{
		cout<<"Estorou a Pilha"<<endl;
	}
	pilha.topo2-=1;
	pilha.vetor[pilha.topo2]=valor;
	pilha.tamanho++;
}

int PopDown(Pilha& pilha)
{
	if (pilha.topo1==0)
	{
		cout<<"Vazia a Pilha"<<endl;
	}
	int removido;
	removido=pilha.vetor[pilha.topo1-1];
	pilha.tamanho--;
	return removido;
}

int PopUp(Pilha& pilha)
{
	if(pilha.topo2==MAX)
	{
		cout<<"Vazia a Pilha"<<endl;
	}
	int removido;
	removido=pilha.vetor[pilha.topo2+1];
	pilha.tamanho--;
	return removido;
}

void DoublePush(Pilha& pilha, int valor)
{
	if (pilha.topo2==pilha.topo1)
	{
		cout<<"Estorou a Pilha"<<endl;
	}
	pilha.topo1+=1;
	pilha.vetor[pilha.topo1]= valor;
	pilha.topo2-=1;
	pilha.vetor[pilha.topo2]= valor;
	pilha.tamanho+=2;
}

void DoublePop(Pilha& pilha, int &removido1, int &removido2)
{
	if(pilha.topo1==0 || pilha.topo2==MAX)
	{
		cout<<"Vazia a Pilha"<<endl;
	}
	removido1= pilha.vetor[pilha.topo1-1];
	removido2= pilha.vetor[pilha.topo2+1];
	pilha.tamanho-=2;
}

void imprime(Pilha& pilha)
{
	int var=1;
	while(var <= pilha.tamanho)
	{
		cout<<"Pilha: "<<pilha.vetor[var]<<endl;
		var++;
	}
}

int main(int argc, char const *argv[])
{
	Pilha pilha;
	int removido1, removido2;
	CriarPilha(pilha);
	PushDown(pilha, 10);
	PushDown(pilha, 20);
	PushUp(pilha, 30);
	PushUp(pilha, 40);
	PopDown(pilha);
	PopUp(pilha);
	DoublePush(pilha, 15);
	DoublePop(pilha, removido1, removido2);
	cout<<"Valor dos removidos: "<<removido1<<", "<<removido2<<endl;
	imprime(pilha);
	return 0;
}