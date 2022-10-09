/*
** EPITECH PROJECT, 2020
** ncpy
** File description:
** ncpy
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    for (; i != n; ++i) {
        dest[i] = src[i];
    }
    return (dest);
}