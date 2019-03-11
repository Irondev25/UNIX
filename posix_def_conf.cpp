#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309L
#include <iostream>
#include <unistd.h>

using namespace std;

int main()
{
    #ifdef _POSIX_JOB_CONTROL
    cout << "system supports job control";
    #else
    cout << "system does not support job control\n";
    #endif
    #ifdef _POSIX_SAVED_IDS
        cout <<" system supports saved set - UID and set - GID";
    #else
        cout <<" system does not support set - uid and gid\n";
    #endif
    #ifdef _POSIX_CHOWN_RESTRICTED
        cout <<"chown_restricted option is :"
            << _POSIX_CHOWN_RESTRICTED
            << endl;
    #else
        cout <<"system does not support"
            <<" chown_restricted option\n";
    #endif
    #ifdef _POSIX_NO_TRUNC
        cout <<"pathname trunc option is :"
            << _POSIX_NO_TRUNC
            << endl;
    #else
        cout <<" system does not support system - wide pathname"
            <<"trunc option\n";
    #endif
    #ifdef _POSIX_VDISABLE
    cout<<"disable char. for terminal files is:"
    <<_POSIX_VDISABLE<<endl;
    #else
        cout <<" system does not support _POSIX_VDISABLE \n";
    #endif
    return 0;
}