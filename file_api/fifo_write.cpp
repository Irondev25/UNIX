#include <bits/stdc++.h>
#include<algorithm>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<stdio.h>

using namespace std;

int main(int argc, char* argv[])
{
    int id, fd, fdd;
    char buf[20];
    memset(buf,'\0',20);
    if ((fd = open(argv[1], O_WRONLY))==-1)
    {
        perror("open FIFO");
        return -1;
    }
    cout<<"FIFO opened from p1 using descriptor "<<fd<<endl;
    char c='y';
    while(c=='y'){
        read(STDIN_FILENO, buf, 10);
        if (write(fd, buf, strlen(buf) + 1) == 0)
        {
            perror("Writing into FIFO");
        }
        cout<<"Enter again\n"<<endl;
        cin>>c;
    }
    return 0;
}