/*
** EPITECH PROJECT, 2020
** option
** File description:
** m
*/

#include "my.h"

all_t set_fps(all_t all)
{
    if (check_click(all.tex.fps60, 250, 100, all) == 1) {
        set_pos(all.tex.arrow2, 10, 530);
        sfRenderWindow_setFramerateLimit(all.window, 60);
        all.cn.fps = 60;
    }
    if (check_click(all.tex.fps120, 250, 100, all) == 1) {
        set_pos(all.tex.arrow2, 10, 650);
        sfRenderWindow_setFramerateLimit(all.window, 120);
        all.cn.fps = 120;
    }
    if (check_click(all.tex.fps144, 250, 100, all) == 1) {
        set_pos(all.tex.arrow2, 10, 760);
        sfRenderWindow_setFramerateLimit(all.window, 144);
        all.cn.fps = 144;
    }
    return (all);
}

all_t set_window(all_t all)
{
    if (check_click(all.tex.fullscreen, 610, 100, all) == 1 && \
        all.cn.window != 1) {
        set_pos(all.tex.arrow, 10, 160);
        sfRenderWindow_destroy(all.window);
        all.window = set_win("My Runner", all.cn.fps, 1);
        all.cn.window = 1;
    }
    else if (check_click(all.tex.windowed, 610, 100, all) == 1 && \
             all.cn.window != 0) {
        set_pos(all.tex.arrow, 10, 270);
        sfRenderWindow_destroy(all.window);
        all.window = set_win("My Runner", all.cn.fps, 0);
        all.cn.window = 0;
    }
    return (all);
}

void destroy(all_t all)
{
    sfMusic_stop(all.mu.play);
    sfMusic_stop(all.mu.title);
    sfMusic_stop(all.mu.tp);
    sfMusic_stop(all.mu.win);
    sfMusic_stop(all.mu.jump);
    sfMusic_destroy(all.mu.play);
    sfMusic_destroy(all.mu.title);
    sfMusic_destroy(all.mu.tp);
    sfMusic_destroy(all.mu.win);
    sfMusic_destroy(all.mu.jump);
}

all_t analyse_event(all_t all)
{
    while (sfRenderWindow_pollEvent(all.window, &all.event)) {
        all = close_window(all);
    }
    return (all);
}

all_t close_window(all_t all)
{
    if (all.event.type == sfEvtClosed) {
        sfRenderWindow_close(all.window);
        all.cn.title = 0;
        all.cn.play = 0;
        all.cn.settings = 0;
        all.cn.win = 0;
        all.cn.end = 0;
        all.cn.pause = 0;
    }
    if (check_click(all.tex.quit, 340, 110, all) == 1 && \
        all.cn.settings != 1 && (all.cn.play != 1 || all.cn.pause)) {
        sfRenderWindow_close(all.window);
        all.cn.title = 0;
        all.cn.play = 0;
        all.cn.settings = 0;
        all.cn.win = 0;
        all.cn.end = 0;
        all.cn.pause = 0;
    }
    return (all);
}
