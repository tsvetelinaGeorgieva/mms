#include<stdio.h>
#include<limits.h>
//MAX :gcc task3_1.c -o task; ./task < numbers.txt | cat numbers.txt | sort -n | tail -n 1
//MIN :gcc task3_1.c -o task; ./task < numbers.txt | cat numbers.txt | sort -n | head -n 1

int main(){
    double number;
    double max = INT_MIN;
    double min = INT_MAX;

    while(scanf("%lf", &number) != EOF){
        
    }

    printf("Max: %.2lf\nMin: %.2lf\n", max, min);

    return 0;
}