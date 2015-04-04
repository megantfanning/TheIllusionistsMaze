#include "Room.h"
using std::endl;
using std::cout;
using std::cin;

/********************* constructor ********************************/
Room::Room(string unlockedLabel){
    //directional ptrs
    label=unlockedLabel;
    type=0;
    west=NULL;
    east=NULL;
    north=NULL;
    south=NULL;
}
/****************************************************************/
void Room ::labelReader(){        
    cout<<"You enter a "<<label<<endl;
    exits();//print out exits
}
/************************************************************
                Exits
Prints all exits available to the user
**************************************************************/
void Room :: exits(){
    cout<<"There are exits to the ";
    if (north != NULL){
        cout<<"north ";
    }
    if (east != NULL){
        cout<<"east ";
    }
    if (south != NULL){
        cout<<"south ";
    }
    if(west != NULL){
        cout<<"west";
    }
    cout<<endl;
}
/**************************************************
            get Room
returns a pointer to the next room
**************************************************/
Room* Room :: getRoom(char direction){
    bool cinBad=false;
    bool roomPtrNull=false;
    do{
        if (direction=='w'||direction=='W'){ 
            if (north ==NULL){
                cout<<"there is no door to the north."<<endl;
                roomPtrNull=true;
            }else{
                cout<<"you walk north"<<endl;
                return north;
            }
        }else if(direction=='d'||direction=='D'){
            if (east ==NULL){
                cout<<"there is no door to the east."<<endl;
                roomPtrNull=true;
            }else{
                cout<<"you walk east"<<endl;
                return east;
            }
        }else if (direction=='s'||direction=='S'){
            if (south ==NULL){
                cout<<"there is no door to the south."<<endl;
                roomPtrNull=true;
            }else{
                cout<<"you walk south"<<endl;
                return south;
            }
        }else if (direction=='a'||direction=='A'){
            if (west ==NULL){
                cout<<"there is no door to the west."<<endl;
                roomPtrNull=true;
            }else{
                cout<<"you walk west"<<endl;
                return west;
            }
        }else{
            cout<<"That's not a valid direction. please use wasd."<<endl;
            roomPtrNull=true;
        }
        if(roomPtrNull){
            cin.clear();
            cin.ignore(10000,'\n');
            cout<<"which direction do you go?"<<endl;
            cin>>direction;
            cinBad=true;
        }
    }while(cinBad);
    cout<<"Error in input to direction function, player moves north"<<endl;
    return north;
}

/********************************************
                 Item Announcer
tells user what items are in room
***********************************************/
void Room :: itemAnnouncer(){
    if(objectsInRm.empty()){
        cout<<"The room is empty"<<endl;
    }else{
        cout<<"Objects in room: "<<endl;
 
        for (unsigned int i=0; i< objectsInRm.size(); i++){
            cout<<i+1<<") "<<objectsInRm.at(i).label<<" ";
        }
        cout<<endl;
    }
}

bool Room :: rmEmpty(){
    return objectsInRm.empty();
} 
/*****************************************************************
                    Item Getter
returns an item to the user and deletes it from the vector
*******************************************************************/
Item Room :: itemGetter(int choice){
    Item object = objectsInRm.at(choice);
    objectsInRm.erase (objectsInRm.begin()+choice);//remove item from room
    return object;    
}


