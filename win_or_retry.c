/*
** EPITECH PROJECT, 2022
** B-PSU-200-RUN-2-1-mysokoban-florian.dajon
** File description:
** win_or_retry
*/
#include "sokoban.h"

void display(game_t *game)
{
    refresh();
    clear();
    mvprintw(game->p.y, game->p.x, "P");
    for (int i = 0; game->map[i] != NULL; i++)
        printw("%s\n", game->map[i]);
    for (int i = 0; i != game->nb_boxes; i++)
        mvprintw(game->boxe[i].y, game->boxe[i].x, "%s", "X");
}

int win_or_reset(game_t *game)
{
    int counter = 0;

    for (int i = 0; i <= game->nb_boxes - 1; i++) {
        if (game->map[game->boxe[i].y][game->boxe[i].x] == 'O')
            counter++;
    }
    if (game->k == ' ') {
        game->p.x = game->p.o_x;
        game->p.y = game->p.o_y;
        for (int i = 0; game->nb_boxes >= i; i++) {
            game->boxe[i].y = game->boxe[i].o_y;
            game->boxe[i].x = game->boxe[i].o_x;
        }
    }
    if (counter == game->nb_boxes) {
        display(game);
        usleep(1000000);
        return 0;
    }
    return 1;
}
