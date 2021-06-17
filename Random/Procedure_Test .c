#include<stdio.h>
#include<stdlib.h>

void test(int x, int *y){
    *y = x;
    printf("%i \n", x);
}

int main(){
    int a,b;
    a =3;
    test(a,&b);
    printf("%i \n", b);
}