/*
** EPITECH PROJECT, 2020
** test_for_raylib
** File description:
** raylib_func.h
*/
#include "raylib.h"
#include <vector>
#include <string>

#define WALL '#'
#define BOMB 'Q'
#define FLOOR ' '
#define BLOCK '+'
#define PLAYER 'P'

#ifndef RAYLIB_FUNC_H
#define RAYLIB_FUNC_H

class raylib_func
{
    private:
        /* data */
    public:
        raylib_func(/* args */);
        ~raylib_func();
        int create_window(void);
        int window_option(void);
        void draw_menu(int Width, int Height);
        void dina_start(int Width, int Height);
        void dina_option(int Width, int Height);
        void dina_exit(int Width, int Height);
        void dina_button(int play, int setting, int leave);
        int button_start(Rectangle PosStart, Vector2 MousePos);
        int button_option(Rectangle PosOption, Vector2 MousePos);
        int button_exit(Rectangle PosExit, Vector2 MousePos);
        int setting_sound(Rectangle PosSound, Vector2 MousePos);
        int setting_exit(Rectangle PosExit, Vector2 MousePos);
        int setting_return(Rectangle PosReturn, Vector2 MousePos);
        void dina_settings(int sound_button, int exit_button, int return_button);
        void dina_sound(int Width, int Height);
        void dina_op_exit(int Width, int Height);
        void dina_return(int Width, int Height);
        int findPlyerX(std::vector<std::string> map);
        int findPlayerY(std::vector<std::string> map);
        void parseMap(std::vector<std::string> _mapItem, std::vector<std::string> _mapPlayer, Texture2D _caisse, Texture2D _wall, Texture2D _floor);
        void drawMap(std::vector<std::string> _mapItem, std::vector<std::string> _mapPlayer);
};

#endif