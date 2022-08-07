void file_for_each(struct Project_dir dir)
{

    printf("File of: %s\n", dir.name);
    for (int i = 1; i <= dir.size; i++)
    {
        printf("File name: %s\n", dir.files[i].name); // FIXME: name is not show
        printf("File path: %s\n", dir.files[i].path);
        printf("File source: %s\n", dir.files[i].source);

        file_read(dir.files[i].path);
    }
}