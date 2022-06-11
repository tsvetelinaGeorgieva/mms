#include<stdio.h>

int sum(int*, int);
void arrayEvaluate(int*, size_t, int(*)(int*, int));


int main(){
    int arr[] = {1, 3, 2};
   
    arrayEvaluate(arr, 3, sum);

    return 0;
}

int sum(int* arr, int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }
    return sum;
}

void arrayEvaluate(int* arr, size_t n, int(*f)(int*, int)){
    printf("Value: %d\n",(*f)(arr, n));
}