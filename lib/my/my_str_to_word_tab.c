/*
** EPITECH PROJECT, 2020
** str
** File description:
** str
*/

#include <stdlib.h>
#include <stddef.h>
#include "../../include/my.h"
#include "../../include/seperates_words.h"
#include <stdio.h>

int count_words(char *str)
{
    int count_words = 1;

    for (int i = 0; str[i]; ++i) {
        if (str[i] == '\n') {
            ++count_words;
        }
    }
    return (count_words);
}

void separate_words(char *str, struct DT *var)
{
    var->counter = 0;

    for (; str[var->i] != '\0'; var->i++) {
        if (str[var->i] == '\n')
            break;
        var->counter++;
    }
}

char **my_malloc_tab(int count_words, char *str, struct DT *var)
{
    char **tab = malloc(sizeof(char *) * (count_words + 1));
    tab[count_words] = NULL;
    var->i = 0;

    for (int a = 0; a != count_words; ++a) {
        separate_words(str, var);
        tab[a] = malloc(sizeof(char) * (var->counter + 1));
        tab[a][var->counter] = 0;
        var->i++;
}
    return (tab);
}

char **my_str_to_word_tab(char *str)
{
    struct DT *var = malloc(sizeof(struct DT));
    int count = count_words(str);
    char **tab = my_malloc_tab(count, str, var);
    int k = 0;
    int a = 0;

    for (int i = 0; str[i]; ++i) {
        if (str[i] == '\n') {
            ++a;
            k = 0;
            ++i;
        }
        tab[a][k] = str[i];
        ++k;
    }
    return (tab);
}