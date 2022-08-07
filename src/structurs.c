struct Project_file
{
    char *source;
    char *name;
    char *path;
};

struct Project_dir
{
    char *name;
    char *path;
    int size;
    struct Project_file files[10]; // TODO: change from fixed size to dynamic, files[?]
};