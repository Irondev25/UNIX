#include<iostream>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

using namespace std;

int main(){
    int fd;
    if(!mknod("/dev/fb1",0777,(15<<8)|3)){
        if ((fd = open("/dev/fb1", O_RDWR | O_NONBLOCK | O_NOCTTY)) != -1)
        {
            char buff[256];
            int rc = 1;
            while (rc)
            {
                if ((rc = read(fd, buff, sizeof(buff))) < 0)
                    perror("read");
                else
                {
                    if (rc)
                        cout << buff << endl;
                    else
                        cout<<"I got nothing from the device man\n";
                }
            }
        }
        else
        {
            perror("open");
        }
    }
    return 0;
}