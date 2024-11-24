#include <stdio.h>
#include <stdlib.h>

typedef struct No {
int valor;
struct No *proximo;
}No;


typedef struct {
No *inicio;
int tam;
}Lista;

void InserirNoInicio(Lista *lista, int valor){
    No *novo = (No*)malloc(sizeof(No));
    novo ->valor = valor;
    novo ->proximo = lista -> inicio;
    lista -> inicio = novo;
    lista->tam++;
}

void InserirNoFinal(Lista *lista, int valor){
No *no, *novo = (No*)malloc(sizeof(No));
novo -> valor = valor;
novo -> proximo = NULL;

if(lista->inicio == NULL){
lista->inicio = novo;

}else{

no = lista -> inicio;
while(no->proximo != NULL){
no = no -> proximo; 
}
no-> proximo = novo;

}
lista -> tam++;
}



void RemoverInicio(Lista *lista, int valor){

No *inicio = lista-> inicio;
No *aux = NULL;

if(inicio != NULL && lista->inicio-> valor == valor){
aux->proximo = lista->inicio;
lista->inicio = aux ->proximo;

}else{
while(inicio != NULL && inicio->proximo != NULL && inicio->proximo->valor != valor){
 inicio = inicio ->proximo;
}
if(inicio != NULL && inicio ->proximo != NULL){
    aux = inicio->proximo;
    inicio->proximo = aux ->proximo;

}
}
if(aux){
    free(aux);
    lista->tam--;
}

}


void imprimir(Lista *lista){
    No *inicio = lista -> inicio;
printf("Tamanho da lista: %d",lista->tam);
    while(inicio != NULL ){
printf("\n%d" , inicio->valor);
inicio = inicio -> proximo;}

printf("\n\n");
}


int main(){
Lista lista;
int opcao,valor;
lista.inicio = NULL;
lista.tam = 0;

do{
printf("Inserir no inicio -1 \t Imprimir -2 \tInserir no fim -3\tRemover item - 4 \t Sair - 5");
scanf("%d",&opcao);

switch (opcao)
{
case 1:
   printf(" Digite o valor que deseja inserir:\t") ;
   scanf("%d", &valor);
   InserirNoInicio( &lista , valor);
    break;
case 2:
    imprimir(&lista);
    break;
case 3:
  printf(" Digite o valor que deseja inserir:\t") ;
   scanf("%d", &valor);
    InserirNoFinal(&lista, valor);
    break;
      case 4:
  printf(" Digite o valor que deseja remover:\t") ;
   scanf("%d", &valor);
   RemoverInicio(&lista, valor);
    break;
case 5:
    printf("Fim do programa");
    break;

default:
printf("Valor invalido!");
    break;
}

}while(opcao != 5);



return 0;
}