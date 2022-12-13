/*
** EPITECH PROJECT, 2021
** B-YEP-400-MAR-4-1-indiestudio-mathys.le-juez [WSL: Ubuntu-20.04]
** File description:
** Item
*/

#ifndef ITEM_HPP_
#define ITEM_HPP_
#include "Interfaces/IItem.hpp"

class Item : public IItem
{
    public:
        Item(const int &pos);
        ~Item();
        /* Getters */
        virtual const int &getPos(void) const; // Usage :: const int *["Reception"] = &["function"]
        virtual int activeEffect(void);
    protected:
        int _pos[2];                           // Position pos[0] = X, pos[1] = Y
    private:
};
#endif /* !ITEM_HPP_ */