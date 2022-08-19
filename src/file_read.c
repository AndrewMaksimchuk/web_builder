#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "file_extruct_style.c"

void file_read(char *fpath)
{
    FILE *fptr;
    fptr = fopen(fpath, "r");

    if (fptr == NULL)
    {
        terrno(errno);
        exit(EXIT_FAILURE);
    }

    int size = 1023;
    char str[size];
    int count = 0;
    BOOLEAN in_style_tag = FALSE;
    BOOLEAN in_script_tag = FALSE;
    while (fgets(str, size, fptr) != NULL)
    {

        /* HTML */
        /* TODO: 
            - Find comment line with "#include"
            - Copy text inside html file from path from #include directive
        */
        if (find_string(str, "#include") > 0)
        {
            ++count;
            printf("String: %s", str);
        };

        /* Style */
        /* TODO: 
            - Find <style> tag
            - Copy all text inside <style> tag to *.css file
        */
        if (find_string(str, "<style>") > 0)
        {
            printf("Style tag is finded: %s", str);
            in_style_tag = TRUE;
        };

        if (find_string(str, "</style>") > 0)
        {
            in_style_tag = FALSE;
        }

        if (in_style_tag)
        {
            printf("%s", str);
        }

        /* Script */
        /* TODO: 
            - Find <script> tag
            - Copy all text inside <style> tag to *.js file
        */
        if (find_string(str, "<script>") > 0)
        {
            printf("Script tag is finded: %s", str);
            in_script_tag = TRUE;
        };

        if (find_string(str, "</script>") > 0)
        {
            in_script_tag = FALSE;
        }

        if (in_script_tag)
        {
            printf("%s", str);
        }
    }
    printf("Count %d\n\n", count);
    fclose(fptr);
}