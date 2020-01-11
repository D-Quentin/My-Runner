/*
** EPITECH PROJECT, 2020
** display
** File description:
** m
*/

#include "my.h"

void display_pause(all_t all)
{
    sfRenderWindow_clear(all.window, sfBlack);
    sfRenderWindow_drawSprite(all.window, all.tex.far, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.midle, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.front, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.run, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.jump, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.cadre, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.quit, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.play, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.menu, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.hud, NULL);
    sfRenderWindow_drawText(all.window, all.tx.score, NULL);
    sfRenderWindow_display(all.window);
}

void display_loose(all_t all)
{
    sfRenderWindow_clear(all.window, sfBlack);
    sfRenderWindow_drawSprite(all.window, all.tex.far, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.midle, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.front, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.hud_loose, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.play, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.menu, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.quit, NULL);
    sfRenderWindow_drawText(all.window, all.tx.loose, NULL);
    sfRenderWindow_drawText(all.window, all.tx.score, NULL);
    sfRenderWindow_drawText(all.window, all.tx.hs, NULL);
    sfRenderWindow_drawText(all.window, all.tx.hs_text, NULL);
    sfRenderWindow_display(all.window);
}

void display_win(all_t all)
{
    sfRenderWindow_clear(all.window, sfBlack);
    sfRenderWindow_drawSprite(all.window, all.tex.background, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.hud_win, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.play, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.menu, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.quit, NULL);
    sfRenderWindow_drawText(all.window, all.tx.win, NULL);
    sfRenderWindow_drawText(all.window, all.tx.score, NULL);
    sfRenderWindow_drawText(all.window, all.tx.hs, NULL);
    sfRenderWindow_drawText(all.window, all.tx.hs_text, NULL);
    sfRenderWindow_display(all.window);
}

void display_play(all_t all)
{
    sfRenderWindow_clear(all.window, sfBlack);
    sfRenderWindow_drawSprite(all.window, all.tex.far, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.midle, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.front, NULL);
    display_obj(all);
    sfRenderWindow_drawSprite(all.window, all.tex.hud, NULL);
    sfRenderWindow_drawText(all.window, all.tx.score, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.run, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.jump, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.tp, NULL);
    sfRenderWindow_display(all.window);
}

void display_obj(all_t all)
{
    int i = 0;

    while (i != all.cn.spike) {
        sfRenderWindow_drawSprite(all.window, all.tex.spike[i], NULL);
        i++;
    }
    i = 0;
    while (i != all.cn.hole) {
        sfRenderWindow_drawSprite(all.window, all.tex.hole[i], NULL);
        i++;
    }
    i = 0;
    while (i != all.cn.wall) {
        sfRenderWindow_drawSprite(all.window, all.tex.wall[i], NULL);
        i++;
    }
}
