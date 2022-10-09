/*
** EPITECH PROJECT, 2020
** str_to_word_array
** File description:
** str_to_word_array
*/

#include <stddef.h>
#include <stdlib.h>
#include "../../include/seperates_words.h"

int count_len_tab(char *str, DT_t *data)
{
    int counter = 1;
    int i = 0;
    for (; str[i]; ++i) {
        if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z') {
            break;
        }
    }
    for (; str[i]; ++i) {
        if (str[i] < 'A' || str[i] > 'Z' &&
        str[i] < 'a' || str[i] > 'z') {
            if (str[i + 1] >= 'A' && str[i + 1] <= 'Z'
            || str[i + 1] >= 'a' && str[i + 1] <= 'z')
                ++counter;
        }
    }
    return (counter);
}

int skip_before_first_word(char *str, int i)
{
    for (; str[i]; ++i) {
        if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z')
            return (i);
    }
    return (0);
}

int good_malloc_size(char *str, DT_t *data)
{
    if (data->a == 0) {
        for (; str[data->i]; data->i++) {
            if (str[data->i] >= 'a' && str[data->i] <= 'z' ||
             str[data->i] >= 'A' && str[data->i] <= 'Z')
                break;
        }
    }
    data->a = 1;
    for (; str[data->i]; data->i++) {
        if (str[data->i] < 'A' || str[data->i] > 'Z' &&
        str[data->i] < 'a' || str[data->i] > 'z')
            break;
        data->counter++;
    }
    return (0);
}

char **malloc_my_tab(int len, char *str, DT_t *data)
{
    char **tab = malloc(sizeof(char *) * (len + 1));
    tab[len] = NULL;
    data->i = 0;
    data->a = 0;

    for (int k = 0; k != len; ++k) {
        good_malloc_size(str, data);
        tab[k] = malloc(sizeof(char) * (data->counter + 1));
        tab[k][data->counter] = 0;
        data->i++;
        data->counter = 0;
    }
    return (tab);
}

char **my_str_to_word_array(char *str)
{
    DT_t *data = malloc(sizeof(DT_t));
    int len_for_tab = count_len_tab(str, data);
    char **tab = malloc_my_tab(len_for_tab, str, data);
    int a = 0;
    int j = 0;
    int i = 0;

    i = skip_before_first_word(str, i);
    for (; str[i]; ++i) {
        if (str[i] < 'A' || str[i] > 'Z' && str[i] < 'a' || str[i] > 'z') {
            if (str[i + 1] >= 'A' && str[i + 1] <= 'Z' ||
            str[i + 1] >= 'a' && str[i + 1] <= 'z') {
                ++a;
                j = 0;
                continue;
            }
            continue;
        }
        if (str[i] >= 'A' && str[i] <= 'Z' ||
        str[i] >= 'a' && str[i] <= 'z') {
            tab[a][j] = str[i];
            ++j;
        }
    }
    return (tab);
}