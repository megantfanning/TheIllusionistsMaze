#include "Inventory.h"
using std::cout;
using std::endl;
using std::cin;


/********************************************************************
            Bag Manager
*********************************************************************/
void Inventory :: itemManager(Room* currentRm){

    char confirmation;
    char confirm;
    int itemNum=-1;

    do{ 
        currentRm->itemAnnouncer();
        cout<<"Would you like to pick up an item in the room? y/n"<<endl;
        cin>>confirmation;
        if (confirmation == 'y' || confirmation == 'Y'){  
            if (bagFull()){
                cout<<"would you like to remove an item from your bag? y/n"<<endl;
                cin>>confirm;
        
                if (confirm == 'y' || confirmation == 'Y'){
                    printBag();
                    cout<<"what is the number of the item you want?"<<endl;
                    cin>>itemNum;
                    int numObjects = bag.size();
                    if (itemNum < 1 || itemNum > numObjects) {
                        cout<<"That's not a valid item!"<<endl;
                    } else {
                        emptyBag(currentRm,itemNum);
                    }
                }
                printBag();//print bag again so they can see it.
            } else {
                cout<<"what item would you like to place in your bag (input the number of the item)"<<endl;
                cin>>itemNum;
                int numObjects = currentRm->objectsInRm.size();
                if (itemNum < 1 || itemNum > numObjects) {
                    cout<<"That's not a valid item!"<<endl;
                } else {
                    bag.push_back(currentRm->itemGetter(itemNum-1));
                }
            }
        }
        cin.clear();
        cin.ignore(1000,'\n');
    } while(confirmation == 'y' || confirmation == 'Y'); 
}
/**************************************
Bag full checker
**********************************/
bool Inventory :: bagFull(){        
    if(bag.size()>4){
        cout<<"Your bag is full"<<endl;
        return true;
    }else{
        return false;
    }
}
/*********************************
        print bag 
print out contents of the bag
**********************************/
void Inventory :: printBag(){
    if(bag.empty()){
        cout<<"Your purse is empty"<<endl;
    }else{
        cout<<"Items in purse: "<<endl;
        
        for(unsigned int i=0; i<bag.size(); i++){
            cout<<i+1<<") "<<bag.at(i).label<<" ";
        }
        cout<<endl;
    }
}
/************************************************
        Empty Bag
takes  a pointer to the current room 
and an integer which is the chosen item
******************************************************/
void Inventory :: emptyBag(Room* currentRm,int choice){
    currentRm->objectsInRm.push_back(bag.at(choice-1));//add item to room
    bag.erase (bag.begin()+choice-1);//remove item from bag
}

/****************************************************
        return item key
****************************************************/
int Inventory :: useKey(){
    if(bag.empty()){
        cout<<"Your purse is empty"<<endl;
        return 0;
    }else{
        unsigned int itemNum;
        cout<<"Items in purse: "<<endl;
        for(unsigned int i=0; i<bag.size(); i++){
            cout<<i+1<<") "<<bag.at(i).label<<" ";
        }
        cout<<endl;
        cout<<"what is the number of the item you want?"<<endl;
        cin>>itemNum;
        if(itemNum <= bag.size()){
            Item key=bag.at(itemNum-1);
            return key.key;
        }else{
            cout<<"you don't have that many items"<<endl;
            return 0;
        }
    }
}

