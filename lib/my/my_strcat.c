/*
** EPITECH PROJECT, 2020
** strcat47
** File description:
** strcat47
*/

#include <stdlib.h>
#include "../../include/my.h"

char *my_strcat(char *dest, char *src)
{
    int i = 0;
    int j = 0;
    char *str =
    malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));

    while (dest && dest[i]) {
        str[i] = dest[i];
        i++;
    }
    while (src && src[j]) {
        str[i] = src[j];
        j++;
        i++;
    }
    str[i] = 0;
    return (str);
}
