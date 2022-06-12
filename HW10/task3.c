#include<stdio.h>
#include<stdint.h>

int clearBit(uint32_t*, size_t, size_t);
int setBit(uint32_t*, size_t, size_t);
int checkBit(uint32_t, size_t, size_t);

int main(){
    uint32_t maskArr[] = {32, 5, 9};
    //setBit(maskArr, 3, 2);
    //clearBit(maskArr, 3, 0);
    for(int i = 0; i < 3; i++){
        printf("%u ", maskArr[i]);
    }

    if(checkBit(maskArr[1], 3, 2) == -1){
        fprintf(stderr, "Invalid len.\n");
    }else{
        printf("\n%d\n", checkBit(maskArr[1], 3, 2));
    }

    return 0;
}

int clearBit(uint32_t* maskArr, size_t nitems, size_t bit){
    for(int i = 0; i < nitems; i++){
        if(sizeof(maskArr[i]) < bit){
            return -1;
        }else{
            *(maskArr + i) &= ~(1U << bit);
        }        
    }
    return 0;
}


int setBit(uint32_t* maskArr, size_t nitems, size_t bit){
    for(int i = 0; i < nitems; i++){
        if(sizeof(maskArr[i]) < bit){
            return -1;
        }else{
            *(maskArr + i) |= (1U << bit);
        }
    }
    return 0;
}

int checkBit(uint32_t maskArr, size_t len, size_t bit){
    if(len < bit){
        return -1;
    }
    if(!!(maskArr & (1U << bit))){
        return 1;
    }else{
         return 0;
    }
}