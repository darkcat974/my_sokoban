/*
** EPITECH PROJECT, 2022
** B-PSU-200-RUN-2-1-mysokoban-florian.dajon
** File description:
** main
*/
#include "sokoban.h"

int is_init(char c, char *str)
{
    char *init = "#PXO \n";
    int bn = 0;

    for (int i = 0; str[i]; i++)
        if (str[i] == '\n')
            bn++;
    for (int i = 0; init[i] != '\0'; i++) {
        if (c == init[i])
            return 0;
    }
    return 1;
}

int errors(game_t *game)
{
    if (game->ac < 2)
        return 84;
    if (game->fd == NULL && my_strcmp(game->pathname, "-h") != 1) {
        return 1;
    } else if (game->fd == NULL)
        return 84;
    for (int i = 0; game->buff[i]; i++)
        if (is_init(game->buff[i], game->buff) == 1)
            return 84;
    return 0;
}

int gameloop(game_t *game)
{
    display(game);
    while (1) {
        refresh();
        clear();
        move_all(game);
        for (int i = 0; game->map[i] != NULL; i++)
            printw("%s\n", game->map[i]);
        for (int i = 0; i != game->nb_boxes; i++)
            mvprintw(game->boxe[i].y, game->boxe[i].x, "%s", "X");
        mvprintw(game->p.y, game->p.x, "P");
        if (win_or_reset(game) == 0) {
            return 0;
            }
        if (loose(game) == 1) {
            return 1;
        }
        game->k = getch();
    }
    return 84;
}

void free_all(game_t *game)
{
    free(game->buff);
    for (int i = 0; game->map[i] != NULL; i++)
        free(game->map[i]);
    free(game->map);
    free(game->boxe);
}

int main(int ac, char **av)
{
    game_t game;
    game.ac = ac;
    game.av = av;
    game.pathname = av[ac - 1];
    int i = get_all(&game);

    if (i == 1) {
        my_printf("USAGE\n\t./my_sokoban map\n\nDESCRIPTION\n\tmap\
file representing the warehouse map, containing '#' for walls,\
'P' for the player, 'X' for boxes and 'O' for storage locations.\n");
        return 0;
    }
    if (i != 0)
        return 84;
    initscr();
    curs_set(0);
    i = gameloop(&game);
    endwin();
    free_all(&game);
    return i;
}
