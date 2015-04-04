#ifndef BAG_H
#define BAG_H

#include "Item.h"
#include "Room.h"
#include <iostream>

class Inventory{
    void emptyBag(Room*,int);
    bool bagFull();

    public:
        void itemManager(Room*);
        std::vector <Item> bag;
        int useKey();
        void printBag();
};


#endif
