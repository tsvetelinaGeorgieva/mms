#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

int randInt(int min, int max){
    return min + (rand()% (max + 1 - min)); 
}

void *routine(void* arg){
    int len = randInt(1, 10);
    char str[len];
    str[0] = randInt('A', 'Z');
    for(int i = 1; i < len; i++){
        str[i] = randInt('a', 'z');
    }
    str[len] = '\0';
    sleep(1);
    printf("%s\n", str);
}

int main(int argc, char **argv){
    srand(time(NULL));
    int size = atoi(argv[1]);
    pthread_t th[size];
    for (int i = 0; i < size; i++){
        if(pthread_create(&th[i], NULL, routine, NULL)){
            perror("create");
            return EXIT_FAILURE;
        }
    }
    for (int i = 0; i < size; i++){
        if(pthread_join(th[i], NULL)){
            perror("join");
            return EXIT_FAILURE;
        }
    }
    return 0;
}