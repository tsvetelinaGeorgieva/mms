#include<stdio.h>
#include<math.h>

int quadEq(double, double, double, double*, double*);

int main(){
    double a, b, c, S, P;
    while(scanf("%lf %lf %lf", &a, &b, &c) != EOF){
        if(quadEq(a, b, c, &S, &P) == 0){
            printf("x1 = %.2lf\n", S);
            printf("x2 = %.2lf\n", P);            

        }else{
            printf("No real roots!\n");
        }
    }

    return 0;
}

int quadEq(double a, double b, double c, double* S, double* P){
    if(pow(b, 2) < (4 * a * c)){
        return -1;
    }else{
        b *= -1;
        *S = (b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
        *P = (b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
        return 0;
    }

}