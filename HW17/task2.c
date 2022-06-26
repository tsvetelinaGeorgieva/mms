#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <time.h>


int main(int argc, char **argv){
    int fd[2];
    if(pipe(fd) == -1){
        perror("pipe");
        return EXIT_SUCCESS;
    }
    
        pid_t pid = fork();
        if (-1 == pid){
            perror("fork");
            return EXIT_FAILURE;
        }
        if (0 == pid){
            int sumCh = 0;
            int *sum;
            sum = &sumCh;
            for(int i = 1; i < argc/2; i++){
                sumCh += atoi(argv[i]);
            }
            //printf("sumCh: %d ", sumCh);
            close(fd[0]);
            write(fd[1], sum, sizeof(int));
            close(fd[1]);
        }else{
            
            int n, sumP = 0;
            int* sum;
            close(fd[1]);
            read(fd[0], sum, sizeof(int));
            //printf("sumP: %d ", *sum);
            for(int i = argc/2; i < argc; i++){
                sumP += atoi(argv[i]);
            }
            sumP += *sum;
            printf("sumP: %d ", sumP);
        }
    
    for (int i = 0; i < argc; i++){
        wait(NULL);
    }
    return EXIT_SUCCESS;
}

