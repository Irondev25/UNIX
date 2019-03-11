#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include<sys/sysmacros.h>

using namespace std;

int main(int argc, char* argv[])
{
    struct stat s;
    if(stat(argv[1],&s)<0){
        perror("stat");
        return -1;
    }
    else{
        cout<<major(s.st_rdev)<<" "<<minor(s.st_rdev)<<endl;
        if(S_ISBLK(s.st_mode)){
            cout<<"block file"<<endl;
        }
        else if(S_ISCHR(s.st_mode)){
            cout<<"char file"<<endl;
        }
    }
    return 0;
}