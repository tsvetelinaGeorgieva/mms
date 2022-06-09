#include<stdio.h>

int sqrtOfNumber(int);

int main(){
    int number;
    scanf("%d", &number);

    if(sqrtOfNumber(number) == -1){
        fprintf(stderr, "Invalid num.\n");
    }else{
        printf("Sqrt of %d is %d.\n", number, sqrtOfNumber(number));
    }

    return 0;
}

int sqrtOfNumber(int number){
    int num;
    if(number == 1){
        num = 1;
        return num;
    }
    for(int i = 2; i <= (number/2); i++){
        if((i * i) == number){
            num = i;
            return i;
        }
    }

    return -1;
}

