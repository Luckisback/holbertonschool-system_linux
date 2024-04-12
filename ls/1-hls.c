#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>


/**
 * main - This program opens the current directory with opendir("."),
 * then browses each entry in this directory with readdir and displays
 * the name of each entry with printf. Finally, it closes the directory
 * with closedir
 * Return: EXIT_SUCCESS
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
printf("%s ", entry->d_name);
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
for (int i = 1; i < argc; i++) {
list_directory(argv[i]);
}
}

return (EXIT_SUCCESS);
}