#include<stdio.h>

void Bubble(int*, unsigned int);

int main(){
    int arr[] = {4, 7, 3, 45, 6, 8, 12};
    unsigned int len = 7;
    printf("Before: ");
    for(int i = 0; i < len; i++){
        printf("%d ", arr[i]);
    }

    Bubble(arr, len);
    printf("After: ");
    for(int i = 0; i < len; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}

void Bubble(int *pArray, unsigned int uLen){
    int flag = 1;
    int temp;
    while(flag != 0){
        flag = 0;
        for(int i = 1; i < uLen; i++){
            if(pArray[i - 1] > pArray[i]){
                temp = pArray[i - 1];
                pArray[i - 1] = pArray[i];
                pArray[i] = temp;
                flag++;
            }
        }
    }
}