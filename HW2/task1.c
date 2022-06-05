#include<stdio.h>

// gcc task1.c -o task1; ./task1 <numbers.txt

int main(){
    double number, min;
    //printf("Enter number: \n");
    scanf("%lf", &number);
    min = number;

    for(int i = 0; i < 2; i++){
        //printf("Enter number: \n");
        scanf("%lf", &number);
        if(min > number){
            min = number;
        }
    }

    printf("Min: %.1lf\n", min);


    return 0;
}