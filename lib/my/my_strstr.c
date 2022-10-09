/*
** EPITECH PROJECT, 2020
** strstrcxzc
** File description:
** strstrcz
*/

#include <stdio.h>
#include <stddef.h>

int check_string(char const *check, char *str, int i, int index)
{
    int counter = 0;

    for (; check[index] && str[i]; ++index) {
        if (check[index] == str[i])
            ++counter;
        ++i;
    }
    return (counter);
}

int count_len3(char const *to_find)
{
    int i = 0;

    for (; to_find[i]; ++i);

    return (i);
}

char *my_strstr(char *str, char const *to_find)
{
    int index = 0;
    int len = count_len3(to_find);
    int is_find = 0;


    if (!str || !to_find)
        return (NULL);
    if (len == 0)
        return (str);
    if (count_len3(str) == 0)
        return (NULL);

    for (int i = 0; str[i]; ++i) {
        if (str[i] == to_find[index]) {
            is_find =  check_string(to_find, str, i, index);
            if (is_find == len)
                return (&str[i]);
        }
    }
    return (NULL);
}