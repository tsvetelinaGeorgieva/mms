#include<stdio.h>
#include<stdint.h>
#include<math.h>

void swapBytes(uint16_t*);
int16_t printbit(int16_t);

int main(){
    uint16_t num;
    //uint16_t* p;
    //p = &num;
    scanf("%hu", &num);
    printf("%hu\n", printbit(num));
    swapBytes(&num);
    printf("%hu\n", num);
    printf("%hu\n", printbit(num));

    return 0;
}

void swapBytes(uint16_t* word){
    int lastBit = !!(*word & (1 << 0));
    int firstBit, index;

    for(int bit = sizeof(* word) * __CHAR_BIT__ - 1; bit >= 0; bit--){
        if(!!(*word & (1 << bit))){
            firstBit = !!(*word & (1 << bit));
            index = bit;
            break;
        }
    }
    
    if(lastBit != firstBit){
        *word ^= (1 << 0);
        //*word ^= (1 << (sizeof(*word) * __CHAR_BIT__ - index));
    }
}

int16_t printbit(int16_t mask){
    int16_t num;
    for(size_t bit = 0; bit < sizeof(uint16_t) * __CHAR_BIT__; bit++){
        num += (!!(mask & (1 << bit))) * pow(10,bit); 
    }
    return num;
}