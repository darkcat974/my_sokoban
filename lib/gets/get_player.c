/*
** EPITECH PROJECT, 2022
** B-PSU-200-RUN-2-1-mysokoban-florian.dajon
** File description:
** get_player
*/
#include "sokoban.h"

int player_pos_x(char *map)
{
    for (int x = 0; map[x] != '\0'; x++) {
        if (map[x] == 'P')
            return x;
    }
    return 0;
}

int get_player(game_t *game)
{
    game->p.x = 0;
    game->p.y = 0;
    int nb_player = 0;
    for (int y = 0; game->map[y] != NULL; y++) {
        if (player_pos_x(game->map[y]) > 0) {
            game->p.x = player_pos_x(game->map[y]);
            game->map[y][player_pos_x(game->map[y])] = ' ';
            game->p.y = y;
            game->p.o_x = game->p.x;
            game->p.o_y = game->p.y;
            nb_player++;
        }
    }
    return nb_player;
}
