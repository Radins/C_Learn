#include <stdio.h>
#include <stdlib.h>

int calc(int num){
    float sum=1;

    while(num > 0){
        num--;
        sum = sum + 1/num;

        
        printf("%f | ", sum);
        printf("%i\n" , num);
    }
    return sum;
}

int main(){

    int n=0;
    scanf("%i", &n);
    printf("%f \n", calc(n));
}