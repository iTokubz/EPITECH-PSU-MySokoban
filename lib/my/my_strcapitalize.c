/*
** EPITECH PROJECT, 2020
** capitalize
** File description:
** capitalize
*/

void is_first_letter(char *str, int i)
{
    if (str[i + 1] >= 97 && str[i + 1] <= 122)
        str[i + 1] = str[i + 1] - 32;
}

void check_first_capi(char *str, int i)
{
    if (i == 0 && str[i] >= 97 && str[i] <= 122)
        str[i] = str[i] - 32;
}

char *my_strcapitalize(char *str)
{
    for (int i = 0; str[i]; ++i) {
        check_first_capi(str, i);
        if (str[i] == ' ')
            is_first_letter(str, i);
    }
    return (str);
}