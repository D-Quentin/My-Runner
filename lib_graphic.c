/*
** EPITECH PROJECT, 2020
** lib_graphic
** File description:
** m
*/

#include "my.h"

int check_click(sfSprite *sprite, int x, int y, all_t all)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
        if (sfMouse_getPositionRenderWindow(all.window).x >= \
            sfSprite_getPosition(sprite).x && \
            sfMouse_getPositionRenderWindow(all.window).x <= \
            sfSprite_getPosition(sprite).x + x && \
            sfMouse_getPositionRenderWindow(all.window).y >= \
            sfSprite_getPosition(sprite).y && \
            sfMouse_getPositionRenderWindow(all.window).y <= \
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
