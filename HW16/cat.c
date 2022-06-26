#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>


int main(int argc, char **argv){

    if(!argv[1]){
        char buff[100];
        while(read(STDIN_FILENO, buff, 100) != EOF){
            printf("%s", buff);
        }
    }else{
        for(int i = 1; i < argc; i++){
            if(argv[i]){
                int fd = open(argv[i], O_RDONLY);
                if(fd == -1){
                perror("File not found!\n");
                return -1;
                }
            int c;
            while(read(fd, &c, 1)){
                 write(STDOUT_FILENO, &c, 1);
            }
            close(fd);
            char* sym = "\n\n";
            write(STDOUT_FILENO, sym, 2);
            }
        }
    }

    return 0;
}