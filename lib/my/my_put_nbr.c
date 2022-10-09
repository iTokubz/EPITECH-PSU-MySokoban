/*
** EPITECH PROJECT, 2020
** put_br
** File description:
** put_nbr
*/

void my_putchar(char c);

void my_put_nbr(int nb)
{
    int k = 0;

    if (nb < 0) {
        my_putchar('-');
        if (nb == -2147483648) {
            nb = nb / 10;
            k = 1;
        }
        nb = nb * -1;
    }
    if (nb >= 10)
        my_put_nbr(nb / 10);
    my_putchar(nb % 10 + 48);
    if (k == 1)
        my_putchar(8 + 48);
}