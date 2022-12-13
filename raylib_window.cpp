/*
** EPITECH PROJECT, 2020
** test_for_raylib
** File description:
** raylib_window.c
*/
#include "Includes/MapManagement.hpp"
#include "Includes/Player.hpp"
#include "Includes/InteractionManager.hpp"
#include "raylib.h"
#include "raylib_func.hpp"
#include <iostream>
#include <chrono>
#include <time.h>
#include <ctime>

using namespace std::chrono;

void raylib_func::dina_button(int play, int setting, int leave)
{
    int Width = 1920;
    int Height = 1080;

    if (play == 1) {
        raylib_func::dina_start(Width, Height);
    }
    if (play == 2) {
        raylib_func::dina_start(Width, Height);
    }
    if (setting == 1) {
        raylib_func::dina_option(Width, Height);
    }
    if (setting == 2) {
        raylib_func::dina_option(Width, Height);
    }
    if (leave == 1) {
        raylib_func::dina_exit(Width, Height);
    }
    if (leave == 2) {
        raylib_func::dina_exit(Width, Height);
    }
}

void raylib_func::dina_start(int Width, int Height)
{
    DrawRectangle(Width/4*2 - 160, 400, 320, 100, YELLOW); //shape for button "START"
    DrawText("START", 850, 420, 60, DARKPURPLE); //text button "START"
}

void raylib_func::dina_option(int Width, int Height)
{
    DrawRectangle(Width/4*2 - 160, 600, 320, 100, YELLOW); //shape for button "OPTION"
    DrawText("OPTION", 845, 620, 60, DARKPURPLE); //text button "OPTION"

}

void raylib_func::dina_exit(int Width, int Height)
{
    DrawRectangle(Width/4*2 - 160, 800, 320, 100, YELLOW); //shape for button "EXIT"
    DrawText("EXIT", 890, 820, 60, DARKPURPLE); //text button "EXIT"
}

int raylib_func::button_exit(Rectangle PosExit, Vector2 MousePos)
{
    MousePos = GetMousePosition();
    if (CheckCollisionPointRec(MousePos, PosExit))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
                return (1);
            } else{return(2);}
        }else {return (-1);}
}
int raylib_func::button_option(Rectangle PosOption, Vector2 MousePos)
{
    MousePos = GetMousePosition();
    if (CheckCollisionPointRec(MousePos, PosOption))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
                return (1);
            } else{return(2);}
        }else {return (-1);}
}

int raylib_func::button_start(Rectangle PosStart, Vector2 MousePos)
{
    MousePos = GetMousePosition();
    if (CheckCollisionPointRec(MousePos, PosStart))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
                return (1);
            } else{return(2);}
        }else {return (-1);}
}

void raylib_func::draw_menu(int Width, int Height)
{
    DrawText("MENU", 870, 260, 60, YELLOW); //title "MENU"

    DrawRectangle(Width/4*2 - 160, 400, 320, 100, DARKPURPLE); //shape for button "START"
    DrawText("START", 850, 420, 60, YELLOW); //text button "START"

    DrawRectangle(Width/4*2 - 160, 600, 320, 100, DARKPURPLE); //shape for button "OPTION"
    DrawText("OPTION", 845, 620, 60, YELLOW); //text button "OPTION"

    DrawRectangle(Width/4*2 - 160, 800, 320, 100, DARKPURPLE); //shape for button "EXIT"
    DrawText("EXIT", 890, 820, 60, YELLOW
    ); //text button "EXIT"
}

int raylib_func::setting_sound(Rectangle PosSound, Vector2 MousePos)
{
    MousePos = GetMousePosition();

    if (CheckCollisionPointRec(MousePos, PosSound)) {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            return (1);
        } else
            return (2);
    } else
        return (-1);
}

int raylib_func::setting_exit(Rectangle PosExit, Vector2 MousePos)
{
    MousePos = GetMousePosition();

    if (CheckCollisionPointRec(MousePos, PosExit)) {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            return (1);
        } else
            return (2);
    } else
        return (-1);
}

int raylib_func::setting_return(Rectangle PosReturn, Vector2 MousePos)
{
    MousePos = GetMousePosition();

    if (CheckCollisionPointRec(MousePos, PosReturn)) {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            return (1);
        } else
            return (2);
    } else
        return (-1);
}

void raylib_func::dina_settings(int sound_button, int exit_button, int return_button)
{
    int Width = 1920;
    int Height = 1080;

    if (sound_button == 1) {
        raylib_func::dina_sound(Width, Height);
    }
    if (sound_button == 2) {
        raylib_func::dina_sound(Width, Height);
    }
    if (exit_button == 1) {
        raylib_func::dina_op_exit(Width, Height);
    }
    if (exit_button == 2) {
        raylib_func::dina_op_exit(Width, Height);
    }
    if (return_button == 1) {
        raylib_func::dina_return(Width, Height);
    }
    if (return_button == 2) {
        raylib_func::dina_return(Width, Height);
    }
}

void raylib_func::dina_return(int Width, int Height)
{
    DrawRectangle(Width/4*2 - 160, 428, 320, 100, WHITE);
    DrawText("Return", 860, 440, 60, GRAY);
}

void raylib_func::dina_op_exit(int Width, int Height)
{
    DrawRectangle(Width/4*2 - 160, 600, 320, 100, WHITE);
    DrawText("Exit", 905, 622, 60, GRAY);
}

void raylib_func::dina_sound(int Width, int Height)
{
    DrawRectangle(Width/4*2 - 160, 248, 320, 100, WHITE); //shape for button "EXIT"
    DrawText("Sound", 870, 270, 60, GRAY); //text button "EXIT"
}

int raylib_func::window_option(void)
{
    int Width = 1920;
    int Height = 1080;

    Rectangle sound = { float(Width/4*2 - 110), 248, 213, 70 };
    Rectangle exit = { float(Width/4*2 - 75), 600, 213, 70 };
    Rectangle return_ = { float(Width/4*2 - 110), 440, 213, 70};
    Vector2 MousePos = { 0.0f, 0.0f };
    time_t timer;
    time(&timer);
    InitWindow(Width, Height, "INDIE STUDIO : OPTION PAGE");

    while (!WindowShouldClose()) {
        int sound_button = raylib_func::setting_sound(sound, MousePos);
        int exit_button = raylib_func::setting_exit(exit, MousePos);
        int return_button = raylib_func::setting_return(return_, MousePos);
        BeginDrawing();
        DrawText("Settings", 785, 90, 80, BLACK);
        DrawText("Sound", 870, 270, 60, WHITE);
        DrawText("Exit", 905, 622, 60, WHITE);
        DrawText("Return", 860, 440, 60, WHITE);
        raylib_func::dina_settings(sound_button, exit_button, return_button);
        DrawText(TextFormat("Time : %d", timer), 100, 100, 80, BLACK);
        if (sound_button == 1) {
            DrawText("______", 851, 246, 60, BLACK);
        }
        if (exit_button == 1) {
            return (1);
        }
        if (return_button == 1) {
            create_window();
            break;
        }
        ClearBackground(GRAY);
        EndDrawing();
    }
    CloseWindow();
}

int raylib_func::create_window(void)
{
    
    MapManagement map (10);

    int Width = 1920;
    int Height = 1080;

    InitWindow(Width, Height, "INDIE STUDIO 2021");
    Image logo = LoadImage("texture/Logo.png");
    Texture2D texture = LoadTextureFromImage(logo);

    Rectangle start = { float(Width/4*2 - 160), 400, 320, 100};
    Rectangle option = { float(Width/4*2 - 160), 600, 320, 100};
    Rectangle exit = { float(Width/4*2 - 160), 800, 320, 100};

    Vector2 MousePos = { 0.0f, 0.0f };
    Music music = LoadMusicStream("texture/mus_menu.mp3");
    UnloadImage(logo);
    PlayMusicStream(music);
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        int play = raylib_func::button_start(start, MousePos);
        int setting = raylib_func::button_option(option, MousePos);
        int leave = raylib_func::button_exit(exit, MousePos);
        
        BeginDrawing();

            ClearBackground(DARKPURPLE);

            DrawTexture(texture, 930 - texture.width/2, 100 - texture.height/2, WHITE);
            raylib_func::draw_menu(Width, Height);
            raylib_func::dina_button(play, setting, leave);
            if (play == 1) {
                raylib_func::drawMap(map._mapItems, map._mapPlayer);
            }
            if (leave == 1) {break;}
            if (setting == 1) {
                EndDrawing();
                CloseWindow();
                int sto = window_option();
                if (sto == 1) break;
            }
            
        EndDrawing();
    }
    UnloadTexture(texture);
    CloseWindow();
}