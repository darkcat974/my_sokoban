/*
** EPITECH PROJECT, 2022
** B-PSU-200-RUN-2-1-mysokoban-florian.dajon
** File description:
** move_boxes
*/
#include "sokoban.h"

void box_up(game_t *game)
{
    if (game->k == 65 && hitboxe(game->boxe[game->nbb].y - 1,
    game->boxe[game->nbb].x, game->boxe, game->nb_boxes) != 0
    && game->map[game->boxe[game->nbb].y - 1][game->boxe[game->nbb].x] != '#')
        game->boxe[game->nbb].y--;
}

void box_down(game_t *game)
{
    if (game->k == 66 && hitboxe(game->boxe[game->nbb].y + 1,
    game->boxe[game->nbb].x, game->boxe, game->nb_boxes) != 0
    && game->map[game->boxe[game->nbb].y + 1][game->boxe[game->nbb].x] != '#')
        game->boxe[game->nbb].y++;
}

void box_left(game_t *game)
{
    if (game->k == 68 && hitboxe(game->boxe[game->nbb].y,
    game->boxe[game->nbb].x - 1, game->boxe, game->nb_boxes) != 0
    && game->map[game->boxe[game->nbb].y][game->boxe[game->nbb].x - 1] != '#')
        game->boxe[game->nbb].x--;
}

void box_right(game_t *game)
{
        if (game->k == 67 && hitboxe(game->boxe[game->nbb].y,
        game->boxe[game->nbb].x + 1, game->boxe, game->nb_boxes) != 0
        && game->map[game->boxe[game->nbb].y]
        [game->boxe[game->nbb].x + 1] != '#')
            game->boxe[game->nbb].x++;
}

void move_boxes(game_t *game)
{
    for (game->nbb = 0; game->nbb != game->nb_boxes; game->nbb++) {
        if (game->boxe[game->nbb].x == game->p.x
        && game->boxe[game->nbb].y == game->p.y - 1)
            box_up(game);
        if (game->boxe[game->nbb].x == game->p.x
        && game->boxe[game->nbb].y == game->p.y + 1)
            box_down(game);
        if (game->boxe[game->nbb].x == game->p.x - 1
        && game->boxe[game->nbb].y == game->p.y)
            box_left(game);
        if (game->boxe[game->nbb].x == game->p.x + 1
        && game->boxe[game->nbb].y == game->p.y)
            box_right(game);
    }
}
