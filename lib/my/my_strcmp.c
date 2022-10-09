/*
** EPITECH PROJECT, 2020
** strcmp1
** File description:
** strcmp1
*/

int my_strcmp(char const *s1, char const *s2)
{
    int str1 = 0;
    int str2 = 0;
    int res = 0;

    for (int i = 0; s1[i]; ++i) {
        str1 = str1 + s1[i];
    }
    for (int i = 0; s2[i]; ++i) {
        str2 = str2 + s2[i];
    }
    res = str1 - str2;

    return (res);
}