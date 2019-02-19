#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fh;

    if ((fh = fopen("myfile.dat", "r")) == NULL)
    {
        perror("fopen");
        abort();
    }
    return 0;
}