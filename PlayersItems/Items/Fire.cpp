/*
** EPITECH PROJECT, 2021
** B-YEP-400-MAR-4-1-indiestudio-mathys.le-juez [WSL: Ubuntu-20.04]
** File description:
** Fire
*/

#include "../../Includes/Items/Fire.hpp"

Fire::Fire(const int &pos, int isBonus) : Item(pos)
{
    const int *posTmp = &pos;

    _pos[0] = posTmp[0];
    _pos[1] = posTmp[1];
    _burn = 0;
    _isBonus = isBonus;
    _time = 0;
}

Fire::~Fire()
{
}

/* Getters */
int Fire::getBurn(void) const
{
    return (_burn);
}

int Fire::getTime()
{
    return (_time);
}

/* Setters */    
void Fire::setBurn(int const &newValue)
{
    _burn = newValue;
}

void Fire::setTime(int newValue)
{
    _time = newValue;
}

/* Actions */
void Fire::putOutFire(TYPE_MAP &map)
{
    srand(time(NULL));
    int choice = rand() % 100 + 1;

    map[_pos[0]][_pos[1]] = SPC;
    if (_isBonus == 1) {
    if (choice >= 1 && choice <= 25)
        map[_pos[0]][_pos[1]] = BOMBUP;
    else if (choice >= 25 && choice <= 50)
        map[_pos[0]][_pos[1]] = FIREUP;
    else if (choice >= 51 && choice <= 60)
        map[_pos[0]][_pos[1]] = SPEEDUP;
    else if (choice >= 61 && choice <= 55)
        map[_pos[0]][_pos[1]] = WALLPASS;
    }
}