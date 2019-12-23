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
};

typedef struct counter_s counter_t;
struct counter_s {
    int play;
    int settings;
    int title;
    int fps;
    int window;
};

typedef struct text_s text_t;
struct text_s {
    sfText *graphics;
    sfText *fps;
};

typedef struct clocks_s clocks_t;
struct clocks_s {
    sfClock *front;
    sfClock *midle;
    sfClock *far;
};

typedef struct all_s all_t;
struct all_s {
    sfRenderWindow *window;
    sfEvent event;
    texture_t tex;
    clocks_t cl;
    counter_t cn;
    text_t tx;
};

sfSprite *create_sprite(sfSprite *sprite, char *file);
sfRenderWindow *set_win(char *title, int fps, int fullscreen);
all_t initialization(all_t all);
void initialization_pos(all_t all);
all_t initialization_tex(all_t all);
all_t initialization_counter(all_t all);
all_t initialization_text(all_t all);
void display_title(all_t all);
void display_settings(all_t all);
void set_pos(sfSprite *sprite, int x, int y);
void parallax_reset(all_t all);
void parallax(all_t all);
all_t title(all_t all);
all_t settings(all_t all);
all_t analyse_event(all_t all);
all_t close_window(all_t all);
int check_click(sfSprite *sprite, int x, int y, all_t all);
sfText *create_text(sfText *text, int size, char *str);
void set_pos_text(sfText *text, int x, int y);
all_t set_fps(all_t all);
all_t set_window(all_t all);

void main(int ac, char **av)
{
    all_t all;

    all = initialization(all);
    while (sfRenderWindow_isOpen(all.window)) {
        if (all.cn.title == 1)
            all = title(all);
        if (all.cn.settings == 1)
            all = settings(all);
        if (all.cn.play == 1)
            all = play(all);
    }
}

all_t play(all_t all)
{
    

all_t settings(all_t all)
{
    while (all.cn.settings == 1) {
        parallax(all);
        display_settings(all);
        all = set_fps(all);
        all = set_window(all);
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
    if (check_click(all.tex.fullscreen, 610, 100, all) == 1 && \
        all.cn.window != 1) {
        set_pos(all.tex.arrow, 10, 160);
        sfRenderWindow_destroy(all.window);
        all.window = set_win("My Runner", all.cn.fps, 1);
        all.cn.window = 1;
    }
    else if (check_click(all.tex.windowed, 610, 100, all) == 1 &&      \
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
    }
    if (check_click(all.tex.quit, 340, 110, all) == 1) {
        sfRenderWindow_close(all.window);
        all.cn.title = 0;
        all.cn.play = 0;
        all.cn.settings = 0;
    }
    return (all);
}

all_t initialization(all_t all)
{
    all.window = set_win("My Runner", 60, 1);
    all.cl.front = sfClock_create();
    all.cl.midle = sfClock_create();
    all.cl.far = sfClock_create();
    all = initialization_tex(all);
    all = initialization_counter(all);
    all = initialization_text(all);
    initialization_pos(all);
    return (all);
}

void parallax(all_t all)
{
    sfVector2f move = {-1, 0};
    
    parallax_reset(all);
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(all.cl.front)) > 10) {
        sfSprite_move(all.tex.front, move);
        sfClock_restart(all.cl.front);
    }
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(all.cl.midle)) > 40) {
        sfSprite_move(all.tex.midle, move);
        sfClock_restart(all.cl.midle);        
    }
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(all.cl.far)) > 70) {
        sfSprite_move(all.tex.far, move);
        sfClock_restart(all.cl.far);        
    }
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
    set_pos_text(all.tx.graphics, 80, 20);
    set_pos_text(all.tx.fps, 80, 390);
    set_pos(all.tex.arrow2, 10, 530);
    set_pos(all.tex.arrow, 10, 160);
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
    all.tex.my_runner = create_sprite(all.tex.my_runner, "files/my_runner.png");
    all.tex.fullscreen = create_sprite(all.tex.fullscreen, "files/fullscreen.png");
    all.tex.windowed = create_sprite(all.tex.windowed, "files/windowed.png");
    all.tex.fps60 = create_sprite(all.tex.fps60, "files/60.png");
    all.tex.fps120 = create_sprite(all.tex.fps120, "files/120.png");
    all.tex.fps144 = create_sprite(all.tex.fps144, "files/144.png");
    all.tex.menu = create_sprite(all.tex.menu, "files/menu.png");
    all.tex.arrow = create_sprite(all.tex.arrow, "files/arrow.png");
    all.tex.arrow2 = create_sprite(all.tex.arrow2, "files/arrow.png");
    return (all);
}

all_t initialization_text(all_t all)
{
    all.tx.graphics = create_text(all.tx.graphics, 80, "Graphics settings :");
    all.tx.fps = create_text(all.tx.fps, 80, "FPS :");
    return (all);
}

all_t initialization_counter(all_t all)
{
    all.cn.title = 1;
    all.cn.play = 0;
    all.cn.settings = 0;
    all.cn.fps = 60;
    all.cn.window = 1;
    return (all);
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
