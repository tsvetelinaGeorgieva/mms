#include<stdio.h>
#include<stdint.h>

#define TINT 1
#define TCHAR 2
#define TDOUBLE 3
#define TFLOAT 4
#define TUINT_8_T 5
#define TUINT_16_T 6
#define TUINT_32_T 7
#define TUINT_64_T 8

void printValue(const void*, uint8_t);

int main(){
    int num = 23;
    printValue(&num, TINT);

    char sym = 't';
    printValue(&sym, TCHAR);

    double doubleNum = 19.19;
    printValue(&doubleNum, TDOUBLE);

    float floatNum = 19.123;
    printValue(&floatNum, TFLOAT);

    uint8_t num8 = 111;
    printValue(&num8, TUINT_8_T);


    uint16_t num16 = 11100;
    printValue(&num16, TUINT_16_T);

    uint32_t num32 = 342;
    printValue(&num32, TUINT_32_T);

    uint64_t num64 = 900011;
    printValue(&num64, TUINT_64_T);


    return 0;
}

void printValue(const void* valuePrt, uint8_t flag){
    switch(flag){
        case 1: 
            printf("Value = %d\n", *(int*)valuePrt);
            break;
        case 2: 
            printf("Value = %c\n", *(char*)valuePrt);
            break;
        case 3: 
            printf("Value = %.2lf\n", *(double*)valuePrt);
            break;
        case 4:
            printf("Value = %.3f\n", *(float*)valuePrt);
            break;
        case 5: 
            printf("Value = %u\n", *(uint8_t*)valuePrt);
            break;
        case 6: 
            printf("Value = %u\n", *(uint16_t*)valuePrt);
            break;
        case 7: 
            printf("Value = %u\n", *(uint32_t*)valuePrt);
            break;
        case 8: 
            printf("Value = %lu\n", *(uint64_t*)valuePrt);
            break;
        
    }

}