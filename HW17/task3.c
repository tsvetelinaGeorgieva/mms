#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<unistd.h>


int main(int argc, char* argv[]){
    pid_t pid = fork();
    if(pid == -1){
        perror("Fork error!\n");
        exit(EXIT_FAILURE);
    }

    if(pid == 0){
        int err = execlp(argv[1], argv[1], NULL);
        if(err == -1){
            perror("execlp error!\n");
            exit(EXIT_FAILURE);
        }
    }else{
        int wstatus;
        wait(&wstatus);

        if(WIFEXITED(wstatus)){
            int statusCode = WEXITSTATUS(wstatus);
            if(statusCode == 0){
                execlp(argv[2], argv[2], NULL);
                rexit(EXIT_SUCCESS);
            }else{
                exit(EXIT_FAILURE);
            }
        }
    }

    return EXIT_SUCCESS;
}