#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <time.h>

int randInt(int, int);
void randomStr(char*);

int main(int argc, char **argv){
    srand(time(NULL));
    int N = atoi(argv[1]);
    for (int i = 0; i < N; i++){
        pid_t pid = fork();
        if (-1 == pid){
            perror("fork");
            return EXIT_FAILURE;
        }
        if (0 == pid){
            srand(time(NULL) + i);
            char str[11];
            randomStr(str);
            printf("My str is %s\n", str);
            sleep(1);
            
            exit(EXIT_SUCCESS);
        }
    }
    for (int i = 0; i < N; i++){
        wait(NULL);
    }
    return EXIT_SUCCESS;
}

int randInt(int min, int max){
    return min + (rand()% (max + 1 - min)); 
}

void randomStr(char* model){
    int len = randInt(1, 10);
    model[0] = randInt('A', 'Z');
    for(int i = 1; i < len; i++){
        model[i] = randInt('a', 'z');
    }
    model[len] = '\0';
}
