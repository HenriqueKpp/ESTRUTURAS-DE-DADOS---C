#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
struct no *abaixo;
int valor;
}No;

typedef struct piha{
No *topo;
}Pilha;

//push
void Inserir(Pilha *pilha, int valor){
No *novo = (No*)malloc(sizeof(No));
No *aux = (No*)malloc(sizeof(No));
aux->abaixo = NULL;
aux->valor = NULL;
novo->abaixo = NULL;
novo->valor = valor;
if(pilha->topo == NULL)
pilha->topo = novo;
else{
aux = pilha->topo;
pilha->topo = novo;
pilha->topo->abaixo = aux;
}
}

//POP
int Remover(Pilha *pilha){
No *aux = (No*)malloc(sizeof(No));
aux->abaixo=NULL;
aux ->valor =NULL;
if(pilha->topo == NULL){
printf("********PILHA ESTA VAZIA***************");
return NULL;
}else{
aux = pilha->topo->abaixo;
int sla =pilha->topo->valor;
pilha->topo = NULL;
pilha->topo = aux;
return sla;
}
}

void Impressao(Pilha *pilha){
No *aux = (No*)malloc(sizeof(No));
aux->abaixo = NULL;
aux->valor = NULL;
if(pilha->topo == NULL)
printf("\n\n***********PILHA ESTA VAZIA****************\n\n");
else{
printf("\n\n*************PILHA**************\n");
aux = pilha->topo;
printf("--%d\n",pilha->topo->valor);
while(aux->abaixo!=NULL ){
printf("--%d\n",aux->abaixo->valor);
aux = aux->abaixo;
}
}

}


int main(){

Pilha pilha;
pilha.topo = NULL;
int valor, ope, aux;

do{
printf("\n\n**********ESCOLHA UMA OPERACAO************\n\n");
printf(" 1 = INSERIR \n 2 = REMOVER \n 3 = IMPRIMIR \n 5 = FECHAR PROGRAMA\n\n");
scanf("%d",&ope);

switch (ope)
{
case 1:
printf("\n\n********DIGITE O VALOR QUE DESEJA INSERIR:*********\n");
scanf("%d",&valor);
Inserir(&pilha, valor);
    break;

case 2:
aux = Remover(&pilha);
if(aux != NULL)
printf("********** VALOR REMOVIDO: %d *************",aux);
    break;

case 3:
Impressao(&pilha);
    break;

case 5:
printf("\n\n*****************PROGRAMA FINALIZADO **********************\n\n");

    break;

default:
printf("**********OPERACAO INVALIDA***************");
    break;
}

}while(ope != 5);

    return 0;
}