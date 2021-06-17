#include <stdio.h>
#include <stdlib.h>

int main(){

    int i, j, N, ans, a;
    
    printf("Enter the size of the matrix: ");
    scanf("%i", &N);

    int matr_1[N][N], matr_2[N][N], matr_mult[N][N];

    // read both the matrix values
    printf("First matrix: \n");
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            printf("Enter the value in the %i° line, %i° column: ", i+1, j+1);
            scanf("%i", &matr_1[i][j]);
        }
    }
    printf("Second matrix: \n");
    for(i=0; i<N; i++)
        for(j=0; j<N; j++){
            printf("Enter the value in the %i° line, %i° column: ", i+1, j+1);
            scanf("%i", &matr_2[i][j]);
        }
    // end the read

    // multiplies both matrices
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            ans=0;
            for(a=0; a<N; a++)
                ans = matr_1[i][a]*matr_2[a][j] + ans;
            
            matr_mult[i][j] = ans;
        }
    }
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            printf("%i \t", matr_mult[i][j]);
        }
    printf("\n");
    }
}