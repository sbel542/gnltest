#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return (1);
    }

    char *line = get_next_line(fd);
    while (line)
    {
        printf("Read line: %s", line);
        free(line);
	line = get_next_line(fd);
    }
    if (!line)
        printf("get_next_line returned NULL\n");

    close(fd);
    return (0);
}

