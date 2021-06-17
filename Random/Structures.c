#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 3

struct TEST{

    bool approved_disapproved;
    char name[25];
    float test_1, test_2, average;

} student[N];

int main(){
    int i;
    char passed[10];

    for(i=0; i<N; i++){
        printf("Enter the student's name: ");
        scanf("%s", &student[i].name);
        printf("Enter the grade of the first test of the %iº student: ", (i+1));
        scanf("%f", &student[i].test_1);
        printf("Enter the grade of the second test of the %iº student: ", (i+1));
        scanf("%f", &student[i].test_2);

        student[i].average = (student[i].test_1 + student[i].test_2)/2;
        if(student[i].average<7){
            student[i].approved_disapproved = false;
        }else{
            student[i].approved_disapproved = true;
        }
    }
    for(i=0; i<N; i++){
        if(student[i].approved_disapproved == false){
            printf("%s hasn't passed the year, it's average is: %.2f\n",  student[i].name, student[i].average);
        }else{
            printf("%s has passed the year, it's average is: %.2f\n",  student[i].name, student[i].average);
        }
        
    }
    return 0;
}