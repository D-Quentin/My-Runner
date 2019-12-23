/*
** EPITECH PROJECT, 2019
** my_find_prime_sup
** File description:
** primee
*/

void my_putchar(char c);

int my_find_prime_sup(int nb)
{
    int d = 2;

    if (nb <= 0 || nb == 1)
        nb = my_find_prime_sup(nb + 1);
    while (d < nb / 2) {
        if (nb % d == 0 && d != nb) {
            nb = my_find_prime_sup(nb + 1);
        }
        d++;
    }
    return (nb);
}
