#include <stdlib.h>
#include <stdio.h>

typedef struct no{
int valor;
struct no *posterior;
struct no *anterior;
}No;

typedef struct{
No *inicio;
}Lista;


 void *Criarlista(Lista *lista){
    int valor;
lista->inicio = (No*)malloc(sizeof(No));
lista->inicio->anterior= NULL;
lista->inicio->posterior= NULL;
lista->inicio->valor = 0;
printf("\nVALOR DO PRIMEIRO NO:");
scanf("%d",&valor);
lista->inicio->valor = valor;
}



void NovoNoFinal(Lista *lista){
 int valor;
No *novo = (No*)malloc(sizeof(No));

novo->anterior = NULL;
novo->posterior = NULL;
printf("\nVALOR DO NOVO NO A SER INSERIDO NO FINAL:");
scanf("%d",&valor);
novo->valor = valor;

No *aux;
aux = lista->inicio;
while(aux->posterior != NULL){
aux = aux->posterior;
}
novo->anterior = aux;
aux->posterior =  novo;

}




void ImprimirListaInicio(Lista *lista){
No *aux = (No*)malloc(sizeof(No));
aux = lista->inicio;
int i = 1;
printf("\n\n********LISTA*********\n ");
while(aux != NULL){
printf("%d- %d\n",i,aux->valor);
i++;
aux = aux->posterior;
}
}



void NovoNoInicio(Lista *lista){

int valor;
No *novo = (No*)malloc(sizeof(No));

novo->anterior = NULL;
novo->posterior = NULL;
printf("\nVALOR DO NOVO NO A SER INSERIDO NO INICIO:");
scanf("%d",&valor);
novo->valor = valor;

No *aux=  lista->inicio;
lista->inicio = novo;
lista->inicio->posterior = aux;
lista->inicio->posterior->anterior = lista->inicio->posterior;
}





//void ImprimirListaFinal(Lista *lista){
//int i = 1;
//No *aux;
//aux = lista->inicio;
//while(aux->posterior != NULL){
//aux = aux->posterior;
//i++;
//}
//printf("\n\n*********LISTA REVERSA********\n");
//while(aux->anterior != NULL){
//printf("%d- %d\n",i,aux->valor);
//i--;
//aux = aux->anterior;
//}

//}







int main(){

Lista *lista;
Criarlista(lista);
NovoNoFinal(lista);
NovoNoFinal(lista);
NovoNoFinal(lista);
NovoNoFinal(lista);
NovoNoInicio(lista);
NovoNoInicio(lista);
ImprimirListaInicio(lista);
//nao funciona ainda
//ImprimirListaFinal(lista);











    return 0;
}