/*
** EPITECH PROJECT, 2022
** B-PSU-200-RUN-2-1-mysokoban-florian.dajon
** File description:
** move_objet
*/
#include "sokoban.h"

void move_player(game_t *game)
{
    if (game->k == 65)
        game->p.y--;
    if (game->k == 66)
        game->p.y++;
    if (game->k == 68)
        game->p.x--;
    if (game->k == 67)
        game->p.x++;
}
