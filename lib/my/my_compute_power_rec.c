/*
** EPITECH PROJECT, 2020
** rec_power
** File description:
** rec_power
*/

int my_compute_power_rec(int nb, int p)
{
    int temp = 0;
    int res = nb;

    if (p < 0)
        return (0);
    if (p == 0)
        return (1);

    if (p > 1) {
        temp = my_compute_power_rec(nb, p - 1);
        res = temp * nb;
    }
    return (res);
}