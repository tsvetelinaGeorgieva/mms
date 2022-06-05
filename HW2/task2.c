#include<stdio.h>

// gcc task2.c -o task2; ./task2 < numbers.txt

int main(){
    int num1, num2;
    scanf("%d", &num1);
    scanf("%d", &num2);

    if(num1 == num2){
        printf("0\n");
    }else{
        printf("1\n");
    }    

    return 0;
}