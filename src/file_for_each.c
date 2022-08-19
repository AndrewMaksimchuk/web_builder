#include "types.h"
#include "structurs.h"
#include "file_read.c"

void
file_for_each(PRJ_DIR dir)
{

    terror(100, "File of project directory: %s", dir.name);
    for (int i = 1; i <= dir.size; i++)
    {
        printf("File name: %s\n", dir.files[i].name);
        printf("File path: %s\n", dir.files[i].path);
        printf("File source path: %s\n", dir.files[i].source);

        file_read(dir.files[i].path);
    }
}