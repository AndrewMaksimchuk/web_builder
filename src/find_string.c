#include "types.h"


BOOLEAN find_string(char line[], char pattern[])
{
    int i, j, k;
    for (i = 0; line[i] != '\0'; i++)
    {
        for (j = i, k = 0; pattern[k] != '\0' && line[j] == pattern[k]; j++, k++)
            ;
        if (k > 0 && pattern[k] == '\0')
            return TRUE; // Found
    }
    return FALSE; // Not found
}