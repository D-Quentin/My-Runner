/*
** EPITECH PROJECT, 2019
** my_itoa
** File description:
** a
*/

#include "../../include/my.h"
#include <stdlib.h>

char *my_itoa(int num)
{
    char *str_num = malloc(num);
    int i = 0;
    int j = num;

    while (j > 0) {
        j /= 10;
        i++;
    }
    str_num[i] = '\0';
    while (i--) {
        str_num[i] = num % 10 + 48;
        num /= 10;
    }
    return (str_num);
}
