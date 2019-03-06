#include<iostream>
#include<sys/types.h>
#include<unistd.h>
#include<utime.h>
#include<time.h>

using namespace std;

int main(int argc, char* argv[]){
    struct utimbuf var;
    int offset;
    cout<<"Enter offset values\n";
    cin>>offset;
    var.actime=var.modtime=time(0)+offset;
    if(utime(argv[1],&var)<0)
        perror("utime");
    return 0;
}