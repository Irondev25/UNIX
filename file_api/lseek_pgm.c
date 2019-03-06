#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>

int main()
{
    char buf1[]="ISE Department";
    char buf2[]="CSE Department";
    int fd;
    fd=open("ISE.txt",O_WRONLY|O_CREAT,0622);
    if(fd<0)
    {
        perror("open");
    }
    else 
    {
        write(fd,buf1,15);
        lseek(fd,48,SEEK_CUR);
        write(fd,buf2,15);
        close(fd);
    }
    return 0;
}