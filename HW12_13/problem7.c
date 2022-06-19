#include<stdio.h>

unsigned int BinSearch(unsigned int*, unsigned int, unsigned int);

int main(){
    unsigned int arr[] = {1, 2, 3, 4, 5, 6, 7};
    unsigned int len = 7;
    if(BinSearch(arr, len, 5) == -1){
        fprintf(stderr, "This element not found!\n");
    }else{
        printf("Index of 5 is: %d\n", BinSearch(arr, len, 5));
    }


    return 0;
}

unsigned int BinSearch(unsigned int* pArray, unsigned int uArraySize, unsigned int uValue){
    for(int i = 0; i < uArraySize; i++){
        if(pArray[i] == uValue){
            return i+1;
        }
    }
    return -1;
}