/*
** EPITECH PROJECT, 2022
** B-CPE-110-RUN-1-1-BSQ-florian.dajon
** File description:
** open_file
*/
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "../../include/my.h"

char *open_file(char const *pathname, map_t *map)
{
    int fd = open(pathname, O_RDONLY);
    struct stat info;
    int offset = 0;
    int r = 0;
    stat(pathname, &info);
    if (fd == -1 || info.st_size <= 1) {
        map->raw = NULL;
        map->size = 0;
        return NULL;
    }
    map->raw = malloc(sizeof(char) * info.st_size);
    while (r != -1) {
        offset += r;
        if ((r = read(fd, map->raw + offset, 50)) < 1)
            break;
    }
    map->raw[offset] = '\0';
    return NULL;
}
