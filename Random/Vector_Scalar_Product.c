#include <stdio.h>
#include <stdlib.h>


int main(){
    int n, i, a, b;
    float vect_1[n], vect_2[n], product=0;
//-----------------------------------------------------------------------------
    printf("Enter the size of the vector: ");
    scanf("%i", &n);

    for(i=0; i<n; i++){
        printf("Enter the %i° value of the firs vector: ", i+1);    // Read the vectors
        scanf("%f", &vect_1[i]);
    }
    for(i=0; i<n; i++){
        printf("Enter the %i° value of the second vector: ", i+1);
        scanf("%f", &vect_2[i]);
    }
//------------------------------------------------------------------------------
    for(i=0; i<n; i++){
        a = vect_1[i];
        b = vect_2[i];
        product = product + (a*b);
    }

    printf("The scalar product between these two vectors is: %.2f\n", product);
}