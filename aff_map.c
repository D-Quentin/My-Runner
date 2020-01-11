/*
** EPITECH PROJECT, 2020
** aff_map
** File description:
** m
*/

#include "my.h"

all_t print_map(all_t all)
{
    if ((all.cn.pix / all.cn.map) >= 20) {
        if (all.map[all.cn.map] == 'S') {
                        all.tex.spike[all.cn.spike] =                               \
                            create_sprite(all.tex.spike[all.cn.spike], "files/spike.png");
                        set_pos(all.tex.spike[all.cn.spike], 1920, 920);
                        all.cn.spike++;
        }
        if (all.map[all.cn.map] == 'V') {
                        all.tex.hole[all.cn.hole] =                                 \
                            create_sprite(all.tex.hole[all.cn.hole], "files/hole.png");
                        all.re.hole[all.cn.hole].top = 0;
                        all.re.hole[all.cn.hole].left = -189;
                        all.re.hole[all.cn.hole].width = 189;
                        all.re.hole[all.cn.hole].height = 190;
                        set_pos(all.tex.hole[all.cn.hole], 1920, 400);
                        all.cn.hole++;
        }
        all = print_map2(all);
        all.cn.map++;
    }
    return (all);
}

all_t print_map2(all_t all)
{
    if (all.map[all.cn.map] == 'W') {
                all.tex.wall[all.cn.wall] =                                     \
                    create_sprite(all.tex.wall[all.cn.wall], "files/wall.png");
                all.re.wall[all.cn.wall].top = 0;
                all.re.wall[all.cn.wall].left = -380;
                all.re.wall[all.cn.wall].width = 380;
                all.re.wall[all.cn.wall].height = 120;
                set_pos(all.tex.wall[all.cn.wall], 1920, 900);
                all.cn.wall++;
    }
    return (all);
}

all_t read_map(all_t all, char **av)
{
    char *buf = malloc(sizeof(char) * 10000);
    int fd = open(av[1], O_RDWR);

    read(fd, buf, 10000);
    all.map = buf;
    all.map_name = av[1];
    return (all);
}

int syntax(int ac, char **av)
{
    if (ac == 1) {
        my_putstr("Please add a map, make [./my_runner -h] for more info\n");
        return (1);
    }
    if (av[1][0] == '-' && av[1][1] == 'h') {
        my_putstr("Welcome in my runner.\n\n");
        my_putstr("USAGE\n\t./my_runner [map]\n\t");
        my_putstr("Choose one of these map:\n\t");
        my_putstr("map1.txt (Easy)\n\tmap2.txt (Medium)\n\tmap3.txt (Hard)");
        my_putstr("\n\nOPTION\n\t-h\tprint the usage and quit.\n\n");
        my_putstr("USER INTERACTIONS\n\t");
        my_putstr("SPACE_KEY\tjump (You have a double jump).\n\t");
        my_putstr("ESCAPE_KEY\tpause.\n\nGLHF\n");
        return (1);
    }
}

all_t move_obj(all_t all)
{
    sfVector2f move = {all.cn.speed, 0};
    int i = 0;

    while (i != all.cn.spike) {
        sfSprite_move(all.tex.spike[i], move);
        i++;
    }
    i = 0;
    while (i != all.cn.hole) {
        sfSprite_move(all.tex.hole[i], move);
        i++;
    }
    i = 0;
    while (i != all.cn.wall) {
        sfSprite_move(all.tex.wall[i], move);
        i++;
    }
    return (all);
}
