/*
** EPITECH PROJECT, 2020
** hit_box_score
** File description:
** l
*/

#include "my.h"

all_t hit_box(all_t all)
{
    int i = 0;

    while (i != all.cn.spike) {
        if (sfSprite_getPosition(all.tex.spike[i]).x < 600 &&   \
            sfSprite_getPosition(all.tex.spike[i]).x > 380 &&   \
            ((sfSprite_getPosition(all.tex.jump).y > 820 &&     \
              sfSprite_getPosition(all.tex.jump).x == 500) ||   \
             (sfSprite_getPosition(all.tex.run).y > 820 &&      \
              sfSprite_getPosition(all.tex.run).x == 500))) {
            all.cn.play = 0;
            all.cn.end = 1;
            all.cn.loose = 1;
        }
        i++;
    }
    all = hit_box2(all);
    return (all);
}

all_t hit_box2(all_t all)
{
    int i = 0;

    while (i != all.cn.wall) {
        if (sfSprite_getPosition(all.tex.wall[i]).x < 600 &&    \
            sfSprite_getPosition(all.tex.wall[i]).x > 180 &&    \
            ((sfSprite_getPosition(all.tex.jump).y > 820 &&     \
              sfSprite_getPosition(all.tex.jump).x == 500) ||   \
             (sfSprite_getPosition(all.tex.run).y > 820 &&      \
              sfSprite_getPosition(all.tex.run).x == 500))) {
            all.cn.play = 0;
            all.cn.end = 1;
            all.cn.loose = 1;
        }
        i++;
    }
    i = 0;
    while (i != all.cn.hole) {
        if (sfSprite_getPosition(all.tex.hole[i]).x < 600 &&    \
            sfSprite_getPosition(all.tex.hole[i]).x > 360 &&    \
            ((sfSprite_getPosition(all.tex.jump).y < 580 &&     \
              sfSprite_getPosition(all.tex.jump).x == 500) ||   \
             (sfSprite_getPosition(all.tex.run).y < 580 &&      \
              sfSprite_getPosition(all.tex.run).x == 500))) {
            all.cn.play = 0;
            all.cn.end = 1;
            all.cn.loose = 1;
        }
        i++;
    }
    return (all);
}


all_t highscore(all_t all)
{
    if (1) {
        if (all.map_name[3] == '1')
            all.hs_file = "files/hs_map1.txt";
        if (all.map_name[3] == '2')
            all.hs_file = "files/hs_map2.txt";
        if (all.map_name[3] == '3')
            all.hs_file = "files/hs_map3.txt";
    }
    all.hs = read_high_score(all);
    if (all.cn.score > my_getnbr(all.hs))
        all.hs = write_high_score(my_itoa(all.cn.score), all);
    sfText_setString(all.tx.hs, all.hs);
}

all_t score(all_t all)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(all.cl.score)) > 10) {
        all.cn.score += 1;
        sfText_setString(all.tx.score, my_itoa(all.cn.score));
        sfClock_restart(all.cl.score);
    }
    return (all);
}
