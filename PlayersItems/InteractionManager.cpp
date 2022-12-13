/*
** EPITECH PROJECT, 2021
** B-YEP-400-MAR-4-1-indiestudio-mathys.le-juez [WSL: Ubuntu-20.04]
** File description:
** InteractionManager
*/

#include "../Includes/InteractionManager.hpp"

InteractionManager::InteractionManager()
{
}

InteractionManager::~InteractionManager()
{
    for (size_t index = 0; _playersList.size() > index; index++)
        delete _playersList[index];
    _playersList.clear();
    for (size_t index = 0; _fireList.size() > index; index++)
        delete _fireList[index];
    _fireList.clear();
}

/* Getters */
std::vector<Player *> const &InteractionManager::getPlayersList(void)
{
    return (_playersList);
}

std::vector<Fire *> const &InteractionManager::getFireList(void)
{
    return (_fireList);
}

/* Setters */
void InteractionManager::setPlayersList(std::vector<Player *> const &newVector)
{
    for (size_t index = 0; _playersList.size() > index; index++)
        _playersList[index]->~Player();
    _playersList.clear();
    for (size_t index = 0; newVector.size() > index; index++)
        _playersList.push_back(newVector[index]);
}

/* Action */

int InteractionManager::hurtPlayer(TYPE_MAP &mapPlayer, int y, int x)
{
    for (size_t index = 0; _playersList.size() > index; index++)
    {
        const int *iTmp = &_playersList[index]->getPos();

        if (iTmp[0] == y && iTmp[1] == x)
        {
            _playersList[index]->takeDamage(BOMB_DAMAGE);
            return (1);
        }
    }
    return (0);
}

/*
Attention le feu à l'emplacement de la bombe est posé avant
pour evité une double explosie=on sur elle même.
*/
void InteractionManager::putFireBis(TYPE_MAP &map, TYPE_MAP &mapPlayer, std::vector<int *> &posFire, std::vector<Bomb *> &listBomb, int index)
{
    for (size_t indexSearch = 0; listBomb.size() > indexSearch; indexSearch++) {
        const int *tmp = &listBomb[indexSearch]->getPos();

        if (tmp[0] == posFire[index][0] && tmp[1] == posFire[index][1]) {
            std::vector<int *> VTmp = listBomb[indexSearch]->activeEffect(map);
            putFire(map, mapPlayer, VTmp, listBomb);
            //for (size_t indexClean = 0; VTmp.size() > indexClean; indexClean++)//crash ici
            //    delete VTmp[indexClean];
            VTmp.clear();
        } 
    }
}

void InteractionManager::putFire(TYPE_MAP &map, TYPE_MAP &mapPlayer, std::vector<int *> &posFire, std::vector<Bomb *> &listBomb)
{
    for (size_t index = 0; posFire.size() > index; index++) {
        if (map[posFire[index][0]][posFire[index][1]] == BOMB) {
            putFireBis(map, mapPlayer, posFire, listBomb, index);
        } else {
            if (map[posFire[index][0]][posFire[index][1]] == BLOCK)
                _fireList.push_back(new Fire (*posFire[index], 1));
            else
                _fireList.push_back(new Fire (*posFire[index], 0));
            hurtPlayer(mapPlayer, posFire[index][0], posFire[index][1]);
            map[posFire[index][0]][posFire[index][1]] = FIRE;
        }
    }
}

void InteractionManager::bombManagement(TYPE_MAP &map, TYPE_MAP &mapPlayer)
{
    for (size_t index = 0; _playersList.size() > index; index++) {
        std::vector<Bomb *> listBomb = _playersList[index]->getBombList();
        for (size_t indexBomb = 0; listBomb.size() > indexBomb; indexBomb++) {
            listBomb[indexBomb]->SetTime(listBomb[indexBomb]->getTime() + 1);
            if (listBomb[indexBomb]->getTime() >= TIMER_BOMB/SPEED_FRAME) {
                std::vector<int *> VTmp = listBomb[indexBomb]->activeEffect(map);
                putFire(map, mapPlayer, VTmp, listBomb);
            }
        }
    }

    /*  Remove bombs which had exploded  */
    for (size_t index = 0; _playersList.size() > index; index++) {
        std::vector<Bomb *> listBomb = _playersList[index]->getBombList();

        for (size_t indexBomb = 0; listBomb.size() > indexBomb; indexBomb++) {
           if (listBomb[indexBomb]->getExploded() == 1) {
               listBomb.erase(listBomb.begin() + indexBomb);
               indexBomb--;
           }
        }
    }
}

void InteractionManager::fireManagement(TYPE_MAP &map)
{
    for (size_t index = 0; _fireList.size() > index; index++) {
        _fireList[index]->setTime(-_fireList[index]->getTime() + 1);
        if (_fireList[index]->getTime() >= TIMER_BOMB/SPEED_FRAME) {
            _fireList[index]->setBurn(1);
            _fireList[index]->putOutFire(map);
            delete _fireList[index];
            _fireList.erase(_fireList.begin() + index);
            index--;
        }
    }

}