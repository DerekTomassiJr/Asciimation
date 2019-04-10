#include <stdexcept>
#include "arrayPairList.h"
using namespace std;

ArrayPairList::ArrayPairList() {
    this->theArray = new pair<int,string>[10];
    this->size = 0;
    this->capacity = 10;
}

ArrayPairList::ArrayPairList(ArrayPairList& toCopy) {
    this->size = toCopy.size;
    this->capacity = toCopy.capacity;
    this->theArray = new pair<int,string>[this->capacity];
    for (int i=0; i<this->size; i++) {
        this->theArray[i] = toCopy.theArray[i];
    }
}

ArrayPairList::~ArrayPairList() {
    delete[] this->theArray;
}

int ArrayPairList::getSize() {
    return this->size;
}

bool ArrayPairList::isEmpty() {
    return this->size == 0;
}

pair<int,string> ArrayPairList::peekHead() {
    if (this->size == 0) {
        throw runtime_error("ArrayPairList::peekHead, list is empty");
    } else {
        return this->theArray[0];
    }
}

pair<int,string> ArrayPairList::peekTail() {
    if (this->size == 0) {
        throw runtime_error("ArrayPairList::peekHead, list is empty");
    } else {
        return this->theArray[this->size - 1];
    }
}

pair<int,string>& ArrayPairList::at(int i) {
    if (i < this->size && i >= 0) {
        return this->theArray[i];
    } else {
        throw runtime_error("ArrayPairList::at, is not a valid index.");
    }
}

pair<int,string>& ArrayPairList::operator[](int i) {
    return this->theArray[i];
}

void ArrayPairList::insertAtHead(pair<int,string> value) {
    if (this->size == this->capacity) {
        this->expandCapacity();
    }
    for (int i=this->size-1; i>=0; i--) {
        this->theArray[i+1] = this->theArray[i];
    }
    this->theArray[0] = value;
    this->size++;
}

void ArrayPairList::insertAtTail(pair<int,string> value) {
    if (this->size == this->capacity) {
        this->expandCapacity();
    }
    this->theArray[size] = value;
    this->size++;
}

void ArrayPairList::removeHead() {
    if (this->size == 0) {
        throw runtime_error("ArrayPairList::removeHead, list is empty");
    }
    for (int i=1; i<this->size; i++) {
        this->theArray[i-1] = this->theArray[i];
    }
    this->size--;
}

void ArrayPairList::removeTail() {
    if (this->size == 0) {
        throw runtime_error("ArrayPairList::removeTail, list is empty");
    }
    this->size--;
}

void ArrayPairList::expandCapacity() {
    int newCapacity = this->capacity*2;
    pair<int,string>* newArray = new pair<int,string>[newCapacity];
    for (int i=0; i<this->size; i++) {
        newArray[i] = this->theArray[i];
    }
    delete[] this->theArray; // reclaim old memory
    this->theArray = newArray; // make class variable point to new array
    this->capacity = newCapacity;
}

ArrayPairList& ArrayPairList::operator=(const ArrayPairList& toAssign) {
    if (this != &toAssign) {
        delete[] this->theArray;

        this->size = toAssign.size;
        this->capacity = toAssign.capacity;
        this->theArray = new pair<int,string>[this->capacity];
        for (int i=0; i<this->size; i++) {
            this->theArray[i] = toAssign.theArray[i];
        }

    }
    return *this;
}
