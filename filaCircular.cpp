#include <iostream>
#define TAM 8

using namespace std;

struct Fila{
    int inicio;
    int qtdEle;
    int fila[TAM];
};

struct Fila* fl;

void CriaFila(struct Fila* fl)
{
    fl->inicio = 3;
    fl->qtdEle = 0;
}

void inserirFila(struct Fila* fl, int valor)
{
    if(fl->qtdEle == TAM)
    {
        cout<<"Fila cheia\n";
    }

    fl->fila[(fl->qtdEle + fl->inicio) % TAM] = valor;
    fl->qtdEle +=1;

}

int removerFila(struct Fila* fl)
{
    if(fl->qtdEle == 0)
    { 
        cout<<"Fila vazia\n";
    }
    fl->qtdEle -= 1;
    return fl->fila[(fl->inicio - fl->qtdEle) % TAM];
}

void printFila(struct Fila* fl)
{
    for(int i = fl->inicio; i<(fl->qtdEle + fl->inicio); i++)
    {
        cout<<"Fila: "<<fl->fila[i]<<endl;
    }
}

int main(int argc, char **argv)
{

    struct Fila *fl = new struct Fila;
    CriaFila(fl);
    inserirFila(fl, 10);
    inserirFila(fl, 20);
    inserirFila(fl, 30);
    inserirFila(fl, 40);
    printFila(fl);
    cout<<"O valor removido da Fila: "<<removerFila(fl)<<endl;
    cout<<"O valor removido da Fila: "<<removerFila(fl)<<endl;
    cout<<"O valor removido da Fila: "<<removerFila(fl)<<endl;
    printFila(fl);
    return 0;
}
