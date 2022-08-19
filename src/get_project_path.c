#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include "variables.h"

char *get_project_path(int argc, char *argv[])
{
    if (argc > 1)
    {
        DIR *dir = opendir(argv[1]);
        if (dir)
        {
            project_path = argv[1];
            closedir(dir);
        }
        else if (ENOENT == errno)
        {
            printf("'%s' - %s\n", argv[1], "Directory does not exist");
            exit(EXIT_FAILURE);
        }
        else
        {
            printf("%s\n", "opendir() failed for some other reason");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        project_path = ".";
    }
}