#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **creat_matrix(int size_i, int size_j){
    int **matrix, i;

    matrix=(int **) malloc(size_i*sizeof(int *));
    if( matrix == NULL){
        printf("Error creating matrix\n");
        return NULL;
    }

    for(i=0; i<size_j; i++){
        matrix[i] = (int *) malloc(size_j*sizeof(int));
        if(matrix[i]==NULL){
            printf("Error creating the lines");
            return NULL;
        }
    }
    return matrix;
}

void show_matrix(int **X, int size_i, int size_j){
    int i,j;

    for(i=0;i<size_i;i++){
        for(j=0;j<size_j;j++)
            printf(" %3i ", X[i][j]);
        printf("\n");
    }
}

void start_matrix(int **X, int size_i, int size_j){
    int i,j;
    srand(time(NULL));

    for(i=0;i<size_i;i++){
        for(j=0;j<size_j;j++)
        X[i][j]=rand()%15;
    }
}

int save(int **X, int size_i, int size_j){
    FILE *fp;
    fp=fopen("matrix.txt", "wb");
    
    if(fp==NULL){
        return -1;
    }
    fwrite(X, size_i*size_j*sizeof(int), 1, fp);
    fclose(fp);
    return 0;
}

void **charge(size_i, size_j){
    FILE *fp;
    int **X;
    X=creat_matrix(size_i,size_j);
    if(X==NULL)
        return NULL;
    fp = fopen("matrix.txt", "rb");
    if(fp==NULL)
        return NULL;

    fread(X, size_i*size_j*sizeof(int), 1, fp);
    fclose(fp);
    return X;
}

int main(){

    int **matrix_a, i, j, ret;

    printf("Enter the matriz size: ");
    scanf("%i %i", &i, &j);
    matrix_a = creat_matrix(i,j);
    if(matrix_a==NULL){
        printf("Memory error\n");
        return -1;
    }

    start_matrix(matrix_a, i, j);
    show_matrix(matrix_a, i, j);

    ret = save(matrix_a, i, j);
    if(ret == -1){
        printf("Error saving the matrix");
        return -2;
    }

    printf("\n\n");
    
    matrix_a=charge(i, j);
    show_matrix(matrix_a, i, j);

    return 0;
}