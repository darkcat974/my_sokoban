/*
** EPITECH PROJECT, 2022
** B-PSU-200-RUN-2-1-mysokoban-florian.dajon
** File description:
** move_objet
*/
#include "sokoban.h"

int hitboxe(int y, int x, objet_t *boxe, int nb_boxes)
{
    for (int i = 0; i != nb_boxes; i++)
        if (boxe[i].x == x && boxe[i].y == y)
            return 0;
    return 1;
}

void move_player(game_t *game)
{
    if (game->k == 65
    && (hitboxe(game->p.y - 1, game->p.x, game->boxe, game->nb_boxes) == 1
    && game->map[game->p.y - 1][game->p.x] != '#'))
        game->p.y--;
    if (game->k == 66
    && (hitboxe(game->p.y + 1, game->p.x, game->boxe, game->nb_boxes) == 1
    && game->map[game->p.y + 1][game->p.x] != '#'))
        game->p.y++;
    if (game->k == 68
    && (hitboxe(game->p.y, game->p.x - 1, game->boxe, game->nb_boxes) == 1
    && game->map[game->p.y][game->p.x - 1] != '#'))
        game->p.x--;
    if (game->k == 67
    && (hitboxe(game->p.y, game->p.x + 1, game->boxe, game->nb_boxes) == 1
    && game->map[game->p.y][game->p.x + 1] != '#'))
        game->p.x++;
}

void move_all(game_t *game)
{
    move_boxes(game);
    move_player(game);
}
