/*
** EPITECH PROJECT, 2019
** my_compute_square_root
** File description:
** square
*/

int my_compute_square_root(int nb)
{
    int result = 0;
    int i = 0;

    while (i * i <= nb) {
        if (i * i == nb) {
            result = i;
            return result;
        }
        i++;
    }
    return result;
}
