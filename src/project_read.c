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

// TODO: remove unused #include
// dev
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
// #include "file_read.c"
#include "directory_read.c"
#include "file_for_each.c"


char *project_dir[] = {"dist/js", "dist/css", "dist"};
char *project_path;
char *page_path;
char *component_path;
char *unit_path;


void project_read(int argc, char *argv[])
{
    get_project_path(argc, argv);
    get_path_to();

    PRJ_DIR page, component, unit;
    directory_read("unit", unit_path, &unit);
    directory_read("component", component_path, &component);
    directory_read("page", page_path, &page);

    file_for_each(unit);
    file_for_each(component);
    file_for_each(page);
    // create_project_struct();
    // file_remove("dist/css");

}
