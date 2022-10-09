/*
** EPITECH PROJECT, 2020
** strlen1
** File description:
** strlen1
*/

int my_strlen(char const *str)
{
    int i = 0;

    for (; str[i]; ++i);
    return (i);
}