#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    float p, h, imc;

    printf("Informe sua altura em metros: ");
    scanf("%f", &h);
    printf("Informe seu peso em Kg ");
    scanf("%f", &p);

    imc = p/(h*h);
        printf(" %.2f \n", imc);

    if(imc<20){
        printf("Abaixo do peso");
    }
    if(imc>=20 && imc < 25){
        printf("Peso normal");
    }
    if(imc>=25 && imc < 30){
        printf("Sobre do peso");
    }
    if(imc>=30 && imc < 40){
        printf("Obeso");
    }
    if(imc>=30 && imc < 40){
        printf("Obesidade morbida");
    }
}
