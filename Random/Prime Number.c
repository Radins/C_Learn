#include <stdio.h>
#include <stdlib.h>

int main(){
    int num, div = 2, x = 1;
    float rest;

    printf("Enter an integer number \n");
    scanf("%i", &num);

    if(num <= 0){
        printf("%i isn't a vallid number");
    }else{
       if(num <= 0){
            printf("This number is invalid");
        }else
            while(div < num){
                rest = num % div;+
                ++div;
                if(rest == 0){
                    x=0;
                    break;
                }
            }
        
        if(x==0 || num == 1){
            printf("%i isn't a prime number.", num);
        }else{
            printf("%i is a prime number.", num);
        }
    }
}


