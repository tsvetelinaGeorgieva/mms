#include<stdio.h>

unsigned sumArrayDigits(const int*, size_t);

int main(){
    int arr[] = {101, 3, 563, 678, 1, 0};
    printf("Sum: %u\n", sumArrayDigits(arr, 6));

    return 0;
}

unsigned sumArrayDigits(const int* arr, size_t n){
    int sum = 0;
    int num = 0;
    
    for(int i =0; i < n; i++){
        num = arr[i];
        while(num != 0){
            sum += num%10;
            num /=10;
        }
    }

    return sum;
}