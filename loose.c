/*
** EPITECH PROJECT, 2022
** B-PSU-200-RUN-2-1-mysokoban-florian.dajon
** File description:
** cornered
*/
#include "sokoban.h"

int topleft(game_t *game, objet_t boxe)
{
    if ((game->map[boxe.y - 1][boxe.x] == '#'
        || game->map[boxe.y - 1][boxe.x] == 'X')
        && (game->map[boxe.y][boxe.x - 1] == '#'
        || game->map[boxe.y][boxe.x - 1] == 'X'))
        return 1;
    return 0;
}

int topright(game_t *game, objet_t boxe)
{
    if ((game->map[boxe.y - 1][boxe.x] == '#'
        || game->map[boxe.y - 1][boxe.x] == 'X')
        && (game->map[boxe.y][boxe.x + 1] == '#'
        || game->map[boxe.y][boxe.x + 1] == 'X'))
        return 1;
    return 0;
}

int downleft(game_t *game, objet_t boxe)
{
    if ((game->map[boxe.y + 1][boxe.x] == '#'
        || game->map[boxe.y + 1][boxe.x] == 'X')
        && (game->map[boxe.y][boxe.x - 1] == '#'
        || game->map[boxe.y][boxe.x - 1] == 'X'))
        return 1;
    return 0;
}

int downright(game_t *game, objet_t boxe)
{
    if ((game->map[boxe.y + 1][boxe.x] == '#'
        || game->map[boxe.y + 1][boxe.x] == 'X')
        && (game->map[boxe.y][boxe.x + 1] == '#'
        || game->map[boxe.y][boxe.x + 1] == 'X'))
        return 1;
    return 0;
}

int loose(game_t *game)
{
    int counter = 0;

    for (int i = 0; game->nb_boxes > i; i++)
        if (topleft(game, game->boxe[i]) + topright(game, game->boxe[i])
        + downleft(game, game->boxe[i]) + downright(game, game->boxe[i]) > 0)
            counter++;
    if (counter == game->nb_boxes) {
        display(game);
        usleep(1000000);
        return 1;
    }
    return 0;
}
