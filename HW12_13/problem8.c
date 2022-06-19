#include<stdio.h>
#include<string.h>
#include<math.h>

void Add(const char*, const char*, char*);

int main(){
    char p1[] = "12345";
    char p2[] = "678";
    char result[strlen(p1) + strlen(p2)];
    Add(p1, p2, result);

    printf("%s\n", result);

    return 0;
}

void Add(const char* p1, const char* p2, char* result){
    int str1 = 0;
    int str2 = 0;
    int sum = 0;

    for(int i = strlen(p1) - 1, j = 0; i >= 0; i--, j++){
        str1 += (p1[i] - '0') * pow(10, j);
    }

    for(int j = strlen(p2) - 1, i = 0; j >= 0; j--, i++){
        str2 += (p2[j] - '0') * pow(10, i);
    }

    sum = str1 + str2;
    int s = 0;
    while(sum != 0){
        s++;
        sum /= 10;
    }
    sum = str1 + str2;
    for(int p = s - 1; p >= 0; p--){
        result[p] = (sum % 10) + '0';
        sum /= 10;
    }
     result[s] = '\0';
}