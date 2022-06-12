#include<stdio.h>
#include<stdint.h>
#include<math.h>

int32_t printbit(int32_t);

int main(){
    int32_t num;
    scanf("%u", &num);
    printf("%u", printbit(num));
    return 0;
}

int32_t printbit(int32_t mask){
    int32_t num;
    for(size_t bit = 0; bit < sizeof(uint32_t) * __CHAR_BIT__; bit++){
        num += (!!(mask & (1U << bit))) * pow(10,bit); 
    }
    return num;
}