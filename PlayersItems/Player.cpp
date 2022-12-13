/*
** EPITECH PROJECT, 2021
** B-YEP-400-MAR-4-1-indiestudio-mathys.le-juez [WSL: Ubuntu-20.04]
** File description:
** Player
*/
#include "../Includes/Player.hpp"

Player::Player(const std::string &name, const int &pos, TYPE_MAP &map_player) : _name(name)
{
    const int *posTmp = &pos;

    _pos[0] = posTmp[0];
    _pos[1] = posTmp[1];
    map_player[_pos[0]][_pos[1]] = PLAY;
    _speed = 1;
    _bombNb = 1;
    _bombRange = 1;
    _wallPassAct = 0;
    _lifeMax = 3;
    _lifeAct = 3;

    std::cout << "Creation of a player \"" << _name << "\"" << std::endl;
}

Player::~Player()
{
    for (size_t index = 0; _bombList.size() > index; index++)
        delete _bombList[index];
    _bombList.empty();

    std::cout << "Destruction of a player \"" << _name << "\"" << std::endl;
}

/*      ------>   Getters    <------        */
const std::string &Player::getName(void) const
{
    return (_name);
}

int Player::getLifeAct(void) const
{
    return (_lifeAct);
}

int Player::getLifeMax(void) const
{
    return (_lifeMax);
}

int Player::getSpeed(void) const
{
    return (_speed);
}

int Player::getBombNb(void) const
{
    return (_bombNb);
}

int Player::getBombRange(void) const
{
    return (_bombRange);
}

const std::vector<Bomb *> &Player::getBombList(void) const
{
    return (_bombList);
}

const int &Player::getPos(void) const
{
    return (_pos[0]);
}

/*      ------>   Setters    <------        */
void Player::setLifeAct(const int newNb)
{
    _lifeAct = newNb;
}

void Player::setLifeMax(const int newNb)
{
    _lifeMax = newNb;
}

void Player::setSpeed(const int newSpeed)
{
    _speed = newSpeed;
}

void Player::setBombNb(const int newNb)
{
    _bombNb = newNb;
}

void Player::setBombRange(const int newNb)
{
    _bombRange = newNb;
}

/*      ------>   Movements    <------        */
int Player::checkCase(int y, int x, TYPE_MAP &map, TYPE_MAP &mapPlayer)
{
    /*if (_wallPassAct == 1) {
        verifier si on a toujours le bonus
    }*/
    if (map[y][x] != WALL && map[y][x] != BOMB && mapPlayer[y][x] != PLAY) {
        if (map[y][x] == BLOCK && _wallPassAct == 0)
            return (1);
        switch (map[y][x])
        {
            case FIRE:
                takeDamage(BOMB_DAMAGE);
                break;
            case BOMBUP:
                _bombNb = _bombNb + 1;
                map[y][x] = SPC;
                break;
            case FIREUP:
                _bombRange = _bombRange + 1;
                map[y][x] = SPC;
                break;
            case SPEEDUP:
                _speed = _speed + 1;
                map[y][x] = SPC;
                break;
            case WALLPASS:
                wallPassActivation();
                map[y][x] = SPC;
                break;
        }
        return (0);
    } else {
        return (1);
    }
}

int Player::moveLeft(TYPE_MAP &map, TYPE_MAP &map_player)
{
    if (checkCase(_pos[0], _pos[1] - 1, map, map_player) == 1)
        return (1);
    else {
        map_player[_pos[0]][_pos[1]] = SPC;
        _pos[1] = _pos[1] - 1;
        map_player[_pos[0]][_pos[1]] = PLAY;
        return (0);
    }
}

int Player::moveRight(TYPE_MAP &map, TYPE_MAP &map_player)
{
    if (checkCase(_pos[0], _pos[1] + 1, map, map_player) == 1)
        return (1);
    else {
        map_player[_pos[0]][_pos[1]] = SPC;
        _pos[1] = _pos[1] + 1;
        map_player[_pos[0]][_pos[1]] = PLAY;
        return (0);
    }
}

int Player::moveUp(TYPE_MAP &map, TYPE_MAP &map_player)
{
    if (checkCase(_pos[0] - 1, _pos[1], map, map_player) == 1)
        return (1);
    else {
        map_player[_pos[0]][_pos[1]] = SPC;
        _pos[0] = _pos[0] - 1;
        map_player[_pos[0]][_pos[1]] = PLAY;
        return (0);
    }
}

int Player::moveDown(TYPE_MAP &map, TYPE_MAP &map_player)
{
    if (checkCase(_pos[0] + 1, _pos[1], map, map_player) == 1)
        return (1);
    else {
        map_player[_pos[0]][_pos[1]] = SPC;
        _pos[0] = _pos[0] + 1;
        map_player[_pos[0]][_pos[1]] = PLAY;
        return (0);
    }
}

/*      ------>   Actions    <------        */
void Player::putBomb(TYPE_MAP &map)
{
    _bombList.push_back(new Bomb (_pos[0], _bombRange));
    map[_pos[0]][_pos[1]] = BOMB;
}

int Player::takeDamage(int nbDamage)
{
    _lifeAct = _lifeAct - nbDamage;
    if (_lifeAct > 0)
        return (1);
    else
        return (0);
}

void Player::wallPassActivation(void)
{
    _wallPassAct = 1;
    //lancer le chronometre
}