/*
** EPITECH PROJECT, 2020
** isneg.c
** File description:
** isneg.c
*/

void my_putchar(char c);

int my_isneg(int n)
{
    if (n >= 0)
        my_putchar('P');
    else
        my_putchar('N');
    return (0);
}