#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int main()
{
int fd,ret;
fd=open("foo.txt",O_WRONLY);
ssize_t nr;
char buf[BUFSIZ];
start:
nr=read(fd,buf,BUFSIZ);

while(BUFSIZ!=0 && (ret = read(fd,buf,BUFSIZ))!=0)
{
if(nr==-1)
{
if(errno == EINTR)
{
goto start;
}
if(errno == EAGAIN)
{
printf("EAGAIN vachindi");
continue;
}
else
{
perror("Read");
break;
}
}
}

}
