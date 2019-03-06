//takes several file names if present then reads the contant otherwise creates the file and write hello world to it

#include<stdio.h>
#include<stdlib.h>

#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(int argc, char* argv[]){
    char buff[256];
    int fdesc, len;
    while(--argc>0){
        if(access(*++argv,F_OK)){
            //if file not present
            fdesc=open(*argv,O_WRONLY|O_CREAT,0744);
            write(fdesc,"Hello world\n",12);
        }
        else{
            fdesc=open(*argv,O_RDONLY);
            while(len=read(fdesc,buff,256))
                write(STDOUT_FILENO,buff,len);
        }
        close(fdesc);
    }
    return 0;
}
