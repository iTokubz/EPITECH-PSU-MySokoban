/*
** EPITECH PROJECT, 2020
** strupcase
** File description:
** strupcase
*/

char *my_strupcase(char *str)
{
    for (int i = 0; str[i]; ++i) {
        str[i] = str[i] - 32;
    }
    return (str);
}