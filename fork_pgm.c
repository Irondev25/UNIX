#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
#include<unistd.h>

int main(){
    pid_t pid;
    //fork a child process
    pid=fork();
    if(pid<0){
        fprintf(stderr,"FORK FAILED!");
        return -1;
    }
    else if(pid==0){
        execlp("/bin/ls","ls",NULL);
    }
    else{
        //parent process
        //parent process will wait for the child to complete
        wait(NULL);
        printf("CHILD complete");
    }
    return 0;
}