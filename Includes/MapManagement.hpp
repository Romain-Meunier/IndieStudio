/*
** EPITECH PROJECT, 2021
** B-YEP-400-MAR-4-1-indiestudio-mathys.le-juez [WSL: Ubuntu-20.04]
** File description:
** MapManagement
*/

#ifndef MAPMANAGEMENT_HPP_
#define MAPMANAGEMENT_HPP_
#include "Interfaces/IMapManagement.hpp"

class MapManagement : public IMapManagement
{
    public:
        MapManagement(int nbLine = 10);
        ~MapManagement();
        virtual std::string lineConstructorItem(int index, int nbLine);
        virtual std::string lineConstructorPlayer(int nbLine);
        virtual void blockGenerationOne(int nbLine);
        virtual void blockGenerationTwo(int nbLine);
        std::vector<std::string> _mapItems;
        std::vector<std::string> _mapPlayer;
    protected:
    private:
};

#endif /* !MAPMANAGEMENT_HPP_ */