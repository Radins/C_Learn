#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *creat_vector(int size){
    int *vector;
    
    vector=(int *) malloc(size*sizeof(int));
    if(vector==NULL){
        printf("Error creating the vector");
        return NULL;
    }

    return vector;
}

void randon_vector(int *vector, int size){
    srand(time(NULL));

    for(int i=0; i<size; i++){
        vector[i]=rand()%15;
    }
}

void print_vector(int *vector, int size){

    for(int i=0; i<size; i++){
        printf("%3i", vector[i]);
    }
    printf("\n");
}

int save_vector(int *vector, int size){
    FILE *fp;
    fp=fopen("vector.txt", "w");

    if(fp==NULL){
        return -1;
    }
    fwrite(vector, size*sizeof(int), 1, fp);
    fclose(fp);
    return 0;
}

void *chage_vector(size){
    FILE *fp;
    int *vector;
    vector=creat_vector(size);
    if(vector==NULL)
        return NULL;
    
    fp = fopen("vector.txt", "r");
    if(fp==NULL)
        return 0;

    fread(vector,size*sizeof(int), 1, fp);
    fclose(fp);
    return vector;
}

int main(){
    int *vect, n;

    printf("Enter the size of the vector: ");
    scanf("%i", &n);

    vect = creat_vector(n);
    randon_vector(vect, n);

    print_vector(vect, n);

    save_vector(vect, n);
    vect = chage_vector(n);
    print_vector(vect, n);
}