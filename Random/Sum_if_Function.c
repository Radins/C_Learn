#include <stdio.h>
#include <stdlib.h>


int test(int *a, int *b){
  int j;
  j = *a + *b;
  *a = *b;
  return j;
}
int main(){
  
  int x,y;

  printf("Enter a number: ");
  scanf("%i", &x);
  printf("Enter another number: ");
  scanf("%i", &y);

  printf("The sum is: %i\n", test(&x,&y));
  printf("%i\n", x);
  
}