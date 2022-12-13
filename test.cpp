#include "Includes/MapManagement.hpp"
#include "Includes/Player.hpp"
#include "Includes/InteractionManager.hpp"
#include "raylib_func.hpp" // sujet a changement
#include <raylib.h>



int raylib_func::findPlyerX(std::vector<std::string> map)
{
    size_t x = 0;
    size_t y = 0;
    for (x = 0;x < 11;) {
        for (y = 0;y < 11 ;y++) {
            if (y == 11) {
                x = x + 1;
            }
            if (map[x][y] == PLAYER) {
                return (x);
            }
        }
        x++;
    }
}

int raylib_func::findPlayerY(std::vector<std::string> map)
{
    size_t x = 0;
    size_t y = 0;
    for (x = 0;x < 11;) {
        for (y = 0;y < 11 ;y++) {
            if (y == 11) {
                x = x + 1;
            }
            if (map[x][y] == PLAYER) {
                return (y);
            }
        }
        x++;
    }
}

void raylib_func::parseMap(std::vector<std::string> _mapItem, std::vector<std::string> _mapPlayer, Texture2D _caisse, Texture2D _wall, Texture2D _floor)
{
    float _sizeX = -2.5;
    float _sizeY = 4;
    Vector3 cubePosition = {_sizeX,_sizeY, 0};
    Vector3 cubeSize = { 0.6f, 0.6f, 0.6f };
    Vector2 CaissePose {_sizeX, _sizeY};
    int _PlayerX = findPlyerX(_mapPlayer);
    int _PlayerY = findPlayerY(_mapPlayer);
    size_t x = 0;
    size_t y = 0;
    
    for (x = 0;x < 11;) {
        for (y = 0;y < 11 ;y++) {
            if (y ==  11) { 
                
                x = x + 1;
                y = -1;
            }
            if (x == _PlayerX && y == _PlayerY) {
               DrawCube(cubePosition, cubeSize.x, cubeSize.y, 1, PINK);
              
                
            } else {
                if (_mapItem[x][y] == WALL) {
                    DrawCubeTexture(_wall,cubePosition, cubeSize.x, cubeSize.y, 1, WHITE);
                }
                if (_mapItem[x][y] == BOMB) {
                    DrawCube(cubePosition, cubeSize.x, cubeSize.y, 1, BLUE);

                }
                if (_mapItem[x][y] == FLOOR) {
                    DrawCubeTexture(_floor,cubePosition, cubeSize.x, cubeSize.y, 0, WHITE);
                }
                if (_mapItem[x][y] == BLOCK) {
                    DrawCubeTexture(_caisse,cubePosition, cubeSize.x, cubeSize.y, 1, WHITE);
                   
                }
            }
            cubePosition.x += 0.6;             
        }
        cubePosition.x = -2.5; 
        cubePosition.y -= 0.6;
        x++;
    }
    
    
}

void move_map(std::vector<std::string> _mapItem, std::vector<std::string> _mapPlayer, Texture2D _caisse, Texture2D _wall, Texture2D _floor)
{
    raylib_func raylib_func;
    raylib_func.parseMap(_mapItem, _mapPlayer,_caisse, _wall, _floor);
}


void raylib_func::drawMap(std::vector<std::string> _mapItem, std::vector<std::string> _mapPlayer)
{
    InteractionManager global;
    int Width = 1920;
    int Height = 1080;

    int pos[2] = {1,1};
    std::string name = "Louise";

    std::vector<Player *> tmp;
    tmp.push_back(new Player (name, pos[0], _mapPlayer));
    global.setPlayersList(tmp);
    InitWindow(Width, Height, "test");
    Camera3D camera = { 0 };
    camera.position = (Vector3){0, -4, 10 }; // Camera position set a x: 0 y: -4 z: 10
    camera.target = (Vector3){ 0, 1, 0 };      // Camera looking at point
    camera.up = (Vector3){0,2, 0 };          // Camera up vector (rotation towards target)
    camera.fovy = 45;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;                   // Camera mode type
    
    Image caisse = LoadImage("texture/caisse.png");
    Image wall = LoadImage("texture/wall.png");
    Image floor = LoadImage("texture/floor.png");
    Texture2D TexCaisse = LoadTextureFromImage(caisse);
    Texture2D TexWall = LoadTextureFromImage(wall);
    Texture2D TexFloor = LoadTextureFromImage(floor);
    
    UnloadImage(caisse);
    UnloadImage(wall);
    UnloadImage(floor);
    SetCameraMode(camera, CAMERA_FREE);
    int test = 0;
    while (!WindowShouldClose())
    {
        /*if (IsKeyPressed(KEY_RIGHT)) 
        if (IsKeyPressed(KEY_LEFT)) 
        if (IsKeyPressed(KEY_UP)) 
        if (IsKeyPressed(KEY_DOWN)) {
            test = 1;  
            global.getPlayersList()[0]->moveDown(_mapItem, _mapPlayer);
        }
        if (IsKeyDown(KEY_SPACE)) global.getPlayersList()[0]->putBomb(_mapItem);*/
        BeginDrawing();
        ClearBackground(BLACK);
        BeginMode3D(camera);
            move_map(_mapItem, _mapPlayer,TexCaisse, TexWall, TexFloor);
        EndMode3D();
            if (test == 1 ) {
                DrawText("key", 0, 0, 10, WHITE);
            }
            
        EndDrawing();
        
    }
    UnloadTexture(TexCaisse);
    UnloadTexture(TexWall);
    UnloadTexture(TexFloor);
    
}
