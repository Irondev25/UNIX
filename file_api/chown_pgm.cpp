#include<iostream>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<pwd.h>

using namespace std;

int main(int argc, char* argv[]){
    struct passwd *pwd;
    uid_t UID;
    struct stat s;

    if(argc<3){
        cerr<<"Usage: "<<argv[0]<<" <username> <filename>\n";
        return -1;
    }
    pwd=getpwnam(argv[1]);
    if(pwd)
        UID=pwd->pw_uid;
    else
        UID=-1;
    if(UID==(uid_t)-1)
        cerr<<"Invalid Username\n";
    else{
        if(stat(argv[2],&s)<0)
            perror("stat");
        else{
            if(chown(argv[2],UID,s.st_gid)<0){
                perror("chown");
            }
            else{
                cout<<"changed ownership\n";
            }
        }
    }
    return 0;
}