#include<iostream>
#include<sys/stat.h>
#include<unistd.h>


using namespace std;

int main(int argc, char* argv[]){
    int flag=S_IRWXG|S_IRWXO|S_IRWXU;
    flag=flag & ~(S_IWGRP|S_IWOTH);
    if(!mkdir(argv[1],flag)){
        perror("mkdir");
    }
    else{
        cout<<"Directory created\n";
    }
    return 0;
}