#include<iostream>
#include<stdlib.h>
#include<unistd.h>

using namespace std;

void bye(void){
    cout<<"that's all folks"<<endl;
}

int main(int argc, char* argv[]){
    cout<<"_SC_ATEXIT_MAX: "<<sysconf(_SC_ATEXIT_MAX)<<endl;
    if(atexit(bye)!=0){
        perror("atexit");
        exit(EXIT_FAILURE);
    }
    return 1;
}