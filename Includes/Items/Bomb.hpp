/*
** EPITECH PROJECT, 2021
** B-YEP-400-MAR-4-1-indiestudio-mathys.le-juez [WSL: Ubuntu-20.04]
** File description:
** Bomb
*/

#ifndef BOMB_HPP_
#define BOMB_HPP_
#include "../Item.hpp"

class Bomb : public Item
{
    public:
        Bomb(const int &pos, int range);
        ~Bomb();
        /* Getter */
        int getRange(void) const;
        int getExploded(void);
        int getTime(void);
        /* Setter */
        void SetTime(int newValue);
        /* Actions */
        int checkFireArea(int y, int x, std::vector<std::string> &map, std::vector<int *> &posFire);
        void putFireRight(std::vector<std::string> &map, std::vector<int *> &posFire);
        void putFireLeft(std::vector<std::string> &map, std::vector<int *> &posFire);
        void putFireUp(std::vector<std::string> &map, std::vector<int *> &posFire);
        void putFireDown(std::vector<std::string> &map, std::vector<int *> &posFire);
        std::vector<int *> activeEffect(std::vector<std::string> &map);
    private:
    const int _range; // Range of explosion
    int _exploded; // 0 if it don't exploded, 1 if it i
    int _time; //chrono explosion
};

#endif /* !BOMB_HPP_ */
