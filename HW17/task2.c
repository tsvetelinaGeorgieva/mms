#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <time.h>


int main(int argc, char** argv){
    int fd[2];
    
    if(pipe(fd) == -1){
        perror("pipe");
        return EXIT_FAILURE;
    }

    pid_t pid = fork();

    if (0 == pid){
        // child
        close(fd[0]);
        int num, sumChild = 0;
        for(int i = 1; i < argc / 2; i++){
            sscanf(argv[i], "%d", &num);
            sumChild += num;
        }
        write(fd[1], &sumChild, sizeof(sumChild));
        close(fd[1]);
    } else {
        // parent
        close(fd[1]);
        int num, sumParent;
        for(int j = argc / 2; j < argc; j++){
            sscanf(argv[j], "%d", &num);
            sumParent += num;
        }
        wait(NULL);
        int sumChild;
        read(fd[0], &sumChild, sizeof(sumChild));
        close(fd[0]);
        int sum = sumParent + sumChild;
        printf("Sum: %d\n", sum);
    }

    return EXIT_SUCCESS;
}