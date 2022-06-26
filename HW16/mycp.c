#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<fcntl.h>


int main(int argc, char **argv){
    int p = atoi(argv[2]);
        for(int i = 0; i < p; i++){
            int fd = open(argv[1], O_RDONLY);
            if(fd == -1){
            perror("File not found (read)!\n");
            return -1;
            }
            int fd1 = open(argv[2], O_APPEND);
            if(fd1 == -1){
            perror("File not found (append)!\n");
            return -1;
            }
            int c;
            while(read(fd, &c, 1)){
                 write(fd1, &c, 1);
            }            
            close(fd);            
        }

    return 0;
}