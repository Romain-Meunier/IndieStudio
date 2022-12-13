/*
** EPITECH PROJECT, 2021
** B-YEP-400-MAR-4-1-indiestudio-mathys.le-juez [WSL: Ubuntu-20.04]
** File description:
** Fire
*/

#ifndef FIRE_HPP_
#define FIRE_HPP_
#include "../Item.hpp"

class Fire : public Item
{
    public:
        Fire(const int &pos, int isBonus);
        ~Fire();
        /* Getters */
        int getBurn(void) const;
        int getTime(void);
        /* Setters */
        void setBurn(int const &newValue);
        void setTime(int newValue);
        /* Actions */
        void putOutFire(TYPE_MAP &map);
    protected:
    private:
        int _burn; // 0 if it burn, 1 if it is
        int _isBonus;
        int _pos[2];
        int _time; // chrono fire
};

#endif /* !FIRE_HPP_ */