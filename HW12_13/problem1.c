#include<stdio.h>

unsigned char CheckBit(unsigned int);

int main(){
    unsigned int a = 0x0400;
    printf("%x \n", CheckBit(a));
    return 0;
}

unsigned char CheckBit(unsigned int uValue){
    int count = 0;

    for(int i = 0; i < 15; i++){
        if(!!(uValue & (1 << i))){
            count++;
        }
    }
    
    if(count == 1){
        return 1;
    }else{
        return 0;
    }
}