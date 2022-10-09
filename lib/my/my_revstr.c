/*
** EPITECH PROJECT, 2020
** rev_str
** File description:
** rev_str
*/

int count_len2(char *str)
{
    int i = 0;

    for (; str[i]; ++i);
    return (i);
}

char *my_revstr(char *str)
{
    char temp = 0;
    int len = count_len2(str) - 1;

    for (int i = 0; i < len; ++i) {
        temp = str[i];
        str[i] = str[len];
        str[len] = temp;
        --len;
    }
    return (str);
}