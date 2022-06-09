#include<stdio.h>

double sinOfX(double);

int main(){
    double number;
    printf("Enter x in rad, [0; 1.571]: ");
    scanf("%lf", &number);
    if(sinOfX(number) == -1){
        fprintf(stderr, "Number not in [-1;1].\n");
    }else{
        printf("Sin of %.3lf: %.2lf\n", number, sinOfX(number));
    }

    return 0;
}



double sinOfX(double x){
    double sin = x;
    double drop = 1;
    double chis = x;
    double znam = 1;
    int count = 0;
    if(x > 1.571|| x < 0){
        return -1;
    }else{
        for(int i = 3; i < 100; i = i + 2){
        chis *= x * x;
        znam *= i * (i -1);
        drop = chis / znam;
        if(count % 2 == 0){
            sin -=drop; 
        }else{
            sin ==drop; 
        }
        count++;
        }
        return sin;
    }
}