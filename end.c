/*
** EPITECH PROJECT, 2020
** end
** File description:
** m
*/

#include "my.h"

all_t loose(all_t all)
{
    set_pos(all.tex.menu, 50, 890);
    set_pos(all.tex.quit, 1520, 890);
    set_pos(all.tex.play, 650, 860);
    set_pos_text(all.tx.score, 860, 360);
    all.cn.speed = -1;
    all = highscore(all);
    sfMusic_play(all.mu.title);
    sfRenderWindow_setMouseCursorVisible(all.window, sfTrue);
    while (all.cn.end == 1) {
        all = parallax(all);
        all = button_end(all);
        display_loose(all);
    }
    if (all.cn.play == 1) {
        sfRenderWindow_setMouseCursorVisible(all.window, sfFalse);
        sfMusic_stop(all.mu.title);
    }
    return (all);
}

all_t win(all_t all)
{
    all.cl.background = sfClock_create();
    set_pos(all.tex.menu, 50, 890);
    set_pos(all.tex.quit, 1520, 890);
    set_pos(all.tex.play, 650, 860);
    set_pos_text(all.tx.score, 860, 360);
    all = highscore(all);
    sfMusic_play(all.mu.win);
    sfRenderWindow_setMouseCursorVisible(all.window, sfTrue);
    while (all.cn.end == 1) {
        all = end_background(all);
        all = button_end(all);
        display_win(all);
    }
    sfMusic_stop(all.mu.win);
    if (all.cn.play == 1)
        sfRenderWindow_setMouseCursorVisible(all.window, sfFalse);
    return (all);
}

all_t button_end(all_t all)
{
    if (check_click(all.tex.menu, 360, 115, all) == 1) {
        all = initialization_counter(all);
        all = initialization_rect(all);
        initialization_pos(all);
        all.cn.title = 1;
        all.cn.end = 0;
        all.cn.pause = 0;
    }
    if (check_click(all.tex.play, 600, 150, all) == 1) {
        if (all.cn.pause != 1) {
            all = initialization_counter(all);
            all = initialization_rect(all);
            initialization_pos(all);
        }
        all.cn.play = 1;
        all.cn.title = 0;
        all.cn.end = 0;
        all.cn.pause = 0;
    }
    all = analyse_event(all);
    return (all);
}

all_t end_background(all_t all)
{
    if (sfSprite_getPosition(all.tex.background).x <= -8084)
        all.move.x = 1;
    if (sfSprite_getPosition(all.tex.background).x >= 0)
        all.move.x = -1;
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(all.cl.background)) > \
        10) {
        sfClock_restart(all.cl.background);
        sfSprite_move(all.tex.background, all.move);
    }
    return (all);
}

all_t end(all_t all)
{
    if (all.map[all.cn.map] == 'E') {
        all.cl.tp = sfClock_create();
        set_pos(all.tex.tp, 500, 800);
        set_pos(all.tex.run, 2000, 2000);
        set_pos(all.tex.jump, 2000, 2000);
        sfMusic_play(all.mu.tp);
        while (all.re.tp.left <= 4875) {
            if (sfTime_asMilliseconds(sfClock_getElapsedTime(all.cl.tp)) > \
                60) {
                sfSprite_setTextureRect(all.tex.tp, all.re.tp);
                all.re.tp.left += 192;
                sfClock_restart(all.cl.tp);
            }
            all = parallax(all);
            display_play(all);
        }
        all.cn.play = 0;
        all.cn.end = 1;
        all.cn.win = 1;
    }
    return (all);
}
