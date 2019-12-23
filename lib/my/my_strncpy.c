/*
** EPITECH PROJECT, 2019
** my_strncpy
** File description:
** strncpy
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int p = 0;

    for (p = 0; p < n && src[p] != '\0'; p++)
        dest[p] = src[p];
    for (; p < n; p++)
        dest[p] = '\0';
    return dest;
}
