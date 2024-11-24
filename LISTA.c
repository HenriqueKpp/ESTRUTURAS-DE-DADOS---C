#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
   int valor;
   struct no *proximo;

}No;

typedef struct lista
{
    No *inicio;
}Lista;



void InserirInicio(Lista *lista,int valor){
No *novo = (No*)malloc(sizeof(No));
novo->valor = valor;
novo->proximo = NULL;
if(lista->inicio == NULL){
lista ->inicio = novo;
}else{
novo->proximo = lista->inicio;
lista->inicio = novo;
}
}



void InserirFinal(Lista *lista, int valor){
No *novo = (No*)malloc(sizeof(No));
No *aux = (No*)malloc(sizeof(No));

aux->proximo =NULL;
novo->valor = valor;
novo->proximo = NULL;

if(lista->inicio == NULL)
lista->inicio = novo;
else{
   aux = lista->inicio; 
while(aux->proximo != NULL){
aux= aux->proximo;
}
aux->proximo = novo;

}
}


void Imprimir(Lista *lista){
    printf("\n\n*************LISTA***********\n\n");


No *aux = (No*)malloc(sizeof(No));
aux->proximo = lista->inicio;

while(aux->proximo != NULL){

printf("-- %d\n",aux->proximo->valor);
aux = aux->proximo;
}
}


int RemoverInicio(Lista *lista){

No *aux = (No*)malloc(sizeof(No));
if(lista->inicio != NULL){
int sla =lista->inicio->valor;
aux = lista->inicio->proximo;
lista->inicio = NULL;
lista->inicio = aux;
return sla;
}else
printf("\n\n********LISTA VAZIA *********\n\n");
return NULL;
}


int RemoverFinal(Lista *lista){
No *aux = (No*)malloc(sizeof(No));

if(lista->inicio == NULL){
printf("******LISTA VAZIA*******");
return NULL;
}else{
aux = lista->inicio;
while(aux->proximo->proximo != NULL){
aux = aux->proximo;
}
int sla = aux->proximo->valor;
aux->proximo = NULL;
return sla;
}
}

void RemoverMeio(int valor, Lista *lista){
No *aux = (No*)malloc(sizeof(No));

if(lista->inicio == NULL){
printf("********LISTA VAZIA**********");
}else{
aux = lista->inicio;
while(aux->proximo->valor != valor || aux->proximo == NULL){
aux = aux->proximo;
}
if(aux->proximo->valor == valor)
aux->proximo = aux->proximo->proximo;
else
printf("******VALOR NAO ESTA PRESENTE NA LISTA********");
}

}


int main() {

Lista lista;
lista.inicio = NULL;
int aux,valor,oper;

do{

printf("\n\n\n*************QUAL OPERACAO DESEJA REALIZAR**********\n\n");
printf(" 1 = INSERIR NO INICIO \n 2 = IMPRIMIR \n 3 = REMOVER DO INICIO \n 4 = REMOVER DO FINAL \n 5 = INSERIR NO FINAL\n 6 = REMOVER NO MEIO \n 7 = FINALIZAR PROGRAMA\n");
scanf("%d",&oper);
switch (oper)
{
case 1:
printf("****QUAL VALOR DESEJA INSERIR?******\n");
scanf("%d",&valor);
InserirInicio(&lista,valor);
    break;

case 2:
Imprimir(&lista);
    break;

case 3:
aux = RemoverInicio(&lista);
if(aux!=0)
printf("\n\n****** VALOR REMOVIDO: %d *******\n\n",aux);
    break;

case 4:

aux = RemoverFinal(&lista);
if(aux!=0)
printf("\n\n******** VALOR REMOVIDO: %d ********\n\n",aux);
    break;

case 5:
printf("****QUAL VALOR DESEJA INSERIR?******\n");
scanf("%d",&valor);
InserirFinal(&lista,valor);
    break;

case 6:
printf("****QUAL VALOR DESEJA REMOVER?******\n");
scanf("%d",&valor);
 RemoverMeio(valor,&lista);


break;

case 7:
printf("**********PROGRAMA FINALIZADO**********\n");

break;

default:
printf("\n*********VALOR INVALIDO DIGITADO- TENTE NOVAMENTE**********\n");
    break;
}

}while(oper != 7);

    return 0;
}