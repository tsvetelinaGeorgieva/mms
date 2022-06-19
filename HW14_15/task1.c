#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>

#define COUNT 3
int randInt(int, int);
double randReal(double, double);
void randomName(char*);

typedef struct Book{
    char title[151];
    char author[101];
    int pages;
    double price;
} Book;


int main(){
    srand(time(NULL));
    Book books[COUNT];
    for(int i = 0; i < COUNT; i++){
        randomName(books[i].title);
        randomName(books[i].author);
        books[i].pages = randInt(5, 2000);
        books[i].price = randReal(1.00, 1000.00);
    }

    char fileName[50];
    printf("Enter the name of file: ");
    scanf("%s", fileName);

    FILE* fp;
    fp = fopen(fileName, "wb");
    if(fp == NULL){
        fprintf(stderr,"Write error.\n");
    }

    for(int i = 0; i < COUNT; i++){
        fwrite(&books[i], sizeof(books[i]), 1, fp);
    }    
    fclose(fp);
    return 0;
}

int randInt(int min, int max){
    return min + (rand()% (max + 1 - min)); 
}

double randReal(double min, double max){
    return min + ((double)rand() / RAND_MAX) * (max - min);
}

void randomName(char* name){
    int len = randInt(10, 20);
    name[0] = randInt('A', 'Z');
    for(int i = 1; i < len; i++){
        name[i] = randInt('a', 'z');
    }
    name[len] = '\0';
}