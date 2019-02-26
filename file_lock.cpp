#include<iostream>

//POSIX API HEADER
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>

using namespace std;

int main(int argc, char* argv[])
{
    struct flock fvar;
    int fdesc;
    //do for each file
    while(--argc>0){
        if((fdesc=open(*++argv,O_RDWR))==-1){
            perror("open");
            continue;
        }
        fvar.l_type=F_WRLCK;
        fvar.l_whence=SEEK_SET;
        fvar.l_start=0;
        fvar.l_len=0;
        //attempt to set exclusive(write) lock on the entire file
        while(fcntl(fdesc,F_SETLK,&fvar)==-1){
            //lock failed, fild out who have locked the file
            while(fcntl(fdesc,F_GETLK,&fvar)!=-1 && fvar.l_type!=F_UNLCK){
                cout<<*argv<<" locked by "<<fvar.l_pid<<" from "<<fvar.l_start<<" for "<<fvar.l_len
                    <<"bytes for "<<(fvar.l_type==F_WRLCK?'w':'r')<<endl;
                if(!fvar.l_len) break;
                fvar.l_start+=fvar.l_len;
                fvar.l_len=0;
            }//while there are locks set by other processes
        }//while set locks unsuccessfull
        //lock OK. Now process the data
        //PROCESS THE FILE HERE
        //Now unlock the file
        fvar.l_type=F_UNLCK;
        fvar.l_whence=SEEK_SET;
        fvar.l_start=0;
        fvar.l_len=0;
        if(fcntl(fdesc,F_SETLKW,&fvar)==-1) perror("fcntl");
    }
    return 0;
}