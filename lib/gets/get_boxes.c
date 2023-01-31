/*
** EPITECH PROJECT, 2022
** B-PSU-200-RUN-2-1-mysokoban-florian.dajon
** File description:
** get_boxes
*/
#include "sokoban.h"

int how_many(char *map)
{
    int counter = 0;

    for (int i = 0; map[i] != '\0'; i++)
        if (map[i] == 'X')
            counter++;
    return counter;
}

void get_x(game_t *game, char *map, int y)
{
    for (int x = 0; map[x] != '\0'; x++) {
        if (map[x] == 'X') {
            game->map[y][x] = ' ';
            game->boxe[game->nbb].x = x;
            game->boxe[game->nbb].y = y;
            game->boxe[game->nbb].o_x = x;
            game->boxe[game->nbb].o_y = y;
            game->nbb++;
        }
        if (map[x] == 'O')
            game->nbo++;
    }
}

int get_boxes(game_t *game)
{
    game->nb_boxes = how_many(game->buff);
    game->nbb = 0;
    game->boxe = malloc(sizeof(objet_t) * game->nb_boxes);

    for (int y = 0; game->map[y] != NULL; y++) {
        get_x(game, game->map[y], y);
    }
    if (game->nbb != game->nbo)
        return 1;
    return 0;
}
