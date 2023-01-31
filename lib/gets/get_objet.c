/*
** EPITECH PROJECT, 2022
** B-PSU-200-RUN-2-1-mysokoban-florian.dajon
** File description:
** get_objet
*/
#include "sokoban.h"

int get_all(game_t *game)
{
    get_map(game);
    if (errors(game) == 1)
        return 1;
    if (errors(game) == 84 || get_player(game) > 1 || get_boxes(game) == 1)
        return 84;
    return 0;
}
