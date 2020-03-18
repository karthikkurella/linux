#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<string.h>
int main(){
int fd,sz;

char *filename="kark1.txt";

//fd=creat(filename, S_IRUSR | S_IWUSR );
//open and read in c using sys calls
int fd1;

fd1=open(filename, O_RDWR);
char *c =(char *) calloc (100, sizeof(char));
sz=read(fd1,c,12);

printf("The Charactersa are as follows: %s \n",c);

//write(fd1,"hello world is here\n",strlen("hello world is here\n"));
//sz=read(fd1,c,40);
//printf("After the write operation its this one: %s \n",c);
       return 0;
}
