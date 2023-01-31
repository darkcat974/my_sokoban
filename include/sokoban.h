/*
** EPITECH PROJECT, 2022
** B-PSU-200-RUN-2-1-mysokoban-florian.dajon
** File description:
** my
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ncurses.h>
#include <signal.h>
#include "my.h"

#ifndef SOKOBAN_H_
    #define SOKOBAN_H_

typedef struct objet {
    int x;
    int y;
    int o_x;
    int o_y;
}objet_t;

typedef struct game {
    int k;
    int ac;
    int nbb;
    int nbo;
    int size;
    char *pathname;
    int nb_boxes;
    char *buff;
    char **av;
    char **map;
    FILE *fd;
    objet_t p;
    objet_t *boxe;
}game_t;

int errors(game_t *game);
void get_map(game_t *game);
int get_player(game_t *game);
int get_boxes(game_t *game);
int get_all(game_t *game);
void move_player(game_t *game);
void move_boxes(game_t *game);
void move_all(game_t *game);
int hitboxe(int x, int y, objet_t *boxe, int nb_boxes);
int win_or_reset(game_t *game);
int loose(game_t *game);
char **my_str_to_word_array(char const *str, char const *sep);
int main(int ac, char **av);
void free_all(game_t *game);
void display(game_t *game);

#endif
