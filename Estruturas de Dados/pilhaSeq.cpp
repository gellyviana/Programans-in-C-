#include <iostream>

#define TAM 50

using namespace std;

typedef struct Pilha{
    int baterry[TAM];
    int qtdEle;
    int fim;
}Pilha;

//struct Pilha * Pilhao;

void cria(Pilha *p )
{
    p->qtdEle = 0;
    p->fim = 0;
}

void inseriEle(Pilha * p, int valor)
{
    if(p->qtdEle == TAM)
    {
        cout<<" Pilha cheia\n";
    }
    p->baterry[p->fim] = valor;
    p->fim += 1;
    p->qtdEle += 1;

}

int removeEle(Pilha* p)
{
    if (p-> qtdEle == 0)
    {
        cout<<"Pilha vazia\n";
    }

    p->qtdEle -= 1;
    p->fim -= 1;
    return p->baterry[p->fim];

}

int acessoEle(Pilha * p)
{
    if (p-> qtdEle == 0)
    {
        cout<<"Pilha vazia\n";
    }

    return p->baterry[p->qtdEle-1];

}

void printPilha(Pilha * p)
{
    for(int i=0; i< p->qtdEle; i++)
    {
        cout<<p->baterry[i]<<endl;
    }
}

int main (int argc, char**argv)
{
    Pilha p;
    cria(&p);
    inseriEle(&p, 10);
    inseriEle(&p, 20);
    inseriEle(&p, 30);
    inseriEle(&p, 40);
    printPilha(&p);
    cout<<"Valor removida pilha: "<<removeEle(&p)<<endl;
    printPilha(&p);
    cout<<"Acesso a um elemento da pilha: "<<acessoEle(&p)<<endl;

    return 0;
}