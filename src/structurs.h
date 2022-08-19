#include <linux/limits.h>

#ifndef STRUCTURS_H
#define STRUCTURS_H

#define NUMBER_OF_FILES 100

struct Project_file
{
    char name[NAME_MAX];
    char path[PATH_MAX];
    char source[PATH_MAX];
};

struct Project_dir
{
    char *name;
    char *path;
    int size;
    struct Project_file files[NUMBER_OF_FILES]; // TODO: change from fixed size to dynamic or defined larg number, files[?]
};

#endif // STRUCTURS_H