#include<stdio.h>
#include<stdlib.h>



typedef struct 
{
    int dia, mes ,ano;
}Data;



typedef struct 
{
Data d;
char nome[100];
}Pessoa;


typedef struct No{
Pessoa p;
struct No *proximo;

}No;



Pessoa entradadados(Pessoa p){
printf("\nDigite o valor do dia, mes e ano de nascimento respectivamente: \t");
scanf("%d%d%d",&p.d.dia,&p.d.mes,&p.d.ano);
printf("Escreva o nome da pessoa: ");
scanf("%s",p.nome);
getchar();
}



void Inserir(No *fila, No ultimo){
No novo, ultimo ;
entradadados(novo.p);
if(fila != NULL){
ultimo.proximo = &novo;
}else{
fila = &novo;
ultimo = novo;
}
    
}


int main(){

No *fila = NULL;
int operacao;


do{
    

printf("\n\n\n        ********OPERACAO QUE DESEJA REALIZAR**********\n Inserir-1\tRemover-2\tImprimir-3\tSair-5\n\n");
scanf("%d",&operacao);
getchar();

switch (operacao)
{
case 1:
Inserir(fila);

    break;
case 2:


    break;

case 3:

    break;


case 5:


    break;
default:
printf("Valor invalido");
    break;
}





}while(operacao != 5);








    return 0;
}