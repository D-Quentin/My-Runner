/*
** EPITECH PROJECT, 2019
** error
** File description:
** errror
*/

int error(char const *str)
{
    if (*str == '-')
        str++;
    while (*str) {
        if (*str < 47 && *str > 58)
            return (0);
        ++str;
    }
    return (1);
}
