/*
** EPITECH PROJECT, 2020
** strcpy1
** File description:
** strcpy1
*/

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    for (; src[i]; ++i) {
        dest[i] = src[i];
    }
    dest[i] = '\0';

    return (dest);
}