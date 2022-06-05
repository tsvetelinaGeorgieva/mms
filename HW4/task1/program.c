#include<stdio.h>
void swap(int*, int*);
//gcc -E program.c -o program.i
//gcc -S program.i -o program.s
//gcc -c program.s -o program.o
//gcc -E swap.c -o swap.i
//gcc -S swap.i -o swap.s
//gcc -c swap.s -o swap.o
//gcc program.o swap.o -o program


int main(){
    int num1, num2;
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);
    printf("Before swap: Num1 = %d, Num2 = %d\n", num1, num2);
    swap(&num1, &num2);
    printf("After swap: Num1 = %d, Num2 = %d\n", num1, num2);

    return 0;
}