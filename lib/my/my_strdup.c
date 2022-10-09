/*
** EPITECH PROJECT, 2020
** strdup1
** File description:
** strdup1
*/

#include "../../include/my.h"
#include <stdlib.h>

char *my_strdup(char const *src)
{
    int i = my_strlen(src);
    int a = 0;
    char *str;

    str = malloc(sizeof(char) * (i));
    for (; i > 0; --i) {
        str[a] = src[a];
        ++a;
    }
    return (str);
}