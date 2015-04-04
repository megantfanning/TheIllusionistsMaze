#include "Carosel.h"

using std::cout;
using std::cin;
using std::endl;

Carosel :: Carosel():Room("room. A carousel with horses, zebras, and dolphins spins in front of you"){
    type=2;
};

Room* Carosel :: getRoom(char direction,int spins){
    if(spins%4 == 0){
        Room* tempn;
        tempn=north;

        north=east;
        east=south;
        south=west;
        west=tempn;
        
    } else if (spins%4 ==1){
        Room* tempn;
        tempn=north;
        Room* tempE;
        tempE=east;

        north=south;
        east=west;
        south=tempn;
        west=tempE;
    }else if(spins%4 == 2){
        Room* tempN;
        tempN=north;
        Room* tempE;
        tempE=east;

        north=west;
        east=south;
        south=tempE;
        west=tempN;
    }else if(spins%4 ==3){
        //orginal orientation
    }else{
        cout<<"error in the carosel spin function, spins input invalid"<<endl;
    }
    return Room::getRoom(direction);

}
