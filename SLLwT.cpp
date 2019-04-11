#include "SLLwT.h"
#include <utility>
#include <string>
#include <stdexcept>
using namespace std;



/* TODO: replace the thrown runtime_error by the appropriate code */

SLLwT::SLLwT() {
    this->size = 0;
    this->head = nullptr;
    this->tail = nullptr;
}

SLLwT::SLLwT(SLLwT& toCopy) {
    if (toCopy.size == 0) {
    this->size = 0;
    this->head = nullptr;
  }
  else {
    this->size = toCopy.size;
    // insert the first node
    SLLCell* cursor1 = toCopy.head;
    this->head = new SLLCell(cursor1->value);
    // cursor1 is one ahead of cursor2
    cursor1 = cursor1->next;
    SLLCell* cursor2 = this->head;
    while (cursor1 != nullptr) {
      cursor2->next = new SLLCell(cursor1->value);
      cursor1 = cursor1->next;
      cursor2 = cursor2->next;
    }

    this->tail = new SLLCell(cursor2->value);
  }
}

SLLwT::~SLLwT() {
    while (this->size >0) {
      this->removeHead();
    }
}

/* TODO: Write the other methods for SLLwT */
int SLLwT::getSize() {
    return this->size;
}

bool SLLwT::isEmpty() {
    return this->size == 0;
}

pair<int, string> SLLwT::peekHead() {
    if (this->size == 0) {
    throw runtime_error("SLLwT::peekHead, the list is empty");
  }
  return this->head->value;
}

pair<int, string> SLLwT::peekTail() {
    if (this->size == 0) {
        throw runtime_error("SLLwT::peekTail, list is empty");
    } else {
        return this->tail->value;
    }
}

pair<int,string>& SLLwT::at(int i) {
    if (i >= this->size || i < 0) {
    throw runtime_error("SLLwT::at, index out of bounds");
  }
  // find the node at index ind
  SLLCell* cursor = this->head;
  for (int j=0; j<i; j++) {
    //move forward once
    cursor = cursor->next;
  }
  // cursor is at the right place
  return cursor->value;
}

pair<int, string>& SLLwT::operator[](int i) {
    // find the node at index ind
  SLLCell* cursor = this->head;
  for (int j=0; j<i; j++) {
    //move forward once
    cursor = cursor->next;
  }
  // cursor is at the right place
  return cursor->value;
}

void SLLwT::insertAtHead(pair<int, string> value) {
    // create a new link
  SLLCell* newCell = new SLLCell(value, this->head);
  // restore invariants
  this->size++;
  this->head = newCell;
}

void SLLwT::insertAtTail(pair<int, string> value) {
    if (this->size != 0) {
    // create new link
    SLLCell* newCell = new SLLCell(value);
    // find the last node
    SLLCell* cursor = this->head;
    for (int i=0; i<this->size-1; i++) {
      //move forward once
      cursor = cursor->next;
    }
    //cursor now points to last node
    // update the next of that last node
    cursor->next = newCell;
    // restore invariants
    this->size++;
    this->tail = newCell;
  } else {
    // if adding the first link, it's the same as insertAtHead
    this->insertAtHead(value);
  }
}

void SLLwT::removeHead() {
    if (this->size == 0) {
    throw runtime_error("SLLwT::removeHead, the list is empty");
  }
  SLLCell* oldHead = this->head;
  this->head = this->head->next;
  delete oldHead;
  this->size--;
}

void SLLwT::removeTail() {
    if (this->size == 0) {
    throw runtime_error("SLLwT::removeTail, the list is empty");
  }
  else if (this->size > 1) {
    // find the second to last node
    SLLCell* cursor = this->head;
    for (int i=0; i<this->size-2; i++) {
      //move forward once
      cursor = cursor->next;
    }
    // delete last node
    delete cursor->next;
    // restore invariants
    cursor->next = nullptr;
    this->size--;
  }
  else {
    // this->size == 1
    this->removeHead();
  }
}

SLLwT& SLLwT::operator=(const SLLwT& toAssign) {
    SLLwT* newList = new SLLwT();

    if (toAssign.size == 0) {
    newList->size = 0;
    newList->head = nullptr;
  }
  else {
    newList->size = toAssign.size;
    // insert the first node
    SLLCell* cursor1 = toAssign.head;
    newList->head = new SLLCell(cursor1->value);
    // cursor1 is one ahead of cursor2
    cursor1 = cursor1->next;
    SLLCell* cursor2 = this->head;
    while (cursor1 != nullptr) {
      cursor2->next = new SLLCell(cursor1->value);
      cursor1 = cursor1->next;
      cursor2 = cursor2->next;
    }

    newList->tail = new SLLCell(cursor2->value);
  }

    return *newList;
}
