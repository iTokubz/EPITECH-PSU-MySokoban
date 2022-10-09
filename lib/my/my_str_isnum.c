/*
** EPITECH PROJECT, 2020
** isnum
** File description:
** isnum
*/

int  my_str_isnum(char  const *str)
{
    if (!str)
        return (1);

    for (int i = 0; str[i]; ++i) {
        if (str[i] > 57 || str[i] < 48)
            return (0);
    }
    return (1);
}

