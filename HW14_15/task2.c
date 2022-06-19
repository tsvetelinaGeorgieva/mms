#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>
#include<string.h>

#define COUNT 3

void push(Booklist**, char*, char*, int*, double*);
void print_list(Booklist*);
void listFree(Booklist**);
int compTitle(const void*, const void*);
void frontBackSplit(Booklist*, Booklist**, Booklist**);
void mergeSort(Booklist**, int(*)(const void* , const void*));

typedef struct Book{
    char title[151];
    char author[101];
    int pages;
    double price
} Book;

typedef struct Booklist{
    char title[151];
    char author[101];
    int pages;
    double price;
    struct Booklist* next
} Booklist;


int main(){
    char fileName[50];
    printf("Name of file (r): ");
    scanf("%s", fileName);
    FILE *fp1;
    fp1 = fopen(fileName, "rb");
    if(fp1 == NULL){
        fprintf(stderr, "Read error.\n");
    }
    Book bookRead[COUNT];
    Booklist *list = NULL;
    //if(fp1 != EOF){
        for(int i = 0; i < COUNT; i++){
            fread(&bookRead[i], sizeof(bookRead[i]), 1, fp1);
            //printf("%s %s %d %.2lf\n", bookRead[i].title, bookRead[i].author, bookRead[i].pages, bookRead[i].price);
            push(&list,bookRead[i].title, bookRead[i].author, bookRead[i].pages, bookRead[i].price);
        }
        mergeSort(list, compTitle);
        print_list(list);
   // }
    //fclose(fp1);

    FILE* fp2;
    char fileW[50];
    printf("Name of file (w):");
    scanf("%s", fileW);

    fp2 = fopen(fileW, "wb");
    if(fp2 == NULL){
        fprintf(stderr, "Write error.\n");
    }

    while(list != NULL){
        fwrite(&list, sizeof(list), 1, fp2);
        list = list->next;
    }

    fclose(fp1);
    fclose(fp2);
    listFree(list);

    return 0;
}



void push(Booklist** list, char title[], char author[], int *pages, double *price){
    Booklist* n = malloc(sizeof(Booklist));
    n->title = title;
    n->author = author;
    n->pages = pages;
    n->price = price;
    n->next = *list;
    *list = n;
}


void print_list(Booklist* list){
    Booklist* current = list;
    while (current){
        printf("%s %s %d %.2lf ", current->title, current->author, current->pages, current->price);
        current = current->next;
    }
    putchar('\n');
}

void listFree(Booklist** list){
    Booklist *current = *list, *prev;
    while (current){
        prev = current;
        current = current->next;
        free(prev);
    }
    *list = NULL;
}

int compTitle(const void* vp1, const void* vp2){
    Booklist* book1 = (Booklist*) vp1;
    Booklist* book2 = (Booklist*) vp2;
    return strcmp(book1->title, book2->title); 
}

void frontBackSplit(Booklist* list, Booklist** front, Booklist** back){
    Booklist* slow = list;
    Booklist* fast = list->next;
    while (fast != NULL){
        fast = fast->next;
        if (fast  != NULL){
            slow = slow->next;
            fast = fast->next;
        }
    }
    *front = list;
    *back = slow->next;
    slow->next = NULL;
}

void mergeSort(Booklist** list, int(*cmp)(const void*, const void*)){
    if (*list == NULL || (*list)->next == NULL){
        return;
    }
    Booklist *front = NULL, *back = NULL;
    frontBackSplit(*list, &front, &back);
    mergeSort(&front, cmp);
    mergeSort(&back, cmp);
    *list = sortedMerge(front, back, cmp);
}