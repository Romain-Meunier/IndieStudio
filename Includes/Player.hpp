/*
** EPITECH PROJECT, 2021
** B-YEP-400-MAR-4-1-indiestudio-mathys.le-juez [WSL: Ubuntu-20.04]
** File description:
** Player
*/
#ifndef PLAYER_HPP_
#define PLAYER_HPP_
#include "Interfaces/IPlayer.hpp"

class Player : public IPlayer
{
    public:
        Player(const std::string &name, const int &pos, TYPE_MAP &map_player);
        ~Player();
        /* Getters */
        virtual const std::string &getName(void) const;
        virtual int getLifeAct(void) const;
        virtual int getLifeMax(void) const;
        virtual int getSpeed(void) const;
        virtual int getBombNb(void) const;
        virtual int getBombRange(void) const;
        virtual const std::vector<Bomb *> &getBombList(void) const;
        virtual const int &getPos(void) const; // Usage :: const int *["Reception"] = &["function"]
        /* Setters */
        virtual void setLifeAct(const int newNb);
        virtual void setLifeMax(const int newNb);
        virtual void setSpeed(const int newSpeed);
        virtual void setBombNb(const int newNb);
        virtual void setBombRange(const int newNb);
        /* Movements */
        virtual int checkCase(int y, int x, TYPE_MAP &map, TYPE_MAP &mapPlayer);
        virtual int moveLeft(TYPE_MAP &map, TYPE_MAP &map_player);
        virtual int moveRight(TYPE_MAP &map, TYPE_MAP &map_player);
        virtual int moveUp(TYPE_MAP &map, TYPE_MAP &map_player);
        virtual int moveDown(TYPE_MAP &map, TYPE_MAP &map_player);
        /* Actions */
        virtual void putBomb(TYPE_MAP &map);
        virtual int takeDamage(int nbDamage);
        virtual void wallPassActivation(void);
    protected:
    private:
        const std::string _name;        // Name of the player
        int _lifeAct;                   // Number of life actually
        int _lifeMax;                   // Number of life maximum
        int _speed;                     // Speed of player
        int _bombNb;                    // Number of bomb which can be drop
        int _bombRange;                 // Range of bomb which can be drop
        int _pos[2];                    // Position pos[0] = X, pos[1] = Y
        std::vector<Bomb *> _bombList;    // List of all bomb of the player
        int _wallPassAct;               // 0 it's normal, 1 it's active
};

#endif /* !PLAYER_HPP_ */
