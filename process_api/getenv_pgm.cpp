#include<iostream>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

using namespace std;

int main(int argc, char*argv[]){
    char *ptr;
    if((ptr=getenv(argv[1]))==NULL){
        perror("getenv");
        exit(1);
    }
    cout<<ptr<<endl;
    return 0;
}