#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<stdlib.h>
extern int errno;
int main()
{    
    
    
    int fd = open("foo.txt",  O_RDWR );
    
    printf("fd = %d/n", fd);
    
    if (fd ==-1)
    {
        
        printf("Error Number % d\n", errno);
        
        
        perror("Program");                
    }
    int sz;
    sz = write(fd, "Hello kark\n", strlen("hello kark\n"));
    if (sz == -1 && errno != EINTR) {
            perror("Write to output file");
            exit(EXIT_FAILURE);
        }
    return 0;
}

