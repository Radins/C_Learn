#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    float num_start, common_diff;
    int position, repeat = 1;
    char want_repeat[] = "yes";
    char str_yes[] = "yes";
    
    printf("Enter the initial term of the arithmetic progression: ");
    scanf("%f", &num_start);
    printf("Now, enter the common difference of the arithmetic progression: ");
    scanf("%f", &common_diff);
    
    while (repeat == 1 ){
        printf("Enter the position that you want to know: ");
        scanf("%i", &position);
        float value;
        value = num_start + (position - 1)*common_diff;
        printf("The value of te %iº position is %f \n", position, value);  
        printf("Do you want to know any more value of this arithmetic progression? \n");
        scanf("%s", &str_yes);
        repeat = strcmp(str_yes, want_repeat);  // compare both values, if they are equal(yes) then repeat = 0, else repeat = an int value
    }
}