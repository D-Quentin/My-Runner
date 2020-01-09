/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** my_runner
*/

#include "my.h"

typedef	struct texture_s texture_t;
struct texture_s {
    sfSprite *cadre;
    sfSprite *play;
    sfSprite *settings;
    sfSprite *quit;
    sfSprite *far;
    sfSprite *midle;
    sfSprite *front;
    sfSprite *my_runner;
    sfSprite *fullscreen;
    sfSprite *windowed;
    sfSprite *fps60;
    sfSprite *fps120;
    sfSprite *fps144;
    sfSprite *menu;
    sfSprite *arrow;
    sfSprite *arrow2;
    sfSprite *jump;
    sfSprite *run;
    sfSprite *hud;
    sfSprite *tp;
    sfSprite *background;
    sfSprite *hud_win;
    sfSprite *hud_loose;
    sfSprite **spike;
    sfSprite **hole;
    sfSprite **wall;
};

typedef struct counter_s counter_t;
struct counter_s {
    int play;
    int settings;
    int title;
    int fps;
    int window;
    int jump;
    int map;
    int spike;
    int hole;
    int wall;
    int pix;
    int score;
    int end;
    int win;
    int pause;
    int loose;
    float speed;
};

typedef struct rect_s rect_t;
struct rect_s {
    sfIntRect run;
    sfIntRect jump;
    sfIntRect tp;
    sfIntRect *hole;
    sfIntRect *wall;
};

typedef struct text_s text_t;
struct text_s {
    sfText *graphics;
    sfText *fps;
    sfText *score;
    sfText *win;
    sfText *loose;
    sfText *hs;
    sfText *hs_text;
};

typedef struct clocks_s clocks_t;
struct clocks_s {
    sfClock *front;
    sfClock *midle;
    sfClock *far;
    sfClock *run;
    sfClock *jump;
    sfClock *gravity;
    sfClock *obj;
    sfClock *score;
    sfClock *tp;
    sfClock *background;
};

typedef struct all_s all_t;
struct all_s {
    sfRenderWindow *window;
    char *map;
    char *map_name;
    char *hs;
    char *hs_file;
    sfVector2f move;
    sfEvent event;
    texture_t tex;
    clocks_t cl;
    counter_t cn;
    text_t tx;
    rect_t re;
};

sfSprite *create_sprite(sfSprite *sprite, char *file);
sfRenderWindow *set_win(char *title, int fps, int fullscreen);
all_t initialization(all_t all);
void initialization_pos(all_t all);
all_t initialization_tex(all_t all);
all_t initialization_tex2(all_t all);
all_t initialization_counter(all_t all);
all_t initialization_text(all_t all);
all_t initialization_rect(all_t all);
all_t initialization_clock(all_t all);
void initialization_pos_text(all_t all);
void display_title(all_t all);
void display_settings(all_t all);
void display_play(all_t all);
void display_win(all_t all);
void display_loose(all_t all);
void display_pause(all_t all);
void set_pos(sfSprite *sprite, int x, int y);
void parallax_reset(all_t all);
all_t parallax(all_t all);
all_t title(all_t all);
all_t settings(all_t all);
all_t analyse_event(all_t all);
all_t close_window(all_t all);
int check_click(sfSprite *sprite, int x, int y, all_t all);
sfText *create_text(sfText *text, int size, char *str);
void set_pos_text(sfText *text, int x, int y);
sfIntRect create_rect(sfIntRect rect, int width, int height);
all_t set_fps(all_t all);
all_t set_window(all_t all);
all_t play(all_t all);
all_t animation(all_t all);
all_t animation2(all_t all);
all_t jump(all_t all);
all_t jump2(all_t all);
all_t gravity(all_t all);
char **array_to_tab_array(char *map_str);
all_t read_map(all_t all, char **av);
all_t print_map(all_t all);
all_t print_map2(all_t all);
void display_obj(all_t all);
all_t move_obj(all_t all);
all_t hit_box(all_t all);
all_t hit_box2(all_t all);
all_t score(all_t all);
all_t end(all_t all);
all_t win(all_t all);
all_t end_background(all_t all);
all_t loose(all_t all);
char *write_high_score(char *buffer, all_t all);
char *read_high_score(all_t all);
all_t highscore(all_t all);
all_t button_end(all_t all);
all_t pause_game(all_t all);

void main(int ac, char **av)
{
    all_t all;

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
}

all_t play(all_t all)
{
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
        while (all.cn.pause == 1) {
            display_pause(all);
            all = button_end(all);
        }
        if (all.cn.play == 1)
            sfRenderWindow_setMouseCursorVisible(all.window, sfFalse);
    }
    return (all);
}

all_t loose(all_t all)
{
    set_pos(all.tex.menu, 50, 890);
    set_pos(all.tex.quit, 1520, 890);
    set_pos(all.tex.play, 650, 860);
    set_pos_text(all.tx.score, 860, 360);
    all.cn.speed = -1;
    all = highscore(all);
    sfRenderWindow_setMouseCursorVisible(all.window, sfTrue);
    while (all.cn.end == 1) {
        all = parallax(all);
        all = button_end(all);
        display_loose(all);
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
    sfRenderWindow_setMouseCursorVisible(all.window, sfTrue);
    while (all.cn.end == 1) {
        all = end_background(all);
        all = button_end(all);
        display_win(all);
    }
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

all_t highscore(all_t all)
{
    switch (all.map_name[3]) {
    case '1':
        all.hs_file = "files/hs_map1.txt";
    case '2':
        all.hs_file = "files/hs_map2.txt";
    case '3':
        all.hs_file = "files/hs_map3.txt";
    default:
        all.hs_file = "files/hs_endless.txt";
    }
    all.hs = read_high_score(all);
    if (all.cn.score > my_getnbr(all.hs))
        all.hs = write_high_score(my_itoa(all.cn.score), all);
    sfText_setString(all.tx.hs, all.hs);
}

char *write_high_score(char *buffer, all_t all)
{
    write(open(all.hs_file, O_WRONLY | O_TRUNC), buffer, 10);
    return (buffer);
}

char *read_high_score(all_t all)
{
    char *buffer = malloc(sizeof(char) * 10);

    read(open(all.hs_file, O_RDONLY), buffer, 10);
    return (buffer);
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

all_t score(all_t all)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(all.cl.score)) > 10) {
        all.cn.score += 1;
        sfText_setString(all.tx.score, my_itoa(all.cn.score));
        sfClock_restart(all.cl.score);
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
        sfSprite_setTextureRect(all.tex.tp, all.re.tp);
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

all_t read_map(all_t all, char **av)
{
    char *buf = malloc(sizeof(char) * 10000);
    int fd = open(av[1], O_RDWR);

    read(fd, buf, 10000);
    all.map = buf;
    all.map_name = av[1];
    return (all);
}

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
    
all_t jump(all_t all)
{
    sfVector2f pos = sfSprite_getPosition(all.tex.jump);

    if (sfSprite_getPosition(all.tex.run).y < 900 && all.cn.jump == 0)
        return (all);
    if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue && all.cn.jump <= 2) {
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

all_t set_fps(all_t all)
{
    if (check_click(all.tex.fps60, 250, 100, all) == 1) {
        set_pos(all.tex.arrow2, 10, 530);
        sfRenderWindow_setFramerateLimit(all.window, 60);
        all.cn.fps = 60;
    }
    if (check_click(all.tex.fps120, 250, 100, all) == 1) {
        set_pos(all.tex.arrow2, 10, 650);
        sfRenderWindow_setFramerateLimit(all.window, 120);
        all.cn.fps = 120;
    }
    if (check_click(all.tex.fps144, 250, 100, all) == 1) {
        set_pos(all.tex.arrow2, 10, 760);
        sfRenderWindow_setFramerateLimit(all.window, 144);
        all.cn.fps = 144;
    }
    return (all);
}

all_t set_window(all_t all)
{
    if (check_click(all.tex.fullscreen, 610, 100, all) == 1 &&  \
        all.cn.window != 1) {
        set_pos(all.tex.arrow, 10, 160);
        sfRenderWindow_destroy(all.window);
        all.window = set_win("My Runner", all.cn.fps, 1);
        all.cn.window = 1;
    }
    else if (check_click(all.tex.windowed, 610, 100, all) == 1 &&       \
             all.cn.window != 0) {
        set_pos(all.tex.arrow, 10, 270);
        sfRenderWindow_destroy(all.window);
        all.window = set_win("My Runner", all.cn.fps, 0);
        all.cn.window = 0;
    }
    return (all);
}

all_t title(all_t all)
{
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
        }
    }
    return (all);
}

all_t analyse_event(all_t all)
{
    while (sfRenderWindow_pollEvent(all.window, &all.event)) {
        all = close_window(all);
    }
    return (all);
}

all_t close_window(all_t all)
{
    if (all.event.type == sfEvtClosed) {
        sfRenderWindow_close(all.window);
        all.cn.title = 0;
        all.cn.play = 0;
        all.cn.settings = 0;
        all.cn.win = 0;
        all.cn.end = 0;
        all.cn.pause = 0;
    }
    if (check_click(all.tex.quit, 340, 110, all) == 1 && all.cn.play != 1) {
        sfRenderWindow_close(all.window);
        all.cn.title = 0;
        all.cn.play = 0;
        all.cn.settings = 0;
        all.cn.win = 0;
        all.cn.end = 0;
        all.cn.pause = 0;
    }
    return (all);
}

all_t initialization(all_t all)
{
    all.window = set_win("My Runner", 60, 1);
    all = initialization_clock(all);
    all = initialization_tex(all);
    all = initialization_tex2(all);
    all = initialization_counter(all);
    all = initialization_text(all);
    all = initialization_rect(all);
    initialization_pos(all);
    initialization_pos_text(all);
    all.tex.spike = malloc(sizeof(sfSprite *) * 1000);
    all.tex.hole = malloc(sizeof(sfSprite *) * 1000);
    all.tex.wall = malloc(sizeof(sfSprite *) * 1000);
    all.re.hole = malloc(sizeof(sfIntRect) * 1000);
    all.re.wall = malloc(sizeof(sfIntRect) * 1000);
    all.hs = malloc(sizeof(char) * 1000);
    all.hs_file = malloc(sizeof(char) * 1000);
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
    return (all);
}

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

void display_pause(all_t all)
{
    sfRenderWindow_clear(all.window, sfBlack);
    sfRenderWindow_drawSprite(all.window, all.tex.far, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.midle, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.front, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.cadre, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.quit, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.play, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.menu, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.run, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.jump, NULL);
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

int check_click(sfSprite *sprite, int x, int y, all_t all)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
        if (sfMouse_getPositionRenderWindow(all.window).x >=    \
            sfSprite_getPosition(sprite).x &&                   \
            sfMouse_getPositionRenderWindow(all.window).x <=    \
            sfSprite_getPosition(sprite).x + x &&               \
            sfMouse_getPositionRenderWindow(all.window).y >=    \
            sfSprite_getPosition(sprite).y &&                   \
            sfMouse_getPositionRenderWindow(all.window).y <=    \
            sfSprite_getPosition(sprite).y + y) {
            all.event.mouseButton.type = sfEvtMouseButtonReleased;
            return (1);
        }
        all.event.mouseButton.type = sfEvtMouseButtonReleased;
    }
    return (0);
}

