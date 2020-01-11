/*
** EPITECH PROJECT, 2020
** animation
** File description:
** m
*/

#include "my.h"

all_t jump(all_t all)
{
    sfVector2f pos = sfSprite_getPosition(all.tex.jump);

    if (sfSprite_getPosition(all.tex.run).y < 900 && all.cn.jump == 0)
        return (all);
    if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue && all.cn.jump <= 2) {
        sfMusic_stop(all.mu.jump);
        sfMusic_play(all.mu.jump);
        if (all.cn.jump == 1 && all.re.jump.left > 300)
            all.cn.jump++;
        if (all.cn.jump == 0) {
            set_pos(all.tex.jump, 500, 900);
            all.cn.jump++;
        } else if (all.cn.jump == 2) {
            set_pos(all.tex.jump, pos.x, pos.y);
            all.re.jump.left = 0;
            all.cn.jump++;
        }
    }
    all = jump2(all);
    return (all);
}

all_t jump2(all_t all)
{
    sfVector2f pos = sfSprite_getPosition(all.tex.jump);

    if (all.cn.jump >= 1) {
        set_pos(all.tex.run, 2000, 2000);
        if (sfTime_asMilliseconds(sfClock_getElapsedTime(all.cl.jump))  \
            > 150) {
            all.re.jump.left = all.re.jump.left + 125;
            sfSprite_setTextureRect(all.tex.jump, all.re.jump);
            sfClock_restart(all.cl.jump);
        }
        if (all.re.jump.left >= 1000) {
            all.re.jump.left = 0;
            all.cn.jump = 0;
            set_pos(all.tex.run, pos.x, pos.y);
            set_pos(all.tex.jump, 2000, 2000);
        }
    }
    return (all);
}

all_t gravity(all_t all)
{
    sfVector2f move = {0, 14};
    sfVector2f move_up = {0, -35};

    if (all.cn.jump >= 1 && all.re.jump.left < 500 &&                   \
        sfTime_asMilliseconds(sfClock_getElapsedTime(all.cl.gravity)) > 20) {
        sfSprite_move(all.tex.jump, move_up);
    }
    if (sfSprite_getPosition(all.tex.jump).y < 900 &&                   \
        sfTime_asMilliseconds(sfClock_getElapsedTime(all.cl.gravity)) > 20) {
        sfSprite_move(all.tex.jump, move);
        sfClock_restart(all.cl.gravity);
    }
    if (sfSprite_getPosition(all.tex.run).y < 900 &&                    \
        sfTime_asMilliseconds(sfClock_getElapsedTime(all.cl.gravity)) > 20) {
        sfSprite_move(all.tex.run, move);
        sfClock_restart(all.cl.gravity);
    }
    return (all);
}

all_t animation(all_t all)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(all.cl.run)) > 100) {
        all.re.run.left = all.re.run.left + 138;
        sfSprite_setTextureRect(all.tex.run, all.re.run);
        sfClock_restart(all.cl.run);
    }
    if (all.re.run.left >= 690)
        all.re.run.left = -138;
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(all.cl.obj)) > 100) {
        all = animation2(all);
    }
    return (all);
}

all_t animation2(all_t all)
{
    int i = 0;

    while (i != all.cn.hole) {
        all.re.hole[i].left = all.re.hole[i].left + 189;
        sfSprite_setTextureRect(all.tex.hole[i], all.re.hole[i]);
        if (all.re.hole[i].left >= 378)
            all.re.hole[i].left = 0;
        i++;
    }
    i = 0;
    while (i != all.cn.wall) {
        all.re.wall[i].left = all.re.wall[i].left + 380;
        sfSprite_setTextureRect(all.tex.wall[i], all.re.wall[i]);
        if (all.re.wall[i].left >= 1140)
            all.re.wall[i].left = 0;
        i++;
    }
    sfClock_restart(all.cl.obj);
    return (all);
}
