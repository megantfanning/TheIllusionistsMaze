#include "LockedRoom.h"


/*********************************************************************
            locked room subclass
has a bool for locked/unlocked and a item which opens it
*********************************************************************/
LockedRoom ::LockedRoom(string label,string aUnlockedLabel, int room, int aKey):Room(label) {
    unlockedLabel=aUnlockedLabel;
    rmToUnlock=room;
    key=aKey;
    type=1;
}

bool LockedRoom ::lockChecker(int itemKey){
    return (itemKey==key);
}
/********************************************************************
            unlocks room
checks if users item key matches the room key  
*******************************************************************/
void LockedRoom :: unlockRoom(int key, std::vector <Room*> maze){
    if(lockChecker(key)){
        std::cout<<unlockedLabel<<std::endl;
        // need to remove key from bag
        north = maze.at(rmToUnlock);//set link to the lockedroom
    }else{
        std::cout<<"That's not the key!"<<std::endl;
    }
}


