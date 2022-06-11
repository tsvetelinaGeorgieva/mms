#include<stdio.h>

int binarySearch(int*, size_t, int);

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    if(binarySearch(arr, 5, 7) == -1){
        printf("Not found!\n");
    }else{
        printf("Index is: %d\n", binarySearch(arr, 5, 7));
    }
    return 0;
}

int binarySearch(int* array, size_t n, int key){
    for(int i = 0; i < n; i++){
        if(array[i] == key){
            return i;
        }
    }

    return -1;
}