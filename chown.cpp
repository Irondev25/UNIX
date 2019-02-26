//if changing the ownership to non-sudo user add sudo before ./a.out
//compgen -u for listing user
//compgen -g for listing group
#include<iostream>

#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<grp.h>
#include<pwd.h>

using namespace std;

int main(int argc, char* argv[]){
    if(argc<3){
        cerr<<"Usage:"<<argv[0]<<"<user_name> <file>..\n";
        return -1;
    }
    struct passwd* pwd=getpwnam(argv[1]);
    uid_t UID=pwd?pwd->pw_uid:-1;
    struct stat statv;
    if(UID==(uid_t)-1){
        cerr<<"Invalid Username\n";
    }
    else{
        for(int i=2;i<argc;i++){
            if(stat(argv[i],&statv)==0){
                if(chown(argv[i],UID,statv.st_gid)){
                    perror("chown");
                }
            }
            else{
                perror("stat");
            }
        }
    }
    return 0;
}