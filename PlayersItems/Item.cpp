/*
** EPITECH PROJECT, 2021
** B-YEP-400-MAR-4-1-indiestudio-mathys.le-juez [WSL: Ubuntu-20.04]
** File description:
** Item
*/

#include "../Includes/Item.hpp"

Item::Item(const int &pos)
{
    const int *posTmp = &pos;

    _pos[0] = posTmp[0];
    _pos[1] = posTmp[1];
}

Item::~Item()
{
}

int Item::activeEffect(void)
{
    std::cout << "L'effect de l'item n'est pas fait" << std::endl;
    return (0);
}

const int &Item::getPos(void) const
{
    return (_pos[0]);
}