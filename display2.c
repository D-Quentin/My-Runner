/*
** EPITECH PROJECT, 2020
** display2
** File description:
** m
*/

#include "my.h"

void display_title(all_t all)
{
    sfRenderWindow_clear(all.window, sfBlack);
    sfRenderWindow_drawSprite(all.window, all.tex.far, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.midle, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.front, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.cadre, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.play, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.settings, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.quit, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.my_runner, NULL);
    sfRenderWindow_display(all.window);
}

void display_settings(all_t all)
{
    sfRenderWindow_clear(all.window, sfBlack);
    sfRenderWindow_drawSprite(all.window, all.tex.far, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.midle, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.front, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.cadre, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.my_runner, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.fullscreen, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.windowed, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.fps60, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.fps120, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.fps144, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.menu, NULL);
    sfRenderWindow_drawText(all.window, all.tx.graphics, NULL);
    sfRenderWindow_drawText(all.window, all.tx.fps, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.arrow, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.arrow2, NULL);
    sfRenderWindow_display(all.window);
}
