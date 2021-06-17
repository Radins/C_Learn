#include <stdio.h>
#include <stdlib.h>

int main(){
    float n1, n2, n3, media;                    // Define the values

    printf("Enter the first grade: ");
    scanf("%f", &n1);
    printf("Enter the second grade: ");
    scanf("%f", &n2);
    printf("Enter the third grade: ");
    scanf("%f", &n3);           //  scanf -> Read // %f -> Read Float // & -> Rout the constant
    media = (n1+n2+n3)/3;
    printf("A média do aluno é: %f \n", media);
    if (media >= 7.0){
        printf("O aluno está provado! \n");     // \n -> Breck line
    }else{
        printf("O aluno está reprovado! \n");
    }
    return 0;
}
