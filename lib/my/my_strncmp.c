/*
** EPITECH PROJECT, 2020
** strncmp1
** File description:
** strncmp1
*/

int  my_strncmp(char  const *s1 , char  const *s2 , int n)
{
    int str1 = 0;
    int str2 = 0;
    int res = 0;

    for (int i = 0; i <= n - 1; ++i) {
        str1 = str1 + s1[i];
    }
    for (int i = 0; i <= n - 1; ++i) {
        str2 = str2 + s2[i];
    }
    res = str1 - str2;

    return (res);
}