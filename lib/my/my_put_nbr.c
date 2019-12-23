/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** nbr
*/

void my_putchar(char c);

int my_put_nbr(int nb)
{
    if (nb < 0) {
        nb = -nb;
        my_putchar('-');
    }
    if (nb >= 10) {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    }
    else {
        my_putchar(nb + '0');
    }
    return (0);
}
