/*
** EPITECH PROJECT, 2021
** B-YEP-400-MAR-4-1-indiestudio-mathys.le-juez [WSL: Ubuntu-20.04]
** File description:
** IPlayer
*/

#ifndef IPLAYER_HPP_
#define IPLAYER_HPP_
#include "../proto.hpp"
#include "../Items/Bomb.hpp"

class IPlayer
{
    public:
        ~IPlayer() = default;
        /* Getters */
        virtual const std::string &getName(void) const = 0;
        virtual int getLifeAct(void) const = 0;
        virtual int getLifeMax(void) const = 0;
        virtual int getSpeed(void) const = 0;
        virtual int getBombNb(void) const = 0;
        virtual int getBombRange(void) const = 0;
        virtual const std::vector<Bomb *> &getBombList(void) const = 0;
        virtual const int &getPos(void) const = 0;
        /* Setters */
        virtual void setLifeAct(const int newNb) = 0;
        virtual void setLifeMax(const int newNb) = 0;
        virtual void setSpeed(const int newSpeed) = 0;
        virtual void setBombNb(const int newNb) = 0;
        /* Movements */
        virtual int checkCase(int y, int x, TYPE_MAP &map, TYPE_MAP &mapPlayer) = 0;
        virtual int moveLeft(TYPE_MAP &map, TYPE_MAP &map_player) = 0;
        virtual int moveRight(TYPE_MAP &map, TYPE_MAP &map_player) = 0;
        virtual int moveUp(TYPE_MAP &map, TYPE_MAP &map_player) = 0;
        virtual int moveDown(TYPE_MAP &map, TYPE_MAP &map_player) = 0;
        /* Actions */
        virtual void putBomb(TYPE_MAP &map) = 0;
        virtual int takeDamage(int nbDamage) = 0;
        virtual void wallPassActivation(void) = 0;
    protected:
    private:
};

#endif /* !IPLAYER_HPP_ */
