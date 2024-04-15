#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>


/**list_directory - descrption
 * dirname: description
 *
 */

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


/**
 * main - imprimer un char
 * list_directory - description
 * @argc: argument count
 * @argv: argument values
 * return: EXIT_SUCCESS
 */

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

return (EXIT_SUCCESS);
}
