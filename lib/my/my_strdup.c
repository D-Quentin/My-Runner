/*
** EPITECH PROJECT, 2019
** my_strdup
** File description:
** strdup
*/

#include <stdlib.h>

void my_putchar(char c);

int my_putstr3(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}

char *my_strdup(char const *src)
{
    char *new;
    int i = 0;

    new = malloc(sizeof(char) * (my_putstr3(src) + 1));
    for (i = 0; src[i] != '\0'; i++)
        new[i] = src[i];
    new[i] = '\0';
    return new;
}
