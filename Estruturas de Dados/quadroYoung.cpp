#include <iostream>

using namespace std;

bool quadroYoung(int lin, int col,int mat[][4]){
	
	int aux1=0, aux2=0;
	int i, j=0;
	
	for(i=0; i<lin; i++){
		for(j=0; j<col; j++){
			if(mat[i][j]<aux1){
				return false;
			}
				aux1=mat[i][j];
		}
		aux1=0;
	}
	for(j=0; j<col; j++){
		for(i=0; i<lin; i++){
			if(mat[i][j]<aux2){
				return false;
			}
			aux2=mat[i][j];
		}
		aux2=0;
	}
	return true;
}

int main(int argc, char *argv[]){
	
	int mat[4][4]={{9,15,16,20},
						{10,21,23,25},
						{17,30,33,39},
						{18,31,34,51}};
	
	cout<<"Valor logico do quadro Young: "<<quadroYoung(4, 4, mat)<<endl;
	
	return 0;
}

