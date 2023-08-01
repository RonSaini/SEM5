//size_t write(int fildes, const void *buf, size_t nbytes);
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main()
{
if ((write(1, ("Here is some data\n"), 18)) != 18)
write(2, ("A write error has occurred on file descriptor 1\n"),46);
exit(0);
}