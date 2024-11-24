#include <stdio.h>
#include <stdlib.h>

typedef struct no{
struct no *proximo;
int valor;
}No;


typedef struct fila{
No *inicio;
}Fila;

void InserirNaFila(Fila *fila, int valor){
No *novo = (No*)malloc(sizeof(No));
No *aux = (No*)malloc(sizeof(No));
novo->proximo = NULL;
novo->valor = valor;

if(fila->inicio == NULL)
fila->inicio = novo;
else{
aux = fila->inicio;
while(aux->proximo != NULL){
aux = aux->proximo;
}
aux->proximo = novo;
}
}


int RemoverDaFila(Fila *fila){
No *aux = (No*)malloc(sizeof(No));
aux->proximo = NULL;

if(fila->inicio == NULL){
printf("\n\n******** A FILA ESTA VAZIA*********\n\n");
return NULL;
}else{
int sla = fila->inicio->valor;
aux = fila->inicio->proximo;
fila->inicio = NULL;
fila->inicio = aux;
return sla;
}
}

void Impressao(Fila *fila){
No *aux = (No*)malloc(sizeof(No));
aux->proximo = NULL;
aux->valor = NULL;
if(fila->inicio == NULL)
printf("\n\n*************FILA ESTA VAZIA ****************\n\n");
else{
    printf("\n\n***********FILA*************\n\n");
aux->proximo = fila->inicio;
while(aux->proximo != NULL){
printf("-- %d\n",aux->proximo->valor );
aux= aux->proximo;
}
}
}


int main() {

Fila fila;
fila.inicio = NULL;
int ope,valor,aux;

do{

printf("\n\n*************QUAL OPERACAO DESEJA REALIZAR?******************\n\n");
printf(" 1 = INSERIR \n 2 = REMOVER \n 3 = IMPRIMIR\n 5 = FINALIZAR PROGRAMA\n");
scanf("%d",&ope);

switch (ope)
{
case 1:
printf("\n************DIGITE O VALOR QUE DESEJA ADICIONAR: ************\n");
scanf("%d",&valor);
InserirNaFila(&fila, valor);
break;

case 2:
aux = RemoverDaFila(&fila);
if(aux != NULL)
    printf("**********VALOR REMOVIDO: %d **************",aux);
break;

case 3:
    Impressao(&fila);
break;

case 5:
printf("************PROGRAMA FINALIZADO **************");   
break;

default:
printf("***********OPERACAO INVALIDA REALIZADA************");
    break;
}

}while(ope !=5);

    return 0;
}