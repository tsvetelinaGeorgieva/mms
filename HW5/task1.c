#include<stdio.h>

int main(){
    float num1, num2, op;
    char sym;
    
    while(scanf("%f %c %f", &num1, &sym, &num2) != EOF){
        switch(sym){
            case '+':
                op = num1 + num2;
                printf("%.2f\n", op);
                break;
            case '-':
                op = num1 - num2;
                printf("%.2f\n", op);
                break;
            case 'x':
                op = num1 * num2;
                printf("%.2f\n", op);
                break;
            case '/':
                op = num1 / num2;
                printf("%.2f\n", op);
                break;
                default:
                    fprintf(stderr,"Invalid input!\n");

        }
    }

    return 0;
}