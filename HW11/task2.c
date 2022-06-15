#include<stdio.h>
#include<time.h>
#include<limits.h>
#include<stdlib.h>

double randDouble(double, double);

int main(){
    srand(time(NULL));
    int n;
    scanf("%d", &n);

    double* arr = malloc(sizeof(double) * n);
    if(arr == NULL){
        fprintf(stderr, "Malloc error!\n");
        return EXIT_FAILURE;
    }

    for(int i = 0; i < n; i++){
        arr[i] = randDouble(0.0, 1.0);
    }

    for(int i = 0; i < n; i++){
        printf("%.2lf ", arr[i]);
    }
    putchar('\n');
    int m;
    scanf("%d", &m);
    arr = realloc(arr, sizeof(double) * (m + n));
    if(arr == NULL){
        fprintf(stderr, "Realloc error!\n");
        return EXIT_FAILURE;
    }
    for(int i = n; i < (n + m); i++){
        arr[i] = randDouble(1.0, 2.0);
    }
    

    for(int i = 0; i < (n + m); i++){
        printf("%.2lf ", arr[i]);
    }
     putchar('\n');

    int p;
    scanf("%d", &p);
    arr = realloc(arr, sizeof(double) * (n + m + p));
    if(arr == NULL){
        fprintf(stderr, "Realloc error!\n");
        return EXIT_FAILURE;
    }
    for(int i = (n + m); i < (n + m + p); i++){
        arr[i] = randDouble(2.0, 3.0);
    }  
    for(int i = 0; i < (n + m + p); i++){
        printf("%.2lf ", arr[i]);
    }
     putchar('\n');


    free(arr);
    return 0;
}

double randDouble(double min, double max){
    return min + ((double)rand() / RAND_MAX) * (max - min);
}