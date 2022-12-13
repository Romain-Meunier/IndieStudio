/*
** EPITECH PROJECT, 2021
** B-YEP-400-MAR-4-1-indiestudio-mathys.le-juez [WSL: Ubuntu-20.04]
** File description:
** MapManagement
*/

#include "../Includes/MapManagement.hpp"

MapManagement::MapManagement(int nbLine)
{
    srand(time(NULL));
    nbLine = nbLine + 1;
    for (int index = 0; nbLine > index; index++)
        _mapItems.push_back(lineConstructorItem(index, nbLine));
    for (int index = 0; nbLine > index; index++)
        _mapPlayer.push_back(lineConstructorPlayer(nbLine));
    if ((rand() % 2 + 1) == 1)
        blockGenerationOne(nbLine);
    else
        blockGenerationTwo(nbLine);
}

MapManagement::~MapManagement()
{
}

std::string MapManagement::lineConstructorItem(int index, int nbLine)
{
    std::string line;

    if (index == 0 || index == (nbLine - 1))
    {
        for (int indexFill = 0; nbLine > indexFill; indexFill++)
            line.push_back(WALL);
    }
    else
    {
        if ((index % 2) != 0) {
            for (int indexFill = 0; nbLine > indexFill; indexFill++)
            {
                if (indexFill == 0 || indexFill == (nbLine - 1))
                    line.push_back(WALL);    
                else
                    line.push_back(SPC);
            }
        }else {
            for (int indexFill = 0; nbLine > indexFill; indexFill++)
            {
                if (indexFill == 0 || indexFill == (nbLine - 1))
                    line.push_back(WALL);    
                else if ((indexFill % 2) == 0 && index != 1 && index != (nbLine - 2))
                    line.push_back(WALL);
                else
                    line.push_back(SPC);
            }
        }
    }
    return (line);
}

std::string MapManagement::lineConstructorPlayer(int nbLine)
{
    std::string line;

    for (int indexFill = 0; nbLine > indexFill; indexFill++)
        line.push_back(SPC);
    return (line);
}

void MapManagement::blockGenerationOne(int nbLine)
{
    for (int indexLine = 0; nbLine > indexLine; indexLine++) {
        int begin = (indexLine == 1 || indexLine == (nbLine - 2)) ? 3 : 1;
        int limit = (indexLine == 1 || indexLine == (nbLine - 2)) ? (nbLine - 3) : nbLine;
        begin = (indexLine == 2 || indexLine == (nbLine - 3)) ? 2 : begin;
        limit = (indexLine == 2 || indexLine == (nbLine - 3)) ? (nbLine - 2) : limit;
        for (int indexChar = begin; limit > indexChar; indexChar++) {
            if (_mapItems[indexLine][indexChar] == SPC)
                _mapItems[indexLine][indexChar] = BLOCK;
        }
    }
}

void MapManagement::blockGenerationTwo(int nbLine)
{
    for (int indexLine = 0; nbLine > indexLine; indexLine++) {
        int begin = (indexLine == 1 || indexLine == (nbLine - 2)) ? 3 : 1;
        int limit = (indexLine == 1 || indexLine == (nbLine - 2)) ? (nbLine - 3) : nbLine;
        begin = (indexLine == 2 || indexLine == (nbLine - 3)) ? 2 : begin;
        limit = (indexLine == 2 || indexLine == (nbLine - 3)) ? (nbLine - 2) : limit;
        for (int indexChar = begin; limit > indexChar; indexChar++) {
            if (_mapItems[indexLine][indexChar] == SPC)
                _mapItems[indexLine][indexChar] = BLOCK;
        }
    }
    for (int indexLine = 0; nbLine > indexLine; indexLine++) {
        for (int indexChar = 0; nbLine > indexChar; indexChar++) {
            if ((rand() % 5 + 1) == 1 && _mapItems[indexLine][indexChar] == BLOCK)
                _mapItems[indexLine][indexChar] = SPC;
        }
    }
}