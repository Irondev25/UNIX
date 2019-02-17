// #define _POSIX_SOURCE
// #define _POSIX_C_SOURCE 200809L
#include<iostream>
#include<unistd.h>

using namespace std;

int main(){
    #ifdef _POSIX_VERSION
        cout<<"System conforms to POSIX"<<_POSIX_VERSION<<endl;
    #else   
        cout<<"_POSIX_VERSION UNDEFINED\n"<<endl;
    #endif

    #ifdef _POSIX_JOB_CONTROL
        cout<<"System supports job control"<<endl;
    #else
        cout << "System doen not supports job control" << endl;
    #endif

    #ifdef _POSIX_CHOWN_RESTRICTED
        cout<<"chown restricted option is "<<_POSIX_CHOWN_RESTRICTED<<endl;
    #else   
        cout<<"system doesn't support chown_restricted option"<<endl;
    #endif

    #ifdef _POSIX_NO_TRUNC
        cout<<"pathname trunc option is "<<_POSIX_NO_TRUNC<<endl;
    #else   
        cout<<"system doesn't support system wide pathname\n"<<endl;
    #endif

    #ifdef _POSIX_VDISABLE
        cout<<"disable char. for terminal files is"<<_POSIX_VDISABLE<<endl;
    #else   
        cout<<"system doesn't support _POSIX_VDISABLE"<<endl;
    #endif
    return 0;
}