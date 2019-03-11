#include<iostream>

using namespace std;

int main(int argc,char*argv[]){
    extern char **environ;
    for(int i=0;environ[i]!=NULL;i++){
        cout<<environ[i]<<endl;
    }
    return -1;
}