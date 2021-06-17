#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *creats_vector(int tam);

void random_vector(int *vector, int size);

int main(){
    srand(time(NULL));

    int size, bits_allocated, first_fit=-1,best_fit=-1,count=0,n,i;
    int *vector;

    printf("Enter the vector size: ");
    scanf("%i", &size);

    vector = creats_vector(size);
    random_vector(vector, size);

    printf("Your vector is:\n");
    for(int i=0; i<size; i++)
        printf(" %i ", vector[i]);

    printf("\n\nInform the amount of bits that need to be allocated: ");
    scanf("%i", &bits_allocated);

    //find the first fit
    for(int i=0; i<size; i++){
        if(vector[i]==0){
            if(count==0)
                first_fit=i;
            count++;
        }else{
            if(count>=bits_allocated)
                break;
            count=0;
        }

        if(i>=size-bits_allocated){
            first_fit = -1;
            break;
        }
    }

    //find the best fit
    if(first_fit!=-1){
        n=bits_allocated-1;
        do{
            count=0;
            n++;
            for(i=0; i<size; i++){
                if(vector[i]==0){
                    if(count==0)
                        best_fit=i;
                    count++;
                }else{
                    if(count==n)
                        break;
                    count=0;
                    best_fit=-1;
                }
            }
        }while(best_fit==-1);
    }
    //print the first fit
    if(first_fit==-1)
        printf("There is no space to allocathe these bits...\n");
    else
        printf("The first fit is in the %i° position.\n", (first_fit+1));

    //print the best fit
    if(best_fit==-1)
        printf("There is no best fit...");
    else
        printf("The best fit is on the %i° position.\n", (best_fit+1));
    
}
//creates the vector
int *creats_vector(int tam){
    int *vec_size;
    vec_size = (int *) malloc(tam*sizeof(int));

    if(vec_size == NULL){
        printf("FATAL ERROR\n");
        exit(-1);
    }
    return vec_size;
}
//randomly fills the vector with 0 and 1
void random_vector(int *vector, int size){
    for(int i=0; i<size; i++)
        vector[i] = rand()%2;
}