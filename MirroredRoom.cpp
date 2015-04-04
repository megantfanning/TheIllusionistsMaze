#include "MirroredRoom.h"

/***************************************************************
                mirrored/hidden room subclass
hides labels so user can't view them
******************************************************************/
MirroredRoom::MirroredRoom():Room("a mirrored room, the mirrors make impossible to spot the exits"){};

void MirroredRoom :: labelReader(){        
    std::cout<<"You enter a "<<label<<std::endl;
}

