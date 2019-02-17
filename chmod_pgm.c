#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

int main(int argc, char* argv[]){
    struct stat s;
    int flags = (S_IROTH|S_IXOTH|S_IWGRP);
    if(stat("bank.txt",&s))
        perror("stat");
    else{
        flags=(s.st_mode & ~flags)|S_ISUID;
        if(chmod("bank.txt",flags)){
            perror("chmod");
        }
    }
    return 0;
}