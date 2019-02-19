#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

int main(int argc, char *argv[])
{
    struct stat s;
    if(link(argv[1],argv[2])<0)
    {
        perror("LINK FAILED");
        return -1;
    }
    else 
    {
        stat(argv[1],&s);
        if(s.st_nlink>0)
            printf("LINK Successful\n%ld links present\n",s.st_nlink-1);
        else
            printf("LINK Unsuccessful");
    }
    return 0;
}