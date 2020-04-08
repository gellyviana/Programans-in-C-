//Lista Encadeada com inicio e fim.
#include <iostream>
#include <cstddef>//Library do nullptr

using namespace std;

//Estrutura do No.
typedef struct No{
	int number;
	No*   next;
}No;

//Estrutura da Lista.
typedef struct List{
	No* comeco;
	No* fim;
	int count;
}List;

//Funcao que cria a lista.
List* creation (List* novo){
        novo=        new List;         //criando um novo No.
	novo->comeco= nullptr; //inicializando os ponteiros.
	novo->fim=    nullptr;
	novo->count=     0;      //inicializando o contador.
	return novo;
}

//Funcao que inseri no fim da lista.
void insertionEnd (List* lista, int valor){
	No* novo= new No;                  //cria um novo No.
	if(lista->comeco== nullptr){	   //se a lista estiver vazia.
		novo->number=  valor;	   //recebe o valor.
		novo->next=  nullptr;	   //next do No recebe nullptr.
		lista->comeco= novo;       //comeco da lista aponta para novo No
		lista->fim=    novo;       //fim tambem aponta para o novo.
		lista->count +=   1;       //contador recebe mais 1.
	}
	   else if (lista->comeco!=nullptr){//caso alista já possua No.
		No* existe=   lista->fim;   //No auxiliar recebe o fim da lista.
		novo->number=      valor;   //recebe o valor.
		novo->next= existe->next;   //novo No recebe o next do ult. No.
		existe->next=       novo;   //ultimo No recebe novo
		lista->fim=         novo;   //e fim da lista aponta para novo No
		lista->coun +=         1;   //contador recebe mais 1.
	}
}

//Funcao que inseri no inicio da lista.
void insertionOutset(List* lista, int valor){
	No* novo=          new No;          //cria um novo no.
	No* existe= lista->comeco;          //faz uma copia do primeiro no da lista.
	novo->number=       valor;          //recebe valor.
	novo->next=        existe;          //o ponteiro next aponta para primeiro no.
	lista->comeco=       novo;          //e novo cemeço recebe o no endereço do no.
	lista->count+=          1;
}

//Funcao que procura um elemento pelo lista.
void searchElement(List* lista, int valor){
	No* tmp= lista->comeco;             //no que recebe o primeiro no da lista.
	while(tmp->next!=nullptr){          //enquanto o next for diferente de nullptr
		if(tmp->number==valor){     //compara o numero contido no No com o valor passado.
			cout<<"Valor "<<tmp->number<<" encontrado!!!"<<endl;
		}                           //caso encontrado manda a mensagem
		tmp=tmp->next;              //caso nao encontrado passa para o proximo.
	}
}

//Funcao que remove o primeiro no.
void removeOutset(List* lista){
	No* existe=   lista->comeco;        //No recebe o primeiro No da lista.
	No* tmp=lista->comeco->next;        //No passa para o segundo No da lista.
	delete             (existe);        //apaga o primeiro No da lista.
	lista->comeco=          tmp;        //ponteiro comeco aponta para o primeiro novo No.
	lista->count-=            1;        //decrementa um 1.
}

//Funcao que remove o ultimo No da lista.
void removeEnd(List* lista){
	No* existe= lista->comeco;          //recebe o primeiro no da lista.
	No* tmp=       lista->fim;          //recebe o ultimo no da lista.
	while(existe->next!=tmp->next){     //enquanto comeco for diferente de fim.
		existe= existe->next;       //percorre a lista.
 	}
	existe->next= tmp->next;            //saido do laco, o next de comeco recebe o next de fim.
	lista->fim=      existe;            //o ponteiro do fim da lista recebe o novo No.
	delete (tmp);
}

//Funcao que imprime todos os No's da lista..
void printList(List* lista){
	No* existe=lista->comeco;           //recebe o primeiro No da lista.
	while(existe->next!= nullptr){
		cout<<"No:  "<<existe->number<<endl;
		existe=                existe->next;
	}
}

//Funcao que desaloca memoria.
void deleteList(List* lista){
	No* existe=lista->comeco;           //recebe o comeco da lista.
	while(existe!= nullptr){
		No* tmp= existe->next;      //No temporario recebe o proximo No da lista.
		delete       (existe);      //deleta o No atual.
		existe=           tmp;      //e faz receber a copia do proximo da lista.
	}
	delete (lista);                     //e depois de deletado os No's, deleta se a lista.
}

int main(){
	List* start= creation(start);       //cria uma nova lista.
	insertionEnd(start,   10);          //inseri um elemento no fim da lista.
	insertionEnd(start,   20);
	insertionEnd(start,   30);
	insertionEnd(start,   40);
	insertionEnd(start,   50);
	insertionOutset(start, 5);         //inseri no comeco da lista.
	insertionOutset(start, 1);        
	searchElement(start,  10);         //procura pelo elemento na lista.
	removeOutset(start);               //remove o primeiro No da lista.
	removeEnd(start);                  //remove o ultimo No da lista.
	printList(start);                  //imprime a nova lista.
	deleteList(start);                 //deleta a lista por completo.
	return 0;
}
