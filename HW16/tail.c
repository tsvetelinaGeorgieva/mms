#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<fcntl.h>


int main(int argc, char **argv){
    int p = atoi(argv[2]);
        for(int i = 0; i <= p; i++){
            int fd = open(argv[1], O_RDONLY);
            if(fd == -1){
            perror("File not found!\n");
            return -1;
            }
            int sett = i * (-1);
            lseek(fd, sett, SEEK_END);
            int c;
            read(fd, &c, 1);
            write(STDOUT_FILENO, &c, 1);            
            close(fd);            
        }
    char* sym = "\n\n";
    write(STDOUT_FILENO, sym, 2);

    return 0;
}