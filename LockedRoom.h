#include "Room.h"
#include "Item.h"

class LockedRoom: public Room{
        int key;//id of item that unlocks the door
        int rmToUnlock;//coordinate of linked room in the maze
        
    public:
        LockedRoom(string,string,int, int);
        bool lockChecker(int);
        string unlockedLabel;
        void unlockRoom(int,std::vector<Room*>);
};

