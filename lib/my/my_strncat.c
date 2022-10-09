/*
** EPITECH PROJECT, 2020
** my_strncat
** File description:
** my_strncat
*/

char *my_strncat(char *dest, char  const *src, int nb)
{
    int i = 0;

    for (; dest[i]; ++i);

    for (int k = 0; k != nb; ++k) {
        dest[i] = src[k];
        ++i;
    }
    dest[i] = '\0';

    return (dest);
}