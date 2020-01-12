/*
** EPITECH PROJECT, 2020
** initialization
** File description:
** m
*/

#include "my.h"

all_t initialization(all_t all)
{
    all.window = set_win("My Runner", 60, 1);
    all = initialization_clock(all);
    all = initialization_tex(all);
    all = initialization_tex2(all);
    all = initialization_counter(all);
    all = initialization_text(all);
    all = initialization_rect(all);
    all = initialization_music(all);
    initialization_pos(all);
    all.tex.spike = malloc(sizeof(sfSprite *) * 1000);
    all.tex.hole = malloc(sizeof(sfSprite *) * 1000);
    all.tex.wall = malloc(sizeof(sfSprite *) * 1000);
    all.re.hole = malloc(sizeof(sfIntRect) * 1000);
    all.re.wall = malloc(sizeof(sfIntRect) * 1000);
    all.hs = malloc(sizeof(char) * 1000);
    all.hs_file = malloc(sizeof(char) * 1000);
    sfSprite_setTextureRect(all.tex.tp, all.re.tp);
    return (all);
}

all_t initialization_music(all_t all)
{
    all.mu.title = sfMusic_createFromFile("files/title.ogg");
    all.mu.play = sfMusic_createFromFile("files/play.ogg");
    all.mu.win = sfMusic_createFromFile("files/win.ogg");
    all.mu.tp = sfMusic_createFromFile("files/tp.ogg");
    all.mu.jump = sfMusic_createFromFile("files/jump.ogg");
    return (all);
}

all_t initialization_clock(all_t all)
{
    all.cl.front = sfClock_create();
    all.cl.midle = sfClock_create();
    all.cl.far = sfClock_create();
    all.cl.run = sfClock_create();
    all.cl.jump = sfClock_create();
    all.cl.gravity = sfClock_create();
    all.cl.obj = sfClock_create();
    all.cl.score = sfClock_create();
    all.cl.tp = sfClock_create();
    return (all);
}

void initialization_pos(all_t all)
{
    set_pos(all.tex.play, 120, 200);
    set_pos(all.tex.settings, 120, 600);
    set_pos(all.tex.quit, 120, 800);
    set_pos(all.tex.my_runner, 920, 50);
    set_pos(all.tex.fullscreen, 120, 130);
    set_pos(all.tex.windowed, 120, 280);
    set_pos(all.tex.fps60, 120, 520);
    set_pos(all.tex.fps120, 120, 640);
    set_pos(all.tex.fps144, 120, 760);
    set_pos(all.tex.menu, 90, 890);
    set_pos(all.tex.arrow2, 10, 530);
    set_pos(all.tex.arrow, 10, 160);
    set_pos(all.tex.run, 500, 900);
    set_pos(all.tex.jump, 2000, 2000);
    set_pos(all.tex.hud, 1565, 10);
    set_pos(all.tex.tp, 2000, 2000);
    set_pos(all.tex.background, 0, 0);
    set_pos(all.tex.hud_win, 630, 0);
    set_pos(all.tex.hud_loose, 630, 0);
    initialization_pos_text(all);
}

void initialization_pos_text(all_t all)
{
    set_pos_text(all.tx.graphics, 80, 20);
    set_pos_text(all.tx.fps, 80, 390);
    set_pos_text(all.tx.score, 1630, 5);
    set_pos_text(all.tx.win, 735, 5);
    set_pos_text(all.tx.loose, 735, 5);
    set_pos_text(all.tx.hs_text, 765, 560);
    set_pos_text(all.tx.hs, 860, 660);
}
