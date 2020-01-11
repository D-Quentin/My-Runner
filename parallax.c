/*
** EPITECH PROJECT, 2020
** parallax
** File description:
** m
*/

#include "my.h"

all_t parallax(all_t all)
{
    sfVector2f move_front = {all.cn.speed, 0};
    sfVector2f move_midle = {all.cn.speed / 4, 0};
    sfVector2f move_far = {all.cn.speed / 7, 0};

    parallax_reset(all);
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(all.cl.front)) > 10) {
        sfSprite_move(all.tex.front, move_front);
        sfSprite_move(all.tex.midle, move_midle);
        sfSprite_move(all.tex.far, move_far);
        sfClock_restart(all.cl.front);
        all.cn.pix++;
        all = move_obj(all);
    }
    return (all);
}

void parallax_reset(all_t all)
{
    sfVector2f position = {0, 0};

    if (sfSprite_getPosition(all.tex.far).x < -1920)
        sfSprite_setPosition(all.tex.far, position);
    if (sfSprite_getPosition(all.tex.midle).x < -1920)
        sfSprite_setPosition(all.tex.midle, position);
    if (sfSprite_getPosition(all.tex.front).x < -1920)
        sfSprite_setPosition(all.tex.front, position);
}
