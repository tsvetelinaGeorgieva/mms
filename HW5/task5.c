#include<stdio.h>
#include<stdint.h>

unsigned onesCount(uint64_t mask);

int main(){
    uint64_t mask;
    scanf("%ld", &mask);
    //printf("%ld\n", mask);
    printf("Count of 1: %d\n", onesCount(mask));

    return 0;
}

unsigned onesCount(uint64_t mask){
    int count = 0;
    for(int bit = 0; bit < sizeof(mask); bit++){
        if(!!(mask & (1 << bit))){
        count++;
        }
    }
    return count;
}

