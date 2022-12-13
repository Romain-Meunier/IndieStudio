/*
** EPITECH PROJECT, 2021
** B-YEP-400-MAR-4-1-indiestudio-mathys.le-juez [WSL: Ubuntu-20.04]
** File description:
** CollisionManger
*/

#ifndef COLLISIONMANGER_HPP_
#define COLLISIONMANGER_HPP_
#include "Interfaces/IInteractionManager.hpp"

class InteractionManager : public IInteractionManager
{
    public:
        InteractionManager();
        ~InteractionManager();
        /* Getters */
        virtual std::vector<Player *> const &getPlayersList(void);
        virtual std::vector<Fire *> const &getFireList(void);
        /* Setters */
        virtual void setPlayersList(std::vector<Player *> const &newVector); // Clean PlayersList and recreate a new
        /* Action */
        virtual int hurtPlayer(TYPE_MAP &mapPlayer, int x, int y);
        virtual void putFireBis(std::vector<std::string> &map, TYPE_MAP &mapPlayer, std::vector<int *> &posFire, std::vector<Bomb *> &listBomb, int index);
        virtual void putFire(std::vector<std::string> &map, TYPE_MAP &mapPlayer, std::vector<int *> &posFire, std::vector<Bomb *> &listBomb);
        virtual void bombManagement(std::vector<std::string> &map, TYPE_MAP &mapPlayer);
        virtual void fireManagement(TYPE_MAP &map);
    protected:
    private:
        std::vector<Player *> _playersList;
        std::vector<Fire *> _fireList;
};

#endif /* !COLLISIONMANGER_HPP_ */