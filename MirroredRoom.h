#ifndef MIRROR_H
#define MIRROR_H
#include "Item.h"
#include "Room.h"
#include <vector>
#include <queue>
#include <iostream>

class MirroredRoom : public Room{
    public:
        MirroredRoom();
        void labelReader();
};

#endif
