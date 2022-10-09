/*
** EPITECH PROJECT, 2020
** islower
** File description:
** islower
*/

int my_str_islower(char const *str)
{
    if (!str)
        return (1);

    for (int i = 0; str[i]; ++i) {
        if (str[i] < 97 || str[i] > 122)
            return (0);
    }
    return (1);
}