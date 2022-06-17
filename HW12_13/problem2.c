#include<stdio.h>

void Reverse(char*);

int countReverse(char* ptr){
    int count = 0;
    for(int l = 0; ptr[l] != '\0'; l++){
        count++;
    }
    return count;
}

int main(){
    char str[] = "This is a test";
    printf("%s\n", str);
    Reverse(str);
    printf("%s\n", str);
    return 0;
}

void Reverse(char* ptr){
    int count = 0;
    for(int l =0; ptr[l] != '\0'; l++){
        count++;
    }
    char temp;
    for(int i = 0; i < (count / 2); i++){
        temp = ptr[i];
        ptr[i] = ptr[count - i - 1];
        ptr[count - i - 1] = temp;
    }
    ptr[count] = '\0';
}