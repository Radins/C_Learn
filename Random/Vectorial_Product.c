#include <stdio.h>
#include <stdlib.h>
#define V 3
int main(){
    float vect_1[V], vect_2[V], vect_ans[V];
    int i=0, a=0, b=0;

    for(i=0;i<=2; i++){
        printf("Enter the %i° value of the first vetor: ", i+1);
        scanf("%f", &vect_1[i]);
    }
    printf("---------------------------------------------\n");
    for(i=0;i<=2; i++){
        printf("Enter the %i° value of the second vetor: ", i+1);
        scanf("%f", &vect_2[i]);
    }
    for(i=0;i<=2; i++){
        a = 1+i;
        if(a==3){
            a=0;
        }
        b = a+1;

        if(b>=3){
            b=0;
        }
        vect_ans[i] = (vect_1[a]*vect_2[b]) - (vect_1[b]*vect_2[a]);
    }
    printf("---------------------------------------------\n");
    printf("Vector[");
    for(i=0;i<=2;i++){
        printf("%.2f, ", vect_ans[i]);
    }
    printf("]");
}