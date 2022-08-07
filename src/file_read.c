#include <stdio.h>
#include <stdlib.h>

// TODO: read file
void file_read(char *fpath)
{
    FILE *fptr;
    // ptr = fopen("fileopen","mode");
    // fopen("E:\\cprogram\\oldprogram.bin","r");
    fptr = fopen(fpath, "r");

    if (fptr == NULL)
    {
        printf("Error!");
        exit(EXIT_FAILURE);
    }

    int size = 1023;
    char str[size];

    // int cursor = fseek(fptr, 10, SEEK_SET);
    // printf("%d\n", cursor);

    int count = 0;
    while (fgets(str, size, fptr) != NULL)
    {

        if (find_string(str, "#include") > 0)
        {
            ++count;
            printf("String: %s", str);
        };
    }
    printf("Count %d\n", count);

    // if (fgets(str, size, fptr) != NULL)
    // {
    //     printf("String is: %s\n", str);
    // }

    // For reading and writing to a text file, we use the functions fprintf() and fscanf().
    // fprintf() and fscanf() expects a pointer to the structure FILE.

    fclose(fptr);
}