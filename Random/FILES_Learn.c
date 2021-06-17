#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int write_file(){
    FILE *fp;
    int cod, cont=0;
    /*char a[]="ascv";
    char b[]="321";
    strncat(b, a, 4);
    */
    float note;

    fp = fopen("Files_learn.txt", "a");
    if(fp==NULL){
        printf("Error opening the file to write\n");
        return -1;
    }

    printf("Code: ");
    scanf("%i", &cod);
    while(cod>=0){
        printf("Note: ");
        scanf("%f", &note);
        fprintf(fp, "%i %f\n", cod, note);
        cont++;
        printf("Code: ");
        scanf("%i", &cod);
    }
    fclose(fp);
    return cont;
}

void show_file(){
    FILE *fp;
    int cod;
    float note;
    fp = fopen("Files_learn.txt", "r");
    if(fp==NULL){
        printf("Error opening the file to read.\n");
        exit(-2);
    }

    while(!feof(fp)){
        fscanf(fp, "%d %f\n", &cod, &note);
        printf("Code: %i / Note: %.1f\n", cod, note);
    }
    fclose(fp);
}

int main(){
    int r;

    r = write_file();
    if(r==-1 || r==-2){
        printf("Erro %i\n", r);
    }else{
        printf("Reading %i inputs\n", r);
        show_file();
    }
    return 0;
}