#include <stdio.h>
#include <stdlib.h>

int main(){
    float v1, v2, v3, biggest_v = v1;
    printf("Enter the first value: ");
    scanf("%f", &v1);
    printf("Enter the second value: ");
    scanf("%f", &v2);
    printf("Enter the third value: ");
    scanf("%f", &v3);
    if(biggest_v < v2){
        biggest_v = v2;
    }
    if(biggest_v < v3){
        biggest_v = v3;
    }
  printf("The biggest value is: %f", biggest_v);
}
