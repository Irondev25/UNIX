#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/fcntl.h>
#include<stdlib.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
    char buf;
    int sourcefile,destfile,n;
    if(argc!=3)
    {
        write(STDOUT_FILENO,"./copy <source file> <destination file>\n",50);
        exit(1);
    }
    else
    {
        sourcefile=open(argv[1],O_RDONLY);
        if(sourcefile==-1)
        {
            perror("SOURCE FILE ERROR");
            exit(0);
        }
        else
        {
            destfile=open(argv[2],O_WRONLY|O_CREAT,0641);
            if(destfile==-1)
            {
                perror("DESTINATION FILE ERROR");
                exit(0);
            }
            else
            {
                while((n=read(sourcefile,&buf,1))>0)
                {
                    write(destfile,&buf,1);
                }
                write(STDOUT_FILENO,"FILES COPIED\n",15);
                close(sourcefile);
                close(destfile);
            }
            
        }
    }
    return 0;
}