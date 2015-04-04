#ifndef CAROSEL_H
#define CAROSEL_H
#include "Item.h"
#include "Room.h"
#include <vector>
#include <iostream>

class Carosel : public Room{
    public:
        Carosel();
        Room* getRoom(char,int);
};

#endif

