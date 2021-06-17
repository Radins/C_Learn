
#include <stdio.h>
#include <stdlib.h>

int main(){
    int nxter, pos, n1=0, n2=1, i=1;

    scanf("%i", &pos);

    while(i <= pos){
        nxter = n1 + n2;
        n1 = n2;
        n2 = nxter;
        i++;

        printf("%i  ", n1);
    }
    //printf("%i", n1);
}