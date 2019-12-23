/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** revstr
*/

char *my_revstr(char *str)
{
    int a = 0;
    int b = 0;
    int t = 0;
    char *str1 = str;
    char c;

    while (str[a] != '\0') {
        a++;
    }
    a--;
    t = a / 2;
    while (a > t) {
        c = str[b];
        str1[b] = str[a];
        str1[a] = c;
        a--;
        b++;
    }
    return (str1);
}
