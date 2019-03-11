#include<iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

using namespace std;

int main(int argc, char* argv[]){
    int id,fd,fdd;
    char buf[10];
    id=mkfifo(argv[1],S_IFIFO|S_IRWXU|S_IRWXG|S_IRWXO);
    if(id==-1){
        perror("mkfifo");
        return -1;
    }
    return 0;
}