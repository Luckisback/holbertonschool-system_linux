#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

/**
 * list_directory - Displays the names of entries in the given directory
 * excluding "." and ".." directories, and hidden files.
 * @dirname: The name of the directory to list.
 **/
void list_directory(const char *dirname)
{
DIR *dir;
struct dirent *entry;

dir = opendir(dirname);
if (dir == NULL)
{
fprintf(stderr, "hls: %s: ", dirname);
perror("");
exit(EXIT_FAILURE);
}

while ((entry = readdir(dir)) != NULL)
{
/* Exclude "." and ".." directories */
if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0)
{

/* Exclude hidden files starting with "." */
if (entry->d_name[0] != '.')
{
printf("%s ", entry->d_name);
}
}
}
printf("\n");

closedir(dir);
}

int main(int argc, char *argv[])
{
if (argc == 1)
{
list_directory(".");
}
else
{
for (int i = 1; i < argc; i++) 
{
list_directory(argv[i]);
}
}

return EXIT_SUCCESS;
}

