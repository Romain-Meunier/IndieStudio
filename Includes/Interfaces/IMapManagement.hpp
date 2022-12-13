/*
** EPITECH PROJECT, 2021
** B-YEP-400-MAR-4-1-indiestudio-mathys.le-juez [WSL: Ubuntu-20.04]
** File description:
** IMapManagement
*/
#ifndef IMAPMANAGEMENT_HPP_
#define IMAPMANAGEMENT_HPP_
#include "../proto.hpp"

class IMapManagement
{
    public:
        ~IMapManagement() = default;
        virtual std::string lineConstructorItem(int index, int nbLine) = 0;
        virtual std::string lineConstructorPlayer(int nbLine) = 0;
        virtual void blockGenerationOne(int nbLine) = 0;
        virtual void blockGenerationTwo(int nbLine) = 0;
    protected:
    private:
};

#endif /*IMAPMANAGEMENT_HPP_*/