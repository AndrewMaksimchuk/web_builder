#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

// TODO: Change to correct successfull message
void file_remove(char *file)
{
    if (remove(file) != 0)
    {
        terrno(errno);
        exit(EXIT_FAILURE);
    }    
    printf("Deleted successfully\n");
}