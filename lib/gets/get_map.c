/*
** EPITECH PROJECT, 2022
** B-PSU-200-RUN-2-1-mysokoban-florian.dajon
** File description:
** get_map
*/
#include "sokoban.h"

void get_map(game_t *game)
{
    struct stat st;
    game->fd = fopen(game->pathname, "r+");
    stat(game->pathname, &st);
    if (game->fd == NULL)
        return;
    if (st.st_size == 0) {
        game->fd = NULL;
        return;
    }
    game->fd = fopen(game->av[game->ac - 1], "r+");
    game->buff = malloc(sizeof(char) * st.st_size);
    fread(game->buff, st.st_size, 1, game->fd);
    game->buff[st.st_size] = '\0';
    game->map = my_str_to_word_array(game->buff, "\n");
    fclose(game->fd);
}
