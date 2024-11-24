#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int BuscaBinaria(int vet[],int inicio, int meio, int final,int chave){
int teste;
if(inicio!=0)
    meio = ((final - inicio)/2)+meio ;
else
    meio = ((final - inicio)/2) ;
if(vet[meio]==chave)
    return chave;
else if(meio<inicio || meio>final)
return 0;
else if(chave<vet[meio]){
    teste =BuscaBinaria(vet,inicio,meio-1,meio-1,chave);
    if(teste)
    return chave;
    else 
    return 0;
}else if(chave>vet[meio]){
    teste = BuscaBinaria(vet,meio+1,meio+1,final,chave);
  if(teste)
    return chave;
    else 
    return 0;
}
}




int main (){

int vet [9] = {14,35,39,57,80,124,654,712,990};
int resp;
char tem[]= {"Valor encontrado! -"};

resp = BuscaBinaria(&(vet),0,0,8,654);
if(resp)
printf("%s %d -",tem,resp);
else
printf("Valor nao encontrado");








return 0;
}