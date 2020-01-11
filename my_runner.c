/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** my_runner
*/

#include "my.h"

int main(int ac, char **av)
{
    all_t all;
    if (syntax(ac, av) == 1)
        return (84);
    all = initialization(all);
    all = read_map(all, av);
    while (sfRenderWindow_isOpen(all.window)) {
        if (all.cn.title == 1)
            all = title(all);
        if (all.cn.settings == 1)
            all = settings(all);
        if (all.cn.play == 1) {
            all.cn.pix = 0;
            all.cn.speed = -6;
            all = play(all);
        }
    }
    destroy(all);
    return (0);
}

all_t play(all_t all)
{
    sfMusic_play(all.mu.play);
    while (all.cn.play == 1) {
        all = parallax(all);
        all = animation(all);
        all = jump(all);
        all = gravity(all);
        all = print_map(all);
        all = hit_box(all);
        all = score(all);
        all = end(all);
        all = analyse_event(all);
        all = pause_game(all);
        display_play(all);
    }
    sfMusic_stop(all.mu.play);
    if (all.cn.win == 1)
        all = win(all);
    else if (all.cn.loose == 1)
        all = loose(all);
    return (all);
}

all_t pause_game(all_t all)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue) {
        all.cn.pause = 1;
        set_pos(all.tex.menu, 120, 450);
        sfRenderWindow_setMouseCursorVisible(all.window, sfTrue);
        sfMusic_pause(all.mu.play);
        while (all.cn.pause == 1) {
            display_pause(all);
            all = button_end(all);
        }
        if (all.cn.play == 1) {
            sfRenderWindow_setMouseCursorVisible(all.window, sfFalse);
            sfMusic_play(all.mu.play);
        }
    }
    return (all);
}

all_t settings(all_t all)
{
    while (all.cn.settings == 1) {
        parallax(all);
        display_settings(all);
        all = set_fps(all);
        all = set_window(all);
        all = analyse_event(all);
        if (check_click(all.tex.menu, 360, 115, all) == 1) {
            all.cn.title = 1;
            all.cn.settings = 0;
        }
    }
    return (all);
}

all_t title(all_t all)
{
    if (sfMusic_getStatus(all.mu.title) == sfStopped)
        sfMusic_play(all.mu.title);
    while (all.cn.title == 1) {
        parallax(all);
        display_title(all);
        all = analyse_event(all);
        if (check_click(all.tex.settings, 530, 110, all) == 1) {
            all.cn.settings = 1;
            all.cn.title = 0;
        }
        if (check_click(all.tex.play, 610, 150, all) == 1) {
            sfRenderWindow_setMouseCursorVisible(all.window, sfFalse);
            all.cn.play = 1;
            all.cn.title = 0;
            sfMusic_stop(all.mu.title);
        }
    }
    return (all);
}
