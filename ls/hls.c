#include "hls.h"

/*retrieve a directory argument, to list the contents.
If no argument is given, then take the current directory*/

int main(int argc, char *argv[])
{
const char *directory;

if (argc == 1)
{
directory = ".";
}
else if (argc == 2)
{
directory = argv[1];
}
else
{
fprintf(stderr, "Usage: %s [directory]\n", argv[0]);
exit(EXIT_FAILURE);
}

hls(directory);

return (EXIT_SUCCESS);
}
