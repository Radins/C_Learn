#include <stdio.h>
#include <stdlib.h>
#define N 8 // <------ Constante

//MAIOR VALOR
float maior(float x[], int tam){
    int i;
    float ma;

    ma = x[0];
    for(i=1; i<tam; i++){
        if(x[i]>ma){
            ma = x[i];
        }
    }
    return ma;
}
//SOMA
float soma (float x[], int tam){
    int i;
    float som=0;

    for(i=0; i<tam; i++){
        som = som + x[i];
    }
    return som;
}
int main(){
    float nota[N],med=0;
    int i;

    for(i=0; i<N; i++){
        printf("Nota do aluno %i: ", i);
        scanf("%f", &nota[i]);
        med = med + nota[i];
    }
    for (i=0;i<N;i++){
        printf("Nota de %i é: %.2f\n", (i+1), nota[i]);
    }
    printf("Média: %.2f \n", (med)/N);
    printf("Maior valor: %.2f \n",maior(nota,N));
    printf("Soma: %.2f \n", soma(nota,N));
}