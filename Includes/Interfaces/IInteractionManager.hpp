/*
** EPITECH PROJECT, 2021
** B-YEP-400-MAR-4-1-indiestudio-mathys.le-juez [WSL: Ubuntu-20.04]
** File description:
** CollisionManager
*/

#ifndef ICOLLISIONMANAGER_HPP_
#define ICOLLISIONMANAGER_HPP_
#include "../proto.hpp"

#include "../Player.hpp"
#include "../Items/Fire.hpp"
#include "../Items/Bomb.hpp"
class IInteractionManager
{
    public:
        virtual ~IInteractionManager() = default;
        /* Getters */
        virtual std::vector<Player *> const &getPlayersList(void) = 0;
        virtual std::vector<Fire *> const &getFireList(void) = 0;
        /* Setters */
        virtual void setPlayersList(std::vector<Player *> const &newVector) = 0;
        /* Action */
        virtual int hurtPlayer(TYPE_MAP &mapPlayer, int x, int y) = 0;
        virtual void putFireBis(std::vector<std::string> &map, TYPE_MAP &mapPlayer, std::vector<int *> &posFire, std::vector<Bomb *> &listBomb, int index) = 0;
        virtual void putFire(std::vector<std::string> &map, TYPE_MAP &mapPlayer, std::vector<int *> &posFire, std::vector<Bomb *> &listBomb) = 0;
        virtual void bombManagement(std::vector<std::string> &map, TYPE_MAP &mapPlayer) = 0;
        virtual void fireManagement(TYPE_MAP &map) = 0;
    protected:
    private:
};

#endif /* !COLLISIONMANAGER_HPP_ */
