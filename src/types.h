#ifndef TYPES_H
#define TYPES_H

typedef enum BOOLEAN
{
    FALSE,
    TRUE
} BOOLEAN;

typedef enum COLOR
{
    BLACK = 30,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN,
    WHITE,
} TEXT_COLOR;

typedef struct dirent DIRECTORY;

typedef struct Project_dir PRJ_DIR;

#endif //TYPES_H