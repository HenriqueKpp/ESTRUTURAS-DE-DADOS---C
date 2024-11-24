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
printf("\nNome: %s \t Aniversario: %d/%d/%d\n\n",p.nome,p.data.dia,p.data.mes,p.data.ano);

}


typedef struct {

No *topo;
int tam;

}Pilha;


void criar_pilha(Pilha *p){

p ->topo = NULL;
p -> tam =0;


}








Pessoa ler_pessoa() 
{
    Pessoa p;
    
    printf("\n Digite o nome, data de nascimento dd mm aaaa: \n");
    scanf("%49[^\n]%d%d%d", p.nome, &p.data.dia, &p.data.mes, &p.data.ano);
    return p;
}



void empilhar(Pilha *p){

No *novo = malloc(sizeof(No));

if(novo){
novo->p = ler_pessoa();
novo->proximo = p -> topo;
p ->topo = novo;
p -> tam++;

}else{
printf("A alocacao da memoria nao funcionou");

}
}



No* desempilhar(Pilha *p){
    if(p-> topo){
    No *remover = p ->topo;
    p-> topo = p->topo-> proximo;
    return remover;
    p -> tam--;
    }else
    printf("Pilha vazia");
return NULL;


}
void imprimirpilha(Pilha *p){
    No *aux;
printf("--------- PILHA  tam : %d--------\n\n",p ->tam);
while (aux)
{
    imprimir(aux->p);
    aux = aux->proximo;
}

printf("---------FIM PILHA --------\n\n");




}





int main(){

int resposta;
Pilha p;
No *removido;
criar_pilha(&p);

do{
printf("Inserir -1 \t Remover-2\t Imprimir-3 \t Sair-5\n");
scanf("%d",&resposta);
getchar();


switch (resposta)
{
case 1:
 empilhar(&p);
    break;

case 2:
removido = desempilhar(&p);
if (removido)
{
    

printf("Pessoa removida:");
imprimir(&removido->p);
free(removido);
}else{

    printf("Sem nos a remover");
}
    
    break;
case 3:
imprimirpilha(&p);

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

