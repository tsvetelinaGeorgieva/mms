#include<stdio.h>
#include<math.h>

int DecTo(int, int);
int toDec(int, int);

int main(){
    int number, base1, base2, num;
    scanf("%d", &number);
    scanf("%d", &base1);
    scanf("%d", &base2);

    if(base1 >= 2 && base1 <= 36 && base2 >=2 && base2 <=36){
        if(base1 == 10){
            num = DecTo(number, base2);
            printf("Number: %d\n", num);
        }else if(base2 == 10){
            num = toDec(number, base1);
            printf("Number: %d\n", num);
        }else{
            num = toDec(number, base1);
            num = DecTo(number, base2);
            printf("Number: %d\n", num);
        }
    }else{
        printf("Invalid base!\n");
    }

    return 0;
}


int DecTo(int number, int base){
    int numberNew = 0;
    int ost = 0;
    int count = 0;

    while(number != 0){
        ost = number % base;
        numberNew = numberNew + ost * pow(10, count);
        number /= 10;
        count ++;
    }

    return numberNew;
}


int toDec(int number, int base){
    int newNumber;
    int digit = 0;
    int count = 0;

    while(number != 0){
        digit = number % 10;
        newNumber = newNumber + digit * pow(base, count);
        number /= 10;
        count++;
    }

    return newNumber;
}

