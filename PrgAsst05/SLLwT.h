#ifndef PRGASST05_SLLwT_H
#define PRGASST05_SLLwT_H

#include "list.h"
#include <string>
#include <utility>
using std::pair;
using std::string;

/* Same SLLCell seen in class, but the type of the value
   is different
*/
class SLLCell {

public:
  /* Construct a new node with a given value and next node.
   */
  SLLCell(pair<int,string> value, SLLCell* next=nullptr) {
    this->value.first = value.first;
    this->value.second = value.second;
    this->next = next;
  }

  pair<int,string> value;
  SLLCell* next;
};

/* Singly Linked List with Tail pointer.
   Name using an acronym for brevity
 */
class SLLwT : public List<pair<int,string> > {
public:
  SLLwT();
  SLLwT(SLLwT& toCopy);
  ~SLLwT();

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
  SLLwT& operator=(const SLLwT& toAssign);

protected:
  SLLCell* head;
  SLLCell* tail;
  int size;
};

#endif //PRGASST05_SLLwT_H
