#include<stdio.h>

int rectangle(double, double, double*, double*);

int main(){
    double a, b, S, P;

    while(scanf("%lf %lf", &a, &b) != EOF){
        if(rectangle(a, b, &S, &P) == 0){
            printf("S = %.2lf\n", S);
            printf("P = %.2lf\n", P);
        }else{
            printf("Invalid rectangle sizes!\n");
        }
    }

    return 0;
}

int rectangle(double w, double h, double* S, double* P){
    if(w > 0 && h > 0){
        *S = w * h;
        *P = 2 * (w + h);
        return 0;
    }else{
        return -1;
    }
}