#include <iostream>
#include <sys/stat.h>
#include <unistd.h>
#include<dirent.h>
#include<cstring>
#include<fcntl.h>

using namespace std;

void opendirectory(char* name){
    DIR *dfd;
    struct dirent *dfp;
    if ((dfd = opendir(name)) != NULL)
    {
        while (dfp = readdir(dfd))
        {
            if (!strcmp(dfp->d_name, "."))
                cout << "." << endl;
            else if (!strcmp(dfp->d_name, ".."))
                cout << ".." << endl;
            else
            {
                cout << dfp->d_name << endl;
                if(dfp->d_type==DT_DIR){
                    cout<<"\n\n";
                    cout<<"Reading "<<dfp->d_name<<" directory"<<endl;
                    opendirectory(dfp->d_name);
                    cout << "\n\n";
                }
            }
        }
        closedir(dfd);
    }
    else
    {
        perror("opendir");
    }
}

int main(int argc, char *argv[])
{
    opendirectory(argv[1]);
    return 0;
}