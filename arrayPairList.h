#ifndef PRGASST05_ARRAYPAIRLIST_H
#define PRGASST05_ARRAYPAIRLIST_H

#include <utility>
#include <string>
#include "list.h"
using std::pair;
using std::string;

class ArrayPairList : public List<pair<int,string> > {
protected:
    pair<int,string>* theArray;
    int size;
    int capacity;

    void expandCapacity();

public:
    ArrayPairList();
    ArrayPairList(ArrayPairList& toCopy);
    ~ArrayPairList();

    int getSize();
    bool isEmpty();
    pair<int,string> peekHead();
    pair<int,string> peekTail();
    pair<int,string>& at(int i);
    pair<int,string>& operator[](int i);
    void insertAtHead(pair<int,string> value);
    void insertAtTail(pair<int,string> value);
    void removeHead();
    void removeTail();
    ArrayPairList& operator=(const ArrayPairList& toAssign);
};

#endif //PRGASST05_ARRAYPAIRLIST_H
