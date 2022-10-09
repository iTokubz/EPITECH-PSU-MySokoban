/*
** EPITECH PROJECT, 2020
** array
** File description:
** array
*/

void my_putchar(char c);

void my_putstr(char const *str);

int my_show_word_array(char * const *tab)
{
    for (int i = 0; tab[i]; ++i) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
}