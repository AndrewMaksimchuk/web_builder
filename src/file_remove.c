void file_remove(char *file)
{
    if (remove(file) == 0)
        printf("Deleted successfully\n");
    else
        printf("Unable to delete the file\n");
}