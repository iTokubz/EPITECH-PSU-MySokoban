/*
** EPITECH PROJECT, 2020
** repo_day10
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#include <stdio.h>

void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char *src);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strdup(char const *src);
int my_show_word_array(char * const *tab);
int fs_open_map(char *filepath);
int check_nbr_boats(char **av, int ac);
int checking_boats(FILE *fd);
int check_letter_boats_files(char *boats);
int checking_files(char **av, int ac);
char **my_path_to_word_array(char *str);
char **my_str_to_word_tab(char *str);
int check_pid(char **av, int ac);
int checking(char *str);
char **my_str_to_word_array(char *str);
void set_prompt(void);
char *my_strstr(char *str, char const *to_find);
void print_help_menu(void);
char *hit_or_missed(int is_touched);
int check_attack_valid(char *str);
void print_infos_p2_hit_or_not(char *enemy_attack, int is_touched);

#endif /* !MY_H_ */
