#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include "types.h"
#include "structurs.h"

// Redefine from <dirent.h> -> fix error what i don`t now. DT_DIR is undefined!
#define DT_UNKNOWN 0 // The file type could not be determined.
#define DT_DIR 4     // This is a directory.
#define DT_REG 8     // This is a regular file.


void directory_read(char *dir_name, char *dir_path, PRJ_DIR *prj_dir)
{
    DIR *dir;
    DIRECTORY *entry;
    int counter = 0;

    prj_dir->name = dir_name; // TODO: strcpy() ??? strcpy(pr_dir.name, dir_name);
    prj_dir->path = dir_path;

    if ((dir = opendir(dir_path)) == NULL)
    {
        terrno(errno);
        exit(EXIT_FAILURE);
    }
    else
    {
        char *correct_dir_path = concat(dir_path, "/");
        terror(256, "\nContents of \"%s\": ", dir_path);
        while ((entry = readdir(dir)) != NULL)
        {

            if (entry->d_type == DT_DIR)
            {
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
                strcpy(pr_file.name, entry->d_name);
                strcpy(pr_file.path, fpath);
                strcpy(pr_file.source, dir_path);
                prj_dir->files[counter] = pr_file;
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