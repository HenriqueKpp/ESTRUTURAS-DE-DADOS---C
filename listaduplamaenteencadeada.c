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
lista->inicio->posterior->anterior = lista->inicio;
}





void ImprimirListaFinal(Lista *lista){
int i = 1;
No *aux;
aux = lista->inicio;
while(aux->posterior != NULL){
aux = aux->posterior;
i++;
}
printf("\n\n*********LISTA REVERSA********\n");
while(aux != NULL){
printf("%d- %d\n",i,aux->valor);
i--;
aux = aux->anterior;
}

}

//TERMINANDO ***********
void InserirNoMeio(Lista *lista){
int posicao;
int quantidade =0;
printf("\n\nEM QUAL POSICAO DE SEJA INSERIR?\n ");
scanf("%d\n\n",&posicao);
No *novo = (No*)malloc(sizeof(No));
No *aux = lista->inicio;
do{
if(aux != NULL)
quantidade++;
aux = aux->posterior;
} while(aux!= NULL);
if(posicao == 1){


}
if(posicao == quantidade){


}

}



int main(){
Lista *lista;
int ope;
Criarlista(lista);
do{

printf("\n\nOPERACOES: 1- INSERIR FINAL\t 2- INSERIR INICIO\t 3-IMPRMIR LISTA PELO INICIO\t 4-IMPRIMIR PELO FINAL\n \t5- INSERIR NO MEIO \t 10- FINALIZAR PROGRAMA\n\n");
scanf("%d",&ope);

switch(ope)
{
case 1:
   NovoNoFinal(lista);
    break;
case 2:
    NovoNoInicio(lista);
break;

case 3:
    ImprimirListaInicio(lista);
break;

case 4:
    ImprimirListaFinal(lista);
break;

case 5: 
    //TERMINANDO******
    InserirNoMeio(lista);
    break;

default:
printf("\n******Valor invalido!******\n");
    break;

}

}while(ope!= 10);

    return 0;
}
