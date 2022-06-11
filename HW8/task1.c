#include<stdio.h>
#include<string.h>

void mystrncpy(char *, const char*, size_t);
void mystrcpy(char *, const char*);
void mystrncat(char *, const char*, size_t);
void mystrcat(char *, const char*);
int mystrlen(char *);
int mystrnlen(char * arr, size_t n);
int mystrcmp(const char*, const char*);
int mystrncmp(const char*, const char*, size_t);
char *mystrstr(const char *str1, const char* str2);

int main(){
    char str1[20], str2[20];
    mystrncpy(str2, "Hello!", 6);
    printf("Str2: %s\n", str2);
    //mystrcpy(str1, "MMS! fun-strcpy");
    //printf("Str1: %s\n", str1);
    //mystrncat(str1, "MMS!", 5);
    //printf("Str1: %s\n", str1); 
    mystrcat(str1, "HelloMMS!");
    //printf("Str2: %s\n", str2);
    //printf("Str1: %s\n", str1);
    //mystrcat(str2, str1);
    printf("Str1: %s\n", str1);
    //printf("%d\n", mystrlen(str1));
    //printf("%d\n", mystrnlen(str1, 3));
    printf("%d\n", mystrcmp(str1, str2));
    printf("%d\n", mystrncmp(str1, str2, 3));

    char* match = mystrstr("Hello, MMS C CAMP", " M");
    printf("%s\n", match);
    


    return 0;
}

void mystrncpy(char * dest, const char* str, size_t n){
    for(size_t i = 0; i < n; i++){
        if(*(str + i) == '\0'){
            *(dest + i) = '\0';
            break;
        }
        *(dest + i) = *(str + i);
    }
    
}

void mystrcpy(char * dest, const char* str){
    for(size_t i = 0; i < strlen(str); i++){
        if(*(str + i) == '\0'){
            *(dest + i) == '\0';
            break;
        }
        *(dest + i) = *(str + i);
    }
}


void mystrncat(char * dest, const char* str, size_t n){
    
    for(size_t i = strlen(dest), j = 0; i <= (strlen(dest) + n); i++, j++){
        if(i == (strlen(dest) + n)){
            *(dest + i + 1) = '\0';
        }else{
            *(dest + i) = *(str + j);
        }
    }
}

void mystrcat(char * dest, const char* str){
    
    for(size_t i = strlen(dest), j = 0; i <= (strlen(dest) + strlen(str)); i++, j++){
        if(i == (strlen(dest) + strlen(str))){
            *(dest + i + 1) = '\0';
        }else{
            *(dest + i) = *(str + j);
        }
    }
}


int mystrlen(char * arr){
    int count = 0;
    for(int i = 0; arr[i] != '\0'; i++){
        count++;
    }
    return count;
}

int mystrnlen(char * arr, size_t n){
    int count = 0;
    for(int i = 0; i < n; i++){
        count++;
    }
    return count * sizeof(*arr);
}

int mystrcmp(const char* str1, const char* str2){
    for(int i = 0; i < strlen(str1); i++){
        if(str1[i] != str2[i]){
            return str1[i] - str2[i];
        }
    }
    return 0;
}

int mystrncmp(const char* str1, const char* str2, size_t n){
    for(int i = 0; i < n; i++){
        if(str1[i] != str2[i]){
            return str1[i] - str2[i];
        }
    }
    return 0;
}


char* mystrstr(const char* str1, const char* str2){
    int flag = 1;
    //char* match = NULL;
    for(int i=0; i < strlen(str1); i++){
        if(str1[i] == str2[0]){
            for(int j = 1; j < strlen(str2); j++){
                if(str2[j] == str1[i + j]){
                    flag++;
                }
            }
        }

        if(flag == strlen(str2)){
            char* match = &str1[i];
            return match;
        }
    }

    //return -1;
}

