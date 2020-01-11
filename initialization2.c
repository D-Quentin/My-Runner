/*
** EPITECH PROJECT, 2020
** initialization2
** File description:
** m
*/

#include "my.h"

all_t initialization_rect(all_t all)
{
    all.re.run.top = 0;
    all.re.run.left = 0;
    all.re.run.width = 138;
    all.re.run.height = 123;
    all.re.jump.top = 0;
    all.re.jump.left = 0;
    all.re.jump.width = 125;
    all.re.jump.height = 140;
    all.re.tp.top = 0;
    all.re.tp.left = 0;
    all.re.tp.width = 192;
    all.re.tp.height = 196;
    return (all);
}

all_t initialization_text(all_t all)
{
    all.tx.graphics = create_text(all.tx.graphics, 80, "Graphics settings :");
    all.tx.fps = create_text(all.tx.fps, 80, "FPS :");
    all.tx.score = create_text(all.tx.score, 80, "0");
    all.tx.win = create_text(all.tx.win, 80,                            \
                             "Game Over\n  You Win\n\nYour Score:");
    all.tx.loose = create_text(all.tx.loose, 80,                        \
                               "Game Over\n You Loose\n\nYour Score:");
    all.tx.hs = create_text(all.tx.hs, 80, "0");
    all.tx.hs_text = create_text(all.tx.hs_text, 80, "Highscore:");
    return (all);
}

all_t initialization_counter(all_t all)
{
    all.cn.title = 1;
    all.cn.play = 0;
    all.cn.settings = 0;
    all.cn.fps = 60;
    all.cn.window = 1;
    all.cn.jump = 0;
    all.cn.map = 1;
    all.cn.spike = 0;
    all.cn.hole = 0;
    all.cn.wall = 0;
    all.cn.speed = -1;
    all.cn.score = 0;
    all.cn.end = 0;
    all.cn.win = 0;
    all.cn.pause = 0;
    all.cn.loose = 0;
    return (all);
}

all_t initialization_tex(all_t all)
{
    all.tex.cadre = create_sprite(all.tex.cadre, "files/cadre.png");
    all.tex.play = create_sprite(all.tex.play, "files/play.png");
    all.tex.settings = create_sprite(all.tex.settings, "files/settings.png");
    all.tex.quit = create_sprite(all.tex.quit, "files/quit.png");
    all.tex.far = create_sprite(all.tex.far, "files/far.png");
    all.tex.midle = create_sprite(all.tex.midle, "files/midle.png");
    all.tex.front = create_sprite(all.tex.front, "files/front.png");
    all.tex.my_runner = create_sprite(all.tex.my_runner, "files/runner.png");
    all.tex.fullscreen = create_sprite(all.tex.fullscreen, "files/fc.png");
    all.tex.windowed = create_sprite(all.tex.windowed, "files/windowed.png");
    all.tex.fps60 = create_sprite(all.tex.fps60, "files/60.png");
    all.tex.fps120 = create_sprite(all.tex.fps120, "files/120.png");
    all.tex.fps144 = create_sprite(all.tex.fps144, "files/144.png");
    all.tex.menu = create_sprite(all.tex.menu, "files/menu.png");
    all.tex.arrow = create_sprite(all.tex.arrow, "files/arrow.png");
    all.tex.arrow2 = create_sprite(all.tex.arrow2, "files/arrow.png");
    return (all);
}

all_t initialization_tex2(all_t all)
{
    all.tex.run = create_sprite(all.tex.run, "files/run.png");
    all.tex.jump = create_sprite(all.tex.jump, "files/jump.png");
    all.tex.hud = create_sprite(all.tex.hud, "files/cadre_score.png");
    all.tex.tp = create_sprite(all.tex.tp, "files/tp.png");
    all.tex.background = create_sprite(all.tex.background, "files/back.jpg");
    all.tex.hud_win = create_sprite(all.tex.hud_win, "files/win.png");
    all.tex.hud_loose = create_sprite(all.tex.hud_loose, "files/loose.png");
    return (all);
}
