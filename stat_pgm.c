#define _POSIX_SOURCE
#include<sys/types.h>
#include<sys/stat.h>
#undef _POSIX_SOURCE
#include <stdio.h>
#include <time.h>

int main(int argc, char* argv[])
{
    struct stat info;

    if (stat(argv[1], &info) != 0)
        perror("stat() error");
    else
    {
        puts("stat() returned the following information about root f⁄s:");
        printf("  inode:   %d\n", (int)info.st_ino);
        printf(" dev id:   %d\n", (int)info.st_dev);
        printf("   mode:   %08x\n", info.st_mode);
        printf("  links:   %ld\n", info.st_nlink);
        printf("    uid:   %d\n", (int)info.st_uid);
        printf("    gid:   %d\n", (int)info.st_gid);
        printf("created:   %s", ctime(&info.st_ctime));
        printf("access:    %s", ctime(&info.st_atime));
        printf("modified:  %s", ctime(&info.st_mtime));
    }
}