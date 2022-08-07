#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>


void directory_create(char *dirname)
{
    int ret = mkdir(dirname, S_IRWXU);
    if (ret == -1)
    {
        switch (errno)
        {
        case EACCES:
            printf("the parent directory does not allow write\n");
            exit(EXIT_FAILURE);
        case EEXIST:
            printf("pathname already exists\n");
            exit(EXIT_FAILURE);
        case ENAMETOOLONG:
            printf("pathname is too long\n");
            exit(EXIT_FAILURE);
        default:
            perror("mkdir");
            exit(EXIT_FAILURE);
        }
    }
    printf("Dist is: %d in %s\n", ret, dirname);
}