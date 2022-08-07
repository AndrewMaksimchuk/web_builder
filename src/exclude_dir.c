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