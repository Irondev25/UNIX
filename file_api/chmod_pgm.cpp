#include<iostream>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

int main(int argc, char* argv[]){
    struct stat s;
    int flag=S_IWGRP|S_IROTH|S_IXOTH;
    if(stat(argv[1],&s)<0){
        perror("stat");
    }
    else{
        flag=(s.st_mode & ~flag)|S_ISUID;
        if(chmod(argv[1],flag)<0)
            perror("chmod");
    }
    return 0;
}