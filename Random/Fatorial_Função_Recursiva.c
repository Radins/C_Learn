#include <stdio.h>
#include <stdlib.h>

int fat(int num){
    
    if(num == 0){
        return 1;
    }else{
        return num*fat(num-1);
    }
}
int main(){
    int n;

    printf("Enter a number: ");
    scanf("%i", &n);

    printf("%i \n", fat(n));

}