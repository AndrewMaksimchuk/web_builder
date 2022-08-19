#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>


void directory_create(char *dirname)
{
    int status_code = mkdir(dirname, S_IRWXU);
    if (status_code == -1)
    {
        terrno(errno);
        exit(EXIT_FAILURE);
    }
    printf("Dist is: %d in %s\n", status_code, dirname);
}
