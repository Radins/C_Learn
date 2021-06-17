#include<stdio.h>
#include<stdlib.h>

int main() {

    float a, b, c;
    
    printf("Enter the first value: ");
    scanf("%f", &a);
    printf("Enter the socond value: ");
    scanf("%f", &b);
    printf("Enter the third value: ");
    scanf("%f", &c);

    if (a < b+c && b < a+c && c < b+a){
        if(a==b && b==c){
            printf("Este triangulo é equilátero");
        }else{
            if(a==b ||a==c || b==c ){
                printf("Esse triangulo é isóceles. ");
        }else{
            printf("Este triangulo pe escaleno");
            }
        }
    }
}
