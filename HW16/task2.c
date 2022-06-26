#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>


int main(int argc, char **argv){
    int fd = open(argv[1], O_RDWR);
        if(fd == -1){
            perror("File not found!\n");
            return -1;
            }
            int c;
            while(read(STDIN_FILENO, &c, 1)){
                 write(fd, &c, 1);
            }
            close(fd);
            char* sym = "Success";
            write(STDOUT_FILENO, sym, 10);
                    
    return 0;
}