#include<stdio.h>
#include<stdarg.h>

unsigned bitsNCount(unsigned count, unsigned bitscnt, ...);

int main(){
    printf("%u\n", bitsNCount(1, 1, 4));
    printf("%u\n", bitsNCount(2, 2, 30, 100));
    printf("%u\n", bitsNCount(3, 3, 0, 5, 6));
    return 0;
}

unsigned bitsNCount(unsigned count, unsigned bitscnt, ...){
    unsigned countMask = 0;
    unsigned countOne = 0;
    va_list argl;
    va_start(argl, bitscnt);
    for(int i = 0; i < count; i++){
        for(int bit = 0; bit < sizeof(va_arg(argl, unsigned)) * 4; bit++){
            if(!!(va_arg(argl, unsigned) & (1<<bit))){
                countOne++; 
            }
        }
        if(countOne == bitscnt){
            countMask++;
        }
        countOne = 0;
    }    
    va_end(argl);

    return countMask;
}