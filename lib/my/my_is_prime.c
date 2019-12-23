/*
** EPITECH PROJECT, 2019
** my_is_prime
** File description:
** prime
*/

int my_is_prime(int nb)
{
    int d = 2;
    int type = 1;

    if (nb <= 0 || nb == 1) {
        type = 0;
        return type;
    }
    while (d < nb / 2) {
        if (nb % d == 0 && d != nb) {
            type = 0;
            return type;
        }
        d++;
    }
    return type;
}
