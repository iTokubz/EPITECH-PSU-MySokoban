/*
** EPITECH PROJECT, 2020
** isupper
** File description:
** isupper
*/

int my_str_isupper(char const *str)
{
    for (int i = 0; str[i]; +i) {
        if (str[i] > 90 || str[i] < 65)
            return (0);
    }
    return (1);
}