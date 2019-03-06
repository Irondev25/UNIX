#include<iostream>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>

using namespace std;

int main(){
    struct stat s;
    int fd;
    int dev_id=(15<<8)|3;
    if((fd=mknod("HD15",S_IFBLK|S_IRWXU|S_IRWXG|S_IRWXO,dev_id))<0){
        perror("mknod");    
        return -1;
    }
    else{
        cout<<"Device Created\n";
    }
    return 0;
}