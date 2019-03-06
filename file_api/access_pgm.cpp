#include<iostream>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

using namespace std;

int main(int argc, char*argv[])
{
    if(!(access(argv[1],R_OK|W_OK|X_OK)))
        cerr<<"Species file has read write and execute perm\n";
    else
        cerr<<"No access permission\n";
    return 0;
}