/*
** EPITECH PROJECT, 2021
** B-YEP-400-MAR-4-1-indiestudio-mathys.le-juez [WSL: Ubuntu-20.04]
** File description:
** IItem
*/

#ifndef IITEM_HPP_
#define IITEM_HPP_
#include "../proto.hpp"

class IItem
{
    public:
        ~IItem() = default;
        /* Getters */
        virtual const int &getPos(void) const = 0;
        /* Actions */
        virtual int activeEffect(void) = 0;
    protected:
    private:
};

#endif /* !IITEM_HPP_ */