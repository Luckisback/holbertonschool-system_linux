#include "hls.h"


/* The program takes a command-line argument,
which is the path of the directory to be listed.
It opens this directory with 'opendir', then reads
files with 'readdir'.For each entry, it uses lstat
to obtain file information and prints the file name
with printf. Finally, it closes the directory with
closedir */

void hls(const char *directory)
{
DIR *dir;
struct dirent *entry;
struct stat fileStat;

dir = opendir(directory

if (dir == NULL)
{
perror("opendir");
exit(EXIT_FAILURE);
}

while ((entry = readdir(dir)) != NULL)
{
char path[1024];
snprintf(path, sizeof(path), "%s/%s", directory, entry->d_name);

if (lstat(path, &fileStat) < 0)
{
perror("lstat");
continue;
}
printf("%s\t", entry->d_name);
}

closedir(dir);
printf("\n");
}
