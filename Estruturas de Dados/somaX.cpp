#include <iostream>

using namespace std;

bool somaX(int vet[10], int tam, int x){
	int i=0, j=tam, soma=0, meio=tam/2;
	while(j>i){
		if(vet[meio]<x){
			j=meio-1;
			soma=vet[i]+vet[j];
			//cout<<"I: "<<vet[i]<<endl;
			//cout<<"J: "<<vet[j]<<endl;
			//cout<<"Soma: "<<soma<<endl;
			if(soma==x){ 
				return true;
			}
		}
				i++;
				j--;
	}
	return false;
}

int main(int argc, char *argv[])
{
	int vet[10]={1,2,3,4,5,6,7,8,9,10};
	int x=8;
	
	cout<<"Valor logico da soma: "<<somaX(vet, 10, x)<<endl;
	
	return 0;
}
