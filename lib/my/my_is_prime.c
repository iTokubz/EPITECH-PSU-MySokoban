/*
** EPITECH PROJECT, 2020
** prime
** File description:
** primze
*/

int my_is_prime(int nb)
{
    int index = 2;

    for (; index != nb; ++index) {
        if (nb % index == 0)
            return (0);
    }
    return (1);
}