#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
    int fd,n,i;
    char buf,buf2[11];
    fd = open("lorem.txt", O_RDONLY | O_CREAT, 0622);
    if (fd < 0)
    {
        perror("open");
    }
    else
    {
        while(read(fd,&buf,1)>0){
            write(STDOUT_FILENO,&buf,1);
        }
        printf("\nLseek Manipulation\n");
        lseek(fd,10,SEEK_SET);
        // if ((n=read(fd, &buf2, 20)) > 0)
        // {
        //     write(STDOUT_FILENO, &buf2, n);
        // }
        i=0;
        while (read(fd, &buf, 1) > 0 && i<20)
        {
            write(STDOUT_FILENO, &buf, 1);
            i++;
        }
    }
    return 0;
}