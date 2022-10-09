/*
** EPITECH PROJECT, 2020
** strisalpha
** File description:
** strisalpha
*/

int my_str_isalpha(char const *str)
{
    if (!str)
        return (1);

    for (int i = 0; str[i]; ++i) {
        if (str[i] > 122 || str[i] < 65)
            return (0);
    }
    return (1);
}