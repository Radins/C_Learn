#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    float num_start, common_ratio;
    float position, repeat = 1;
    char want_repeat[] = "yes";
    char str_yes[] = "yes";

    printf("Enter the initial term of the geometric progression: ");
    scanf("%f", &num_start);
    printf("Now, enter the common ratio of the geometric progression: ");
    scanf("%f", &common_ratio);

    while (repeat == 1 ){
        printf("Enter the position that you want to know: ");
        scanf("%i", &position);
        float value;
        value = pow( position, common_ratio);
        printf("The value of te %iº position is %f \n", position, value);
        printf("Do you want to know any more value of this arithmetic progression? \n");
        scanf("%s", &want_repeat);
        repeat = strcmp(str_yes, want_repeat);  // compare both values, if they are equal(yes) then repeat = 0, else repeat = an int value
    }
}
