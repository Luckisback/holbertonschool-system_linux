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

int main(void)
{
DIR *dir;
struct dirent *entry;

dir = opendir(".");
if (dir == NULL)
{
perror("opendir");
exit(EXIT_FAILURE);
}
/*Ignore hidden files and directories*/
while ((entry = readdir(dir)) != NULL)
{
if (entry->d_name[0] != '.')
{
printf("%s  ", entry->d_name);
}
}
printf("\n");

closedir(dir);

return (EXIT_SUCCESS);
}
