#ifndef BUSCAS_H_INCLUDED
#define BUSCAS_H_INCLUDED


using namespace std;

void particao(int[], int, int, int*, int*);
void quickSort(int[], int, int);
bool buscaSeqInt (int[], int, int, int*);
bool buscaSeqRec (int[], int, int, int*);
bool buscaBinInt (int[], int, int, int*);
bool buscaBinRec (int[], int, int, int*);
bool buscaBinRecAux (int[], int, int, int, int*);

#endif //BUSCAS_H_INCLUDED