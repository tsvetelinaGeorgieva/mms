#include<stdio.h>

void map(int*, size_t, int(*)(int));
int pl1(int);

int main(){
    int array[] = {1,2,3};
    map(array, 3, pl1);
    for(int i = 0;  i< 3; i++){
        printf("%d ", array[i]);
    }
    return 0;
}

void map(int* array, size_t n, int(*func)(int)){
    for(int i = 0; i < n; i++){
        array[i] = (*func)(array[i]);
    }
}

int pl1(int n){
    return n+1;
}