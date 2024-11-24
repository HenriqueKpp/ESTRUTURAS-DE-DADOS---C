#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int mes;
    int ano;
    int dia;
}Data;



typedef struct {
Data data;
char nome[100];
}Pessoa;




typedef struct No{
Pessoa p;
struct No *proximo;
}No;

void imprimir(Pessoa p){
printf("\nNome: %s \t Aniversario: %d/%d/%d\n\n",&p.nome,p.data.dia,p.data.mes,p.data.ano);

}

Pessoa ler_pessoa() 
{
    Pessoa p;
    
    printf("\n Digite o nome, data de nascimento dd mm aaaa: \n");
    scanf("%49[^\n]%d%d%d", p.nome, &p.data.dia, &p.data.mes, &p.data.ano);
    return p;
}



No* empilhar(No *topo){

No *novo = malloc(sizeof(No));

if(novo){
novo->p = ler_pessoa();
novo->proximo = topo;
return novo;


}else{
printf("A alocacao da memoria nao funcionou");
return NULL;
}
}



No* desempilhar(No **topo){
    if(*topo != NULL){
    No *remover = *topo;
    *topo = remover -> proximo;
    return remover;
    }else
    printf("Pilha vazia");
return NULL;


}
void imprimirpilha(No *topo){
printf("--------- PILHA --------\n\n");
while (topo)
{
    imprimir(topo->p);
    topo = topo->proximo;
}

printf("---------FIM PILHA --------\n\n");




}





int main(){

int resposta;
No *topo = NULL;
No *removido;

do{
printf("Inserir -1 \t Remover-2\t Imprimir-3 \t Sair-5\n");
scanf("%d",&resposta);
getchar();


switch (resposta)
{
case 1:
topo = empilhar(topo);
    break;

case 2:
removido = desempilhar(&topo);
printf("Pessoa removida:");
imprimir(removido->p);
    break;
case 3:
imprimirpilha(topo);

    break;

case 5:

break;
default:
printf("Valor invalido, tente novamente.");
    break;
}

}while (resposta != 5);



    return 0;
}

