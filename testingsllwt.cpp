#include <iostream>
#include "SLLwT.h"
using namespace std;

int main() {
    SLLwT* newList = new SLLwT();

    for (int i = 0; i < 10; i++) {
        pair<int, string> thePair(i + 1, "a");
        newList->insertAtTail(thePair);
    }

    cout << "Size: " << newList->getSize() << endl;
    cout << "List 1 Empty: " << newList->isEmpty() << endl;

    SLLwT* list2 = new SLLwT();

    cout << "List 2 Empty: " << list2->isEmpty() << endl;

    list2 = newList;

    cout << "List 1: ";
    for (int i = 0; i < newList->getSize(); i++) {
        pair<int, string> itsAPair = newList->at(i);
        cout << itsAPair.first;
        cout << itsAPair.second;
    }
    cout << endl;

    cout << "List 2: ";
    for (int i = 0; i < list2->getSize(); i++) {
        pair<int, string> itsAPair = list2->at(i);
        cout << itsAPair.first;
        cout << itsAPair.second;
    }
    cout << endl;

    pair<int, string> newListPair(200, "e");
    newList->insertAtHead(newListPair);

    pair<int, string> list2Pair(300, "d");
    list2->insertAtTail(list2Pair);

    cout << "List 1: ";
    for (int i = 0; i < newList->getSize(); i++) {
        pair<int, string> itsAPair = newList->at(i);
        cout << itsAPair.first;
        cout << itsAPair.second;
    }
    cout << endl;

    cout << "List 2: ";
    for (int i = 0; i < list2->getSize(); i++) {
        pair<int, string> itsAPair = list2->at(i);
        cout << itsAPair.first;
        cout << itsAPair.second;
    }
    cout << endl;

    SLLwT* list3 = new SLLwT(*list2);

    cout << "List 3: ";
    for (int i = 0; i < list3->getSize(); i++) {
        pair<int, string> itsAPair = list3->at(i);
        cout << itsAPair.first;
        cout << itsAPair.second;
    }
    cout << endl;

    delete newList;
    delete list2;
    delete list3;

    return 0;
}
