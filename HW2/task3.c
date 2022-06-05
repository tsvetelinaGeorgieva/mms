#include<stdio.h>
#include<limits.h>

int main(){
    double number;
    double max = INT_MIN;
    double min = INT_MAX;

    while(scanf("%lf", &number) != EOF){
        if(min > number){
            min = number;
        }

        if(max < number){
            max = number;
        }
    }

    printf("Max: %.2lf\nMin: %.2lf\n", max, min);

    return 0;
}