#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char **creat_played_board(int i, int j){
    char **board;
    int n;
    board = (char **) malloc(i*sizeof(char *));
    if(board==NULL){
        printf("Erro ao criar tabuleiro!\n");
        return NULL;
    }

    for(n=0; n<j; n++){
        board[n] = (char *) malloc(j*sizeof(char));
        if(board[n]==NULL){
            printf("Erro ao criar as linhas do tabuleiro!");
            return NULL;
        }
    }

    for(int k=0; k<i; k++){
        for(int l=0; l<j; l++){
            board[k][l] = '_';
        }
    }
    return board;
}


int write_file(char **array, int i, int j){
    FILE *fp;
    
    fp = fopen("data_1.tex", "a");
    if(fp==NULL){
        printf("Error opening the file to write\n");
        return -1;
    }
    for(int k=0; k<i; k++){
        for(int l=0; l<j; l++){
            fprintf(fp, " %c ", array[l][k]);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);

    return 0;

    
}
//-------------------------------------//
void read_file(int i, int j){

    FILE *fp;
    char spot;

    fp = fopen("data_1.tex", "rb");
    if(fp==NULL){
        printf("Error opening the file to read\n");
        exit(-2);
    }

    /*while(!feof(fp)){
        fscanf(fp, "%c", &spot);
        printf("%c", spot);

            
    }*/

   while(!feof(fp)){
        
        fgets(&spot, 4, fp);
        printf("%c", spot);
            
    }
    fclose(fp);

}

//-------------------------------------//
int main(){

    //srand(time(0));
    
    char **array;
    int i=4,
        j=4,
        control;

    array = creat_played_board(i, j);
    control = write_file(array, i, j);
    read_file(i, j);

    /*for(int k=0; k<4; k++){
        for(int l=0; l<4; l++){
            printf(" %c ", array[l][k]);
        }
        printf("\n");
    }*/


}