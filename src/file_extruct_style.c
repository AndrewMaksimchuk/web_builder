// Extruct css from <style> tag then put to file *.css 
// thet include to html header


#include "file_open.c"
#include "file_close.c"

void file_extruct_style(char* fpath)
{
    FILE* fptr = file_open(fpath);

    file_close(fptr);
}

// read file

// find <style> tag

// get text inside tag

// copy to *.css file

// save file
