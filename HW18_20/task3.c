#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <time.h>
#include <pthread.h>

void *routine(void* arg){
    //char str[] = arg;
    sleep(1);
    printf("Child: My PID: %d   ", getpid());
    printf("Thread ID: %ld   ", pthread_self());
    printf("%s\n", (char*)arg);
}

int main(int argc, char **argv){
    int P = atoi(argv[1]);
    for (int i = 0; i < P; i++){
        pid_t pid = fork();
        if (-1 == pid){
            perror("fork");
            return EXIT_FAILURE;
        }
        if (0 == pid){
            int T = atoi(argv[2]);
            pthread_t th[T];
            for (int i = 0; i < T; i++){
            if(pthread_create(&th[i], NULL, routine, argv[3])){
                perror("create");
                return EXIT_FAILURE;
            }
        }
        for (int i = 0; i < T; i++){
        if(pthread_join(th[i], NULL)){
            perror("join");
            return EXIT_FAILURE;
            }
           
        }
            exit(EXIT_SUCCESS);
        }
    }
    for (int i = 0; i < P; i++){
        wait(NULL);
    }
    return EXIT_SUCCESS;
}