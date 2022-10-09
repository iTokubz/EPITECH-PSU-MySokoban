/*
** EPITECH PROJECT, 2020
** square
** File description:
** square
*/

int my_compute_square_root(int nb)
{
    int n = 1;

    if (nb < 0)
        return (0);

    while (n * n != nb) {
        if ((n * n) > nb)
            return (0);
        ++n;
    }
    return (n);
}