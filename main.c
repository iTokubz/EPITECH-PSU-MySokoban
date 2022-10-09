/*
** EPITECH PROJECT, 2021
** B-PSU-200-STG-2-1-mysokoban-axel.derbisz
** File description:
** main
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include <string.h>
#include "include/sokoban.h"
#include "include/my.h"

sokoban_t *init_struct(void)
{
    sokoban_t *controler = malloc(sizeof(*controler));
    controler->player = malloc(sizeof(player_t));
    controler->buffer = NULL;
    controler->j = 0;
    controler->value = 0;
    controler->player->return_win = 0;
    controler->player->x = 0;
    controler->player->y = 0;
    controler->tab = NULL;
    return (controler);
}

void print_help_menu(void)
{
    char buffer[200];
    size_t len;
    ssize_t bytes_read;
    int fd = open("help_menu.txt", O_RDONLY);
    len = sizeof(buffer);
    bytes_read = read(fd, buffer, len);

    my_putstr(buffer);

}

int read_map_input(char *file, sokoban_t *controler)
{
    struct stat st;
    int fd = 0;
    int size = 0;
    int c = 0;
    fd = open(file, O_RDONLY);
    if (fd == -1)
        return (84);
    stat(file, &st);
    size = st.st_size;
    controler->buffer = malloc(sizeof(char) * (size + 1));
    c = read(fd,  controler->buffer, size);
    controler->buffer[c] = 0;

    return (0);

}

my_count_ligns(sokoban_t *controler)
{
    int count_ligns = 1;

    for (int i = 0; controler->buffer[i]; ++i) {
        if (controler->buffer[i] == '\n')
            ++count_ligns;
    }
    return (count_ligns);
}

void print_map(sokoban_t *controler)
{
    int ligns = my_count_ligns(controler);
    int collumns = 0;

    for (int i = 0; i < ligns; ++i) {
        collumns = my_strlen(controler->tab[i]);
        for (int k = 0; k < collumns; ++k) {
            move(LINES/2 + i, COLS/2 + k);
            printw("%c", controler->tab[i][k]);
        }
    }
}

void detecting_player(sokoban_t *controler)
{
    int ligns = my_count_ligns(controler);
    int collumns = 0;

    for (int i = 0; i < ligns; ++i) {
        collumns = my_strlen(controler->tab[i]);
        for (int k = 0; k < collumns; ++k) {
            if (controler->tab[i][k] == 'P') {
                controler->player->x = k;
                controler->player->y = i;
            }
        }
    }
    move(LINES/2 + controler->player->y, COLS/2 + controler->player->x);
}

void init_ncurses(void)
{
    initscr();
    curs_set(0);
    noecho();
}

void move_boite_down(sokoban_t *controler)
{
    if (controler->tab[controler->player->y - 2][controler->player->x] == ' ') {
        controler->tab[controler->player->y][controler->player->x] = ' ';
        controler->tab[controler->player->y - 1][controler->player->x] = 'P';
        controler->tab[controler->player->y - 2][controler->player->x] = 'X';
    }
}

void move_boite_up(sokoban_t *controler)
{
    if (controler->tab[controler->player->y + 2][controler->player->x] == ' ') {
        controler->tab[controler->player->y][controler->player->x] = ' ';
        controler->tab[controler->player->y + 1][controler->player->x] = 'P';
        controler->tab[controler->player->y + 2][controler->player->x] = 'X';
    }
}

void move_to_up(sokoban_t *controler)
{
    if (controler->tab[controler->player->y - 1][controler->player->x] == ' ') {
        controler->tab[controler->player->y][controler->player->x] = ' ';
        controler->tab[controler->player->y - 1][controler->player->x] = 'P';
    }
    if (controler->tab[controler->player->y - 1][controler->player->x] == 'X') {
        move_boite_down(controler);
    }
    if (controler->tab[controler->player->y - 1][controler->player->x] == 'O') {
        controler->tab[controler->player->y][controler->player->x] = ' ';
        controler->tab[controler->player->y - 1][controler->player->x] = 'P';
    }
    if ((controler->tab[controler->player->y - 2][controler->player->x] == 'O') &&
    (controler->tab[controler->player->y - 1][controler->player->x] == 'X')) {
        controler->tab[controler->player->y][controler->player->x] = ' ';
        controler->tab[controler->player->y - 1][controler->player->x] = 'P';
        controler->tab[controler->player->y - 2][controler->player->x] = 'X';
    }
}

void move_to_down(sokoban_t *controler)
{
    if (controler->tab[controler->player->y + 1][controler->player->x] == ' ') {
        controler->tab[controler->player->y][controler->player->x] = ' ';
        controler->tab[controler->player->y + 1][controler->player->x] = 'P';
    }
    if (controler->tab[controler->player->y + 1][controler->player->x] == 'X') {
        move_boite_up(controler);
    }
    if (controler->tab[controler->player->y + 1][controler->player->x] == 'O') {
        controler->tab[controler->player->y][controler->player->x] = ' ';
        controler->tab[controler->player->y + 1][controler->player->x] = 'P';
    }
    if (controler->tab[controler->player->y + 2][controler->player->x] == 'O' &&
    controler->tab[controler->player->y + 1][controler->player->x] == 'X') {
        controler->tab[controler->player->y][controler->player->x] = ' ';
        controler->tab[controler->player->y + 1][controler->player->x] = 'P';
        controler->tab[controler->player->y + 2][controler->player->x] = 'X';
    }

}

void move_boite_right(sokoban_t *controler)
{
    if (controler->tab[controler->player->y][controler->player->x + 2] == ' ') {
        controler->tab[controler->player->y][controler->player->x] = ' ';
        controler->tab[controler->player->y][controler->player->x + 1] = 'P';
        controler->tab[controler->player->y][controler->player->x + 2] = 'X';
    }
}

void move_to_right(sokoban_t *controler)
{
    if (controler->tab[controler->player->y][controler->player->x + 1] == ' ') {
        controler->tab[controler->player->y][controler->player->x] = ' ';
        controler->tab[controler->player->y][controler->player->x + 1] = 'P';
    }
    if (controler->tab[controler->player->y][controler->player->x + 1] == 'X')
        move_boite_right(controler);
    if (controler->tab[controler->player->y][controler->player->x + 1] == 'O') {
        controler->tab[controler->player->y][controler->player->x] = ' ';
        controler->tab[controler->player->y][controler->player->x + 1] = 'P';
    }
    if (controler->tab[controler->player->y][controler->player->x + 2] == 'O' &&
    controler->tab[controler->player->y][controler->player->x + 1] == 'X') {
        controler->tab[controler->player->y][controler->player->x] = ' ';
        controler->tab[controler->player->y][controler->player->x + 1] = 'P';
        controler->tab[controler->player->y][controler->player->x + 2] = 'X';
    }

}

void move_boite_left(sokoban_t *controler)
{
    if (controler->tab[controler->player->y][controler->player->x - 2] == ' ') {
        controler->tab[controler->player->y][controler->player->x] = ' ';
        controler->tab[controler->player->y][controler->player->x - 1] = 'P';
        controler->tab[controler->player->y][controler->player->x - 2] = 'X';
    }
}

void move_to_left(sokoban_t *controler)
{
    if (controler->tab[controler->player->y][controler->player->x - 1] == ' ') {
        controler->tab[controler->player->y][controler->player->x] = ' ';
        controler->tab[controler->player->y][controler->player->x - 1] = 'P';
    }
    if (controler->tab[controler->player->y][controler->player->x - 1] == 'X')
        move_boite_left(controler);
    if (controler->tab[controler->player->y][controler->player->x - 1] == 'O') {
        controler->tab[controler->player->y][controler->player->x] = ' ';
        controler->tab[controler->player->y][controler->player->x - 1] = 'P';
    }
    if (controler->tab[controler->player->y][controler->player->x - 2] == 'O' &&
    controler->tab[controler->player->y][controler->player->x - 1] == 'X') {
        controler->tab[controler->player->y][controler->player->x] = ' ';
        controler->tab[controler->player->y][controler->player->x - 1] = 'P';
        controler->tab[controler->player->y][controler->player->x - 2] = 'X';
    }
}

void check_move_player(sokoban_t *controler)
{
    while (getch() < 0);
    int key = getch();
    switch (key) {
    case 65:
        if (controler->tab[controler->player->y - 1][controler->player->x] == '#')
            break;
        move_to_up(controler);
        break;
    case 66:
        if (controler->tab[controler->player->y + 1][controler->player->x] == '#')
            break;
        move_to_down(controler);
        break;
    case 67:
        if (controler->tab[controler->player->y][controler->player->x + 1] == '#')
            break;
        move_to_right(controler);
        break;
    case 68:
        if (controler->tab[controler->player->y][controler->player->x - 1] == '#')
            break;
        move_to_left(controler);
        break;
    }
}

void replacing(sokoban_t *controler)
{
    for (int i = 0; i < controler->nbr_o; ++i) {
        if (controler->tab[controler->pos_box[i].y][controler->pos_box[i].x] == ' ')
            controler->tab[controler->pos_box[i].y][controler->pos_box[i].x] = 'O';
    }
}

void win_conditions(sokoban_t *controler)
{
    int temp = 0;

    for (int i = 0; i < controler->nbr_o; ++i) {
        if (controler->tab[controler->pos_box[i].y][controler->pos_box[i].x] == 'X')
            ++temp;
    }
    if (temp == controler->nbr_o) {
        controler->value = 0;
        controler->j = WIN;
    }
}

void lose_conditions(sokoban_t *controler)
{
    int counter = 0;

     for (int i = 0; i < controler->nbr_x; ++i) {
        if ((controler->tab[controler->pos_x[i].y + 1][controler->pos_x[i].x] == '#' &&
            controler->tab[controler->pos_x[i].y][controler->pos_x[i].x + 1] == '#') ||
            (controler->tab[controler->pos_x[i].y - 1][controler->pos_x[i].x] == '#'
            && controler->tab[controler->pos_x[i].y][controler->pos_x[i].x + 1] == '#') ||
            (controler->tab[controler->pos_x[i].y + 1][controler->pos_x[i].x] == '#'
            && controler->tab[controler->pos_x[i].y][controler->pos_x[i].x - 1] == '#')
            || (controler->tab[controler->pos_x[i].y - 1][controler->pos_x[i].x] == '#'
            && controler->tab[controler->pos_x[i].y][controler->pos_x[i].x - 1] == '#'))
            ++counter;
    }
    if (counter == controler->nbr_x) {
        controler->value = 1;
        controler->j = LOSE;
    }
}

void game_loop(sokoban_t *controler)
{
    init_ncurses();
    while (controler->j == 0) {
        print_map(controler);
        detecting_player(controler);
        while (getch() < 0);
        check_move_player(controler);
        replacing(controler);
        win_conditions(controler);
        store_x_positions(controler);
        lose_conditions(controler);
    }
    refresh();
    endwin();
}

int save_x_positions(sokoban_t *controler)
{
    int temp = 0;

    for (int i = 0; controler->buffer[i]; ++i) {
        if (controler->buffer[i] == 'O')
            ++temp;
    }
    return (temp);
}

int save_o_positions(sokoban_t *controler)
{
    int temp = 0;

    for (int i = 0; controler->buffer[i]; ++i) {
        if (controler->buffer[i] == 'O')
            ++temp;
    }
    return (temp);
}

void store_o_positions(sokoban_t *controler)
{
    int y = 0;

    for (int i = 0; controler->tab[i]; ++i) {
        for (int a = 0; controler->tab[i][a]; ++a) {
            if (controler->tab[i][a] == 'O') {
                controler->pos_box[y].x = a;
                controler->pos_box[y].y = i;
                ++y;
            }
        }
    }
}

void store_x_positions(sokoban_t *controler)
{
    int y = 0;

    for (int i = 0; controler->tab[i]; ++i) {
        for (int a = 0; controler->tab[i][a]; ++a) {
            if (controler->tab[i][a] == 'X') {
                controler->pos_x[y].x = a;
                controler->pos_x[y].y = i;
                ++y;
            }
        }
    }
}

void preparations(sokoban_t *controler)
{
    controler->tab = my_str_to_word_tab(controler->buffer);
    controler->nbr_x = save_x_positions(controler);
    controler->nbr_o = save_o_positions(controler);
    controler->pos_x = malloc(sizeof(pos_x_t) * (controler->nbr_x));
    controler->pos_box = malloc(sizeof(box_t) * (controler->nbr_o));
    store_o_positions(controler);
    store_x_positions(controler);

}

int main(int ac, char **av)
{
    sokoban_t *controler = init_struct();
    if (my_strcmp(av[1], "-h") == 0)
        print_help_menu();
    if (read_map_input(av[1], controler) == 84)
        return (84);
    preparations(controler);
    game_loop(controler);
    return (controler->value);
}

