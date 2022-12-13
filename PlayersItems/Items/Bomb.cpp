/*
** EPITECH PROJECT, 2021
** B-YEP-400-MAR-4-1-indiestudio-mathys.le-juez [WSL: Ubuntu-20.04]
** File description:
** Bomb
*/

#include "../../Includes/Items/Bomb.hpp"

Bomb::Bomb(const int &pos, int range) : Item(pos), _range(range)
{
    _exploded = 0;
    _time = 0;
}

Bomb::~Bomb()
{
}

int Bomb::getRange(void) const
{
    return (_range);
}

int Bomb::getExploded(void)
{
    return (_exploded);
}

int Bomb::getTime()
{
    return (_time);
}

void Bomb::SetTime(int newValue)
{
    _time = newValue;
}

int Bomb::checkFireArea(int y, int x, TYPE_MAP &map, std::vector<int *> &posFire)
{
    if (map[y][x])
    {
        switch (map[y][x])
        {
            case WALL:
                return (1);
                break;
            case SPC:
                posFire.push_back(new int[2]{y, x});
                break;
            case BOMB:
                posFire.push_back(new int[2]{y, x});
                break;
            default:
                posFire.push_back(new int[2]{y, x});
                return (1);
                break;
        }
        return (0);
    }
    return (1);
}

void Bomb::putFireRight(std::vector<std::string> &map, std::vector<int *> &posFire)
{
    for (int index = 1; index <= _range; index++)
    {
        if (checkFireArea(_pos[0], _pos[1] + index, map, posFire) == 1)
            break;
    }
}

void Bomb::putFireLeft(std::vector<std::string> &map, std::vector<int *> &posFire)
{
    for (int index = 1; index <= _range; index++)
    {
        if (checkFireArea(_pos[0], _pos[1] - index, map, posFire) == 1)
            break;
    }
}

void Bomb::putFireUp(std::vector<std::string> &map, std::vector<int *> &posFire)
{
    for (int index = 1; index <= _range; index++)
    {
        if (checkFireArea(_pos[0] + index, _pos[1], map, posFire) == 1)
            break;
    }
}

void Bomb::putFireDown(std::vector<std::string> &map, std::vector<int *> &posFire)
{
    for (int index = 1; index <= _range; index++)
    {
        if (checkFireArea(_pos[0] - index, _pos[1], map, posFire) == 1)
            break;
    }
}

std::vector<int *> Bomb::activeEffect(std::vector<std::string> &map)
{
    std::vector<int *> posFire;

    _exploded = 1;
    map[_pos[0]][_pos[1]] = FIRE;
    posFire.push_back(_pos);
    putFireRight(map, posFire);
    putFireLeft(map, posFire);
    putFireUp(map, posFire);
    putFireDown(map, posFire);
    return (posFire);
}