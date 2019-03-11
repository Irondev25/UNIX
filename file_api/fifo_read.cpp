#include <bits/stdc++.h>
#include <algorithm>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

using namespace std;

int main(int argc, char *argv[])
{
    int fdd;
    char buf[20];
    memset(buf,'\0',sizeof(buf)+1);
    fdd=open(argv[1],O_RDONLY);
    if(fdd==-1){
        perror("opening FIFO");
        return -1;
    }
    cout << "FIFO opened from p2 using descriptor " << fdd << endl;
    while(strcmp(buf,"done")){
        if (read(fdd, buf, 10) == 0)
        {
            perror("read");
            return -1;
        }
        cout << "Data read into p2 from the fifo = " << buf << endl;
    }
    return 0;
}