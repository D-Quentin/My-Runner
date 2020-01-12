/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** m
*/

#include <SFML/Window.h>
#include <SFML/Config.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <unistd.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Joystick.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Window/Sensor.h>
#include <SFML/System/Export.h>
#include <SFML/System/Types.h>
#include <SFML/System/Time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>
#include <SFML/Audio.h>

typedef struct texture_s texture_t;
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

typedef struct music_s music_t;
struct music_s {
    sfMusic *title;
    sfMusic *play;
    sfMusic *win;
    sfMusic *tp;
    sfMusic *jump;
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
    music_t mu;
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
all_t initialization_music(all_t all);
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
all_t hit_box3(all_t all);
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
int syntax(int ac, char **av);
void destroy(all_t all);
void destroy_music(all_t all);
