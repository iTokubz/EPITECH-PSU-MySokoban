/*
** EPITECH PROJECT, 2020
** prime
** File description:
** prime
*/

int my_find_prime(int nb)
{
    int index = 2;

    for (; index != nb; ++index) {
        if (nb % index == 0)
            return (nb);
    }
    return (0);
}

int my_find_prime_sup(int nb)
{
    while (my_find_prime(nb)) {
        ++nb;
    }
    return (nb);
}