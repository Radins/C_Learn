#include<stdio.h>
#include<stdlib.h>

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    if (num % 2 == 0){
        printf("The number %i is even \n", num);
    }else{
        printf("The number %i is odd \n", num);
    }
}
