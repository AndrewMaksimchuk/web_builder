#define _POSIX_SOURCE
#include <dirent.h>
#include <errno.h>
#include <sys/types.h>
#undef _POSIX_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
// #include <sys/types.h>

// Redefine from <dirent.h>
#define DT_UNKNOWN 0 // The file type could not be determined.
#define DT_DIR 4     // This is a directory.
#define DT_REG 8     // This is a regular file.

// char d_name[256];

typedef struct dirent directory;

int directory_size = sizeof(directory);

char *project_path;
char *page_path;
char *component_path;
char *unit_path;

char *project_directories[] = {"page_path", "component_path", "unit_path"};

// TODO: create struct for directories from project_directories

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

// struct Project {
//     struct Project_dir dirs[3];
// };

char *concat(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1) + strlen(s2) + 1);

    if (result == NULL)
    {
        printf("Unable to allocate memory\n");
        exit(EXIT_FAILURE);
    }

    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

void get_project_path(int argc, char *argv[])
{
    if (argc > 1)
    {
        // TODO: check if path from cli argument is exist
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

void get_path_to()
{
    switch (0)
    {
    case 0:
        page_path = concat(project_path, "/src/page");
    case 1:
        component_path = concat(project_path, "/src/component");
    case 2:
        unit_path = concat(project_path, "/src/unit");
    }
}

void logging(char *message)
{
    printf("%s\n", message);
}

void logging_all_path()
{
    logging(project_path);
    logging(page_path);
    logging(component_path);
    logging(unit_path);
}

int exclude_dir(char *dirname)
{
    // 0 - Both the strings are equal.
    // 1 - Different
    if (strcmp(dirname, "..") == 0)
    {
        return 0;
    }
    else if (strcmp(dirname, ".") == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

struct Project_dir read_directory(char *dir_name, char *dir_path)
{
    // TODO: return pointer(address of memory) of array of string(file name in folder)
    DIR *dir;
    directory *entry;
    int counter = 0;

    struct Project_dir pr_dir;
    pr_dir.name = dir_name;
    pr_dir.path = dir_path;

    if ((dir = opendir(dir_path)) == NULL)
    {
        // TODO: add readeble error message and close program or scipt if some directore don`t exist
        perror("opendir() error");
    }
    else
    {
        char *correct_dir_path = concat(dir_path, "/");
        printf("\033[31;1m\nContents of \"%s\": \n\033[0m", dir_path);
        while ((entry = readdir(dir)) != NULL)
        {

            if (entry->d_type == DT_DIR)
            {
                // TODO: exclude '.' and '..' directories
                if (exclude_dir(entry->d_name) == 0)
                {
                    continue;
                }
                printf("  %s\n", entry->d_name);
            }

            if (entry->d_type == DT_REG)
            {
                char *fpath = concat(correct_dir_path, entry->d_name);
                printf("  %d. %s\n", ++counter, entry->d_name);
                printf("     %s\n", fpath);
                // TODO: add filename to array then return array pointer(address)

                struct Project_file pr_file;
                pr_file.source = dir_path;
                pr_file.name = entry->d_name;
                pr_file.path = fpath;
                pr_dir.files[counter] = pr_file;

                // printf("- %s\n", pr_file.source);
                // printf("- %s\n", pr_file.name);
                // printf("- %s\n", pr_file.path);
                // printf("%s\n", pr_dir.files[counter].name);
            }
        }

        pr_dir.size = counter;
        closedir(dir);
        printf("\033[32m  In total you have %d files.\n\033[0m", counter);

        return pr_dir;
    }
}

int find_string(char line[], char pattern[])
{
    int i, j, k;
    for (i = 0; line[i] != '\0'; i++)
    {
        for (j = i, k = 0; pattern[k] != '\0' && line[j] == pattern[k]; j++, k++)
            ;
        if (k > 0 && pattern[k] == '\0')
            return 1;
    }
    return 0;
}

int create_directory(char *dirname)
{
    // return mkdir(dirname, 0777);
    return mkdir(dirname, S_IRWXU);
}

void write_file()
{

    int num;
    FILE *fptr;

    // use appropriate location if you are using MacOS or Linux
    fptr = fopen("./program.txt", "w");

    if (fptr == NULL)
    {
        printf("Error!");
        exit(1);
    }

    printf("Enter num: ");
    scanf("%d", &num);

    fprintf(fptr, "%d", num);
    fclose(fptr);
}

// TODO: read file
void read_file(char *fpath)
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
    create_directory("dist");

    // if (fgets(str, size, fptr) != NULL)
    // {
    //     printf("String is: %s\n", str);
    // }

    // For reading and writing to a text file, we use the functions fprintf() and fscanf().
    // fprintf() and fscanf() expects a pointer to the structure FILE.

    fclose(fptr);
}

void for_each_file(struct Project_dir dir)
{

    printf("File of: %s\n", dir.name);
    for (int i = 1; i <= dir.size; i++)
    {
        printf("File name: %s\n", dir.files[i].name); // FIXME: name is not show
        printf("File path: %s\n", dir.files[i].path);
        printf("File source: %s\n", dir.files[i].source);

        read_file(dir.files[i].path);
    }
}

void read_project(int argc, char *argv[])
{
    DIR *dir;
    directory *entry;

    get_project_path(argc, argv);
    get_path_to();
    // logging_all_path();

    struct Project_dir page = read_directory("page", page_path);
    struct Project_dir component = read_directory("component", component_path);
    struct Project_dir unit = read_directory("unit", unit_path);

    for_each_file(page);

    // printf("\n\n\n Global array of struct and 0 index struct is: %s\n", store_project_directories[0].name);
}
