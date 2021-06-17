#include <stdio.h>
#include <stdlib.h>

int main(){                 
    int num, num_ans, ans = 1;

    printf("Digite o número do fatorial: ");
    scanf("%i", &num);

    num_ans = num;

    if(num < 0){
        printf("Fatorial de %i existe!", num_ans);
    }else{
        while(num > 0){

            ans = ans * num;
             num = num -1;
        }
    printf("O fatorial de %i é %i \n", num_ans, ans);
    }
}