/*
** EPITECH PROJECT, 2020
** lib_graphic2
** File description:
** m
*/

#include "my.h"

sfRenderWindow *set_win(char *title, int fps, int fullscreen)
{
    sfRenderWindow *window = NULL;
    sfVideoMode mode = {1920, 1080, 32};

    if (fullscreen == 0)
        window = sfRenderWindow_create(mode, title, sfClose, NULL);
    else
        window = sfRenderWindow_create(mode, title, sfFullscreen, NULL);
    sfRenderWindow_setFramerateLimit(window, fps);
    sfRenderWindow_setKeyRepeatEnabled(window, sfFalse);
    return (window);
}

char *write_high_score(char *buffer, all_t all)
{
    write(open(all.hs_file, O_WRONLY | O_TRUNC), buffer, 10);
    return (buffer);
}

char *read_high_score(all_t all)
{
    char *buffer = malloc(sizeof(char) * 10);

    read(open(all.hs_file, O_RDONLY), buffer, 10);
    return (buffer);
}
