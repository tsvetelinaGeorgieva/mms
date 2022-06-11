#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#define COUNT 9

int randInt(int, int);
double randReal(double, double);
void randomName(char*);

int compTitleASC(const void*, const void*);
int compTitleDESC(const void*, const void*);
int compAuthorASC(const void*, const void*);
int compAuthorDESC(const void*, const void*);
int compPagesASC(const void*, const void*);
int compPagesDESC(const void*, const void*);
int compPriceASC(const void*, const void*);
int compPriceDESC(const void*, const void*);
void* linearSearch(const void*, const void*, size_t, size_t, int (*)(const void*, const void*));

typedef struct Book{
    char title[151];
    char author[101];
    int pages;
    double price;
}Book;

int main(){
    srand(time(NULL));
    Book books[COUNT];
    for(int i = 0; i < COUNT; i++){
        randomName(books[i].title);
        randomName(books[i].author);
        books[i].pages = randInt(5, 2000);
        books[i].price = randReal(20.20, 20.60);
    }
    //qsort(books, COUNT, sizeof(books[0]), compTitleASC);
    //qsort(books, COUNT, sizeof(books[0]), compTitleDESC);
    //qsort(books, COUNT, sizeof(books[0]), compAuthorASC);
    //qsort(books, COUNT, sizeof(books[0]), compAuthorDESC);
    //qsort(books, COUNT, sizeof(books[0]), compPagesASC);
    //qsort(books, COUNT, sizeof(books[0]), compPagesDESC);
    //qsort(books, COUNT, sizeof(books[0]), compPriceDESC);
    qsort(books, COUNT, sizeof(books[0]), compPriceASC);

    for(int i = 0; i < COUNT; i++){
        printf("%d.\n", (i+1));
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("Pages: %d\n", books[i].pages);
        printf("Price: %.2f\n\n", books[i].price);
    }

    Book search = {.price = 20.50};
    Book* bookSerch = linearSearch(&search.price, books, COUNT, sizeof(books[0]), compPriceASC);
    if(!bookSerch){
        printf("Not found!\n");
    }else{
        printf("Title: %s\n", bookSerch->title);
    }

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

int compTitleASC(const void* vp1, const void* vp2){
    Book* book1 = (Book*) vp1;
    Book* book2 = (Book*) vp2;
    return strcmp(book1->title, book2->title); 
}

int compTitleDESC(const void* vp1, const void* vp2){
    Book* book1 = (Book*) vp1;
    Book* book2 = (Book*) vp2;
    return strcmp(book2->title, book1->title); 
}


int compAuthorASC(const void* vp1, const void* vp2){
    Book* book1 = (Book*) vp1;
    Book* book2 = (Book*) vp2;
    return strcmp(book1->author, book2->author); 
}

int compAuthorDESC(const void* vp1, const void* vp2){
    Book* book1 = (Book*) vp1;
    Book* book2 = (Book*) vp2;
    return strcmp(book2->author, book1->author); 
}

int compPagesASC(const void* vp1, const void* vp2){
    Book* book1 = (Book*) vp1;
    Book* book2 = (Book*) vp2;
    return book1->pages - book2->pages; 
}

int compPagesDESC(const void* vp1, const void* vp2){
    Book* book1 = (Book*) vp1;
    Book* book2 = (Book*) vp2;
    return book2->pages - book1->pages; 
}

int compPriceASC(const void* vp1, const void* vp2){
    Book* book1 = (Book*) vp1;
    Book* book2 = (Book*) vp2;

    if(fabs(book1->price - book2->price) < 0.0001){
        return 0;
    }else if(book1->price > book2->price){
        return 1;
    }
    return -1;
}

int compPriceDESC(const void* vp1, const void* vp2){
    Book* book1 = (Book*) vp1;
    Book* book2 = (Book*) vp2;

    if(fabs(book1->price - book2->price) < 0.0001){
        return 0;
    }else if(book1->price < book2->price){
        return 1;
    }
    return -1;
}

void* linearSearch(const void* key, const void* base, size_t n, size_t size, int (*comparator)(const void*, const void*)){
    for(int i = 0; i < n; i++){
        if(comparator(key, (base + i * size)) == 0){
            return (base + i * size);
        }
    }

    return NULL;
}