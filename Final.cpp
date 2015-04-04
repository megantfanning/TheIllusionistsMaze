#include "Final.h"

using std::cout;
using std::endl;
using std::cin;

int main(){
    //make vector for maze
    std::vector < Room* > maze;
    
    //create variables
    char direction;
    Inventory bag; //create bag
    Room* currentRm;
    currentRm = makeMaze(maze);
    bool win=false;
    bool fail=false;
    int min=0;//counts the number of rooms entered for timing
    
    //introduction
    cout<<"~**~~~~*******~~~~**~"<<endl;
    cout<<"You are an aging showgirl, and you've had just about enough of these magicians and illusionists. You know how to stack a deck and get cut in half with the best of them - it's time they let you in on their secrets! The Illusionist you've been working for has told you to meet him at the warehouse he practices at, and says he'll teach you magic IF you can successfully identify magic and illusion."<<endl<<endl;
    cout<<"To win, you must collect 3 props for the show tonight in 30 minutes. The props are for: a bullet catch trick, an underwater escape, and sawing a woman (you) in half."<<endl<<endl;;
    cout<<"Upon entering his warehouse you find yourself in a hall of mirrors..."<<endl<<endl;
    cout<<"~**~~~~*******~~~~**~"<<endl;
    cout<<endl;
    cout<<"Your possessions are a compass, your purse and a watch."<<endl;
    cout<<"You can walk north:w, east:d, south:s, west:a "<<endl;

    //while the player is in the maze prompt for direction
    while (!win && !fail){
        min++;
        currentRm->labelReader();
        //if the room has a locked door prompt the user to try to open it
        if (currentRm->type == 1){
            char confirm;
            cout<<"There is a locked door to the north!"<<endl;
            cout<<"Do you want to try to unlock the door? y/n"<<endl;
            cin>>confirm;
            if (confirm== 'y' || confirm=='Y'){
                ((LockedRoom*) currentRm)->unlockRoom(bag.useKey(),maze);
            }
        }

        if(!currentRm->rmEmpty()){
            //print items in room and ask user if they want to pick them up
            bag.itemManager(currentRm);
            cout<<"current contents of purse "<<endl;
            bag.printBag();
        }else {
            cout<<"The room has no items in it"<<endl;
        }

        if(min>30){
            cout<<"You ran out of time, you have failed"<<endl;
            fail=true;//player didn't win but program should exit
        }
        std::cout<<"it's been "<<min<<" minutes since you entered the warehouse"<<endl;

        //direction
        cout<<"which direction do you go?"<<endl;
        cin>>direction;
        
        //if room is a carosel use the carosel getroom function
        if(currentRm->type ==2){
            currentRm=((Carosel*) currentRm)->getRoom(direction, min);
        }else{
            currentRm=currentRm->getRoom(direction);
        }
        //checks if user has reached exit with all items
        if(currentRm->label == "exit"){
            cout<<"Present the Items needed for the show tonight"<<endl;
            int j=0;
            for (int i=0; i<3; i++){
                if(bag.useKey()== 111){
                    j++;
                }
            }
            if(j==3){
                win=true;
            }
        }
    }
    if(win){
        cout<<"you emerge from the tunnel, are back stage...and the curtains begin to rise"<<endl;
        cout<<"You have sucessfully passed the magician's test, congratuations!"<<endl;
    }
    if(fail){
        cout<<"Better luck next time!"<<endl;
    }

    //delete maze
    for(unsigned int i=0;i<maze.size();i++){
        delete maze.at(i);
    }

    return 0;
}
/********************* Make rooms***************************************
* this function adds the rooms dynamically
* then it links the rooms after creation.
* rooms numbered in columns from top to bottom column 1 has rooms 0 through 1
* items required to win have a key of 111 handcuff keys, hacksaw and gun
********************************************************************/
Room* makeMaze(std::vector <Room*>& maze){   
    //column 1
    maze.push_back( new Room("there is a large water tank that the magician must escape from ")); //links to 1
    maze.at(0)->objectsInRm.push_back(Item("handcuff keys",111));//make item
    maze.push_back( new LockedRoom("room with tigers, better be careful!", "you throw the bunny at the tiger and can enter the room to the north!",0,123));
    maze.at(0)->objectsInRm.push_back(Item("skeleton key",321));

    //column 2
    maze.push_back( new Room("exit")); //2 EXIT
    maze.push_back(new LockedRoom("stage, complete with red curtains and a trap door","you unlock the trap door",2,321));//3
    maze.at(3)->objectsInRm.push_back(Item("a flimsey lookin hacksaw",111));

    maze.push_back(new Carosel());//4
    maze.push_back( new MirroredRoom());//5
    maze.push_back( new MirroredRoom());//6 ENTRANCE

    //column 3
    maze.push_back( new Room("scaffolded room")); //7 links to 8
    maze.at(7)->objectsInRm.push_back(Item("loaded gun",111));
    maze.at(7)->objectsInRm.push_back(Item("perfume",522));
    maze.at(7)->objectsInRm.push_back(Item("deck of cards",533));

    maze.push_back(new Room("prop room, there are dresses, suits, and dozens of boxes"));//8
    maze.at(8)->objectsInRm.push_back(Item("bunny",123));
    maze.at(8)->objectsInRm.push_back(Item("1 fake leg",511));
    maze.at(8)->objectsInRm.push_back(Item("7 silk scarves",521));

    maze.push_back( new MirroredRoom());//9

    //Link the rooms together column
    maze.at(0)-> south = maze.at(1);        
    //maze.at(1)-> north = maze.at(0); Locked
    maze.at(1)-> east = maze.at(4);
    //column 2
    maze.at(2)-> south = maze.at(3);
    //maze.at(3)-> north = maze.at(2); locked
    maze.at(3)-> south = maze.at(4);
    maze.at(4)-> north = maze.at(3);
    maze.at(4)-> east = maze.at(8);
    maze.at(4)-> south = maze.at(5);
    maze.at(4)-> west = maze.at(1);
    maze.at(5)-> south = maze.at(6);
    maze.at(5)-> north = maze.at(4);
    maze.at(5)-> east = maze.at(9);
    maze.at(6)-> north = maze.at(5);
    //column 3
    maze.at(7)-> south = maze.at(8);        
    maze.at(8)-> north = maze.at(7);
    maze.at(8)-> west = maze.at(4);
    maze.at(8)-> south = maze.at(9);
    maze.at(9)-> west = maze.at(5);
    maze.at(9)-> north = maze.at(8);


    Room* entrance = maze.at(6);
    return entrance;
}