void set_pos(sfSprite *sprite, int x, int y)
{
    sfVector2f pos = {x, y};

    sfSprite_setPosition(sprite, pos);
}

void set_pos_text(sfText *text, int x, int y)
{
    sfVector2f pos = {x, y};

    sfText_setPosition(text, pos);
}

sfText *create_text(sfText *text, int size, char *str)
{
    sfText* tmp;

    text = sfText_create();
    sfText_setString(text, str);
    sfText_setFont(text, sfFont_createFromFile("files/font.ttf"));
    sfText_setCharacterSize(text, size);
    return (text);
}

sfSprite *create_sprite(sfSprite *sprite, char *file)
{
    sfTexture *texture;

    texture = sfTexture_createFromFile(file, NULL);
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    return (sprite);
}

sfRenderWindow *set_win(char *title, int fps, int fullscreen)
{
    sfRenderWindow *window = NULL;
    sfVideoMode mode = {1920, 1080, 32};

    if (fullscreen == 0)
        window = sfRenderWindow_create(mode, title, sfClose, NULL);
    else
        window = sfRenderWindow_create(mode, title, sfFullscreen, NULL);
    sfRenderWindow_setFramerateLimit(window, fps);
    sfRenderWindow_setKeyRepeatEnabled(window, sfFalse);
    return (window);
}
