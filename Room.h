#ifndef ROOM_H
#define ROOM_H
#include "Item.h"

#include <vector>
#include <queue>
#include <iostream>
using std::string;

class Room{
    //directional ptrs
    public:
        Room *west;
        Room *east;
        Room *north;
        Room *south;
        int type;
        //constructor
        Room(string);
        string label;
        virtual Room* getRoom(char);
        std::vector <Item> objectsInRm;
        void itemAnnouncer();
        bool rmEmpty();
        Item itemGetter(int);
        virtual void labelReader();
        void exits();
};

#endif
