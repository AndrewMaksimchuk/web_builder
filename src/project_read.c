// sys
#define _POSIX_SOURCE
#include <dirent.h>
#include <errno.h>
#include <sys/types.h>
#undef _POSIX_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

// Redefine from <dirent.h> -> fix error what i don`t now. DT_DIR is undefined!
#define DT_UNKNOWN 0 // The file type could not be determined.
#define DT_DIR 4     // This is a directory.
#define DT_REG 8     // This is a regular file.

// dev
#include "types.c"
#include "structurs.c"
#include "logging.c"
#include "str_concat.c"
#include "get_project_path.c"
#include "get_path_to.c"
#include "exclude_dir.c"
#include "find_string.c"
#include "directory_create.c"
#include "create_project_struct.c"
#include "file_remove.c"
// #include "remove_project_directories.c" // now not use
// #include "file_write.c" // now not use
#include "file_read.c"
// #include "directory_read.c" // TODO: rewrite, not return
// #include "file_for_each.c" // FIXME: error

char *project_dir[] = {"dist/js", "dist/css", "dist"};
char *project_path;
char *page_path;
char *component_path;
char *unit_path;

void directory_read(char *dir_name, char *dir_path, PRJ_DIR *prj_dir)
{
    DIR *dir;
    DIRECTORY *entry;
    int counter = 0;

    prj_dir->name = dir_name; // strcpy() ??? strcpy(pr_dir.name, dir_name);
    prj_dir->path = dir_path;

    if ((dir = opendir(dir_path)) == NULL)
    {
        // TODO: add readeble error message and close program or scipt if some directore don`t exist
        perror("opendir() error");
    }
    else
    {
        char *correct_dir_path = concat(dir_path, "/");
        terror(256, "\nContents of \"%s\": ", dir_path);
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
                prj_dir->files[counter] = pr_file;

                // printf("- %s\n", pr_file.source);
                // printf("- %s\n", pr_file.name);
                // printf("- %s\n", pr_file.path);
                // printf("%s\n", pr_dir.files[counter].name);
            }
        }

        prj_dir->size = counter;
        closedir(dir);
        if (counter == 0)
        {
            tlog_color(32, "  There are no files here.");
        }
        else if (counter > 1)
        {
            tmessage_number(32, 31, "  In total you have %d files.\n", counter);
        }
        else
        {
            tmessage_number(32, 31, "  In total you have %d file.\n", counter);
        }
    }
}

/* FIXME: extruct in separeted file without error, fix error */
void file_for_each(PRJ_DIR dir)
{
    if (dir.name == NULL)
    {
        printf("Don`t have directory.\n");
        return;
    }

    printf("File of: %s\n", dir.name);
    for (int i = 1; i <= dir.size; i++)
    {
        printf("File name: %s\n", dir.files[i].name); // FIXME: name is not show
        printf("File path: %s\n", dir.files[i].path);
        printf("File source: %s\n", dir.files[i].source);

        file_read(dir.files[i].path);
    }
}

void project_read(int argc, char *argv[])
{
    //     DIR *dir;
    //     DIRECTORY *entry;

    get_project_path(argc, argv);
    get_path_to();

    PRJ_DIR page, component, unit;
    directory_read("page", page_path, &page);
    directory_read("component", component_path, &component);
    directory_read("unit", unit_path, &unit);

    file_for_each(page);
    create_project_struct();
    // file_remove("dist/css");
}
