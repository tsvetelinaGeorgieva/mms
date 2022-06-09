#include<stdio.h>
#include<limits.h>


int secondMax(const int* arr, size_t n, int* secondMax);


int main(){
    int arr[] = {5,7,90};
    int secMax;
    
    if(secondMax(arr, 3, &secMax) == -1){
        fprintf(stderr,"Invalid input!\n");
    }else{
        printf("Second max: %d\n", secMax);
    }
    return 0;
}


int secondMax(const int* arr, size_t n, int* secondMax){
    int max = INT_MIN;
    int secMax = INT_MIN;

    if(n == 1 || n == 0){
        return -1;
    }

    for(int i = 0; i < n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }

    for(int i = 0; i < n; i++){
        if(arr[i] > secMax && arr[i] != max){
            secMax = arr[i];
        }
    }
    
    
    if(secMax != INT_MIN){
        *secondMax = secMax;
        return 0;
    }else{
        return -1;
    }
}
