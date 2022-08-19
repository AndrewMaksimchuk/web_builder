#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

// TODO: Change to correct write file .css, .js and .html
void file_write()
{
    int num;
    FILE *fptr;

    fptr = fopen("./program.txt", "w");

    if (fptr == NULL)
    {
        terrno(errno);
        exit(EXIT_FAILURE);
    }

    printf("Enter num: ");
    scanf("%d", &num);

    fprintf(fptr, "%d", num);
    fclose(fptr);
}