#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


FILE* file_open(char *fpath)
{
    FILE* fptr;
    fptr = fopen(fpath, "r");

    if (fptr == NULL)
    {
        terrno(errno);
        exit(EXIT_FAILURE);
    }

    return fptr;

}