#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


void file_close(FILE *fptr)
{
    int status_code = fclose(fptr);

    if (status_code != 0)
    {
        terrno(errno);
        exit(EXIT_FAILURE);
    }

}