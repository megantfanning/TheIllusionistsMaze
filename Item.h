#ifndef ITEM_H
#define ITEM_H

#include <string>
using std::string;

class Item{
    public:
        string label;
        int key;
        Item(string,int);
};

#endif
