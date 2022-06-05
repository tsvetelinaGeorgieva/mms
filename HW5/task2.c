#include<stdio.h>
#include<math.h>

int triangle(double, double, double, double*, double*);

int main(){
    double a, b, c, S, P;

    while(scanf("%lf %lf %lf", &a, &b, &c) != EOF){
        if(triangle(a,b,c, &S, &P) == 0){
            printf("S = %.2lf\n", S);
            printf("P = %.2lf\n", P);
        }else{
            printf("Invalid triangle sides!\n");
        }
    }

    return 0;
}




int triangle(double a, double b, double c, double* S, double* P){
    if(a <= 0 || b <= 0 || c <= 0){
        return -1;
    }else{
        *P = a + b + c;
        double p = *P / 2;
        *S = sqrt(p*(p - a) * (p - b) * (p - c));
        return 0;
    }
}