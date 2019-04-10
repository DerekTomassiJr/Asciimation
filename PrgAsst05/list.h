#ifndef ADTS_LIST_H
#define ADTS_LIST_H


/**
 * List is an abstract (a.k.a. pure virtual) class specifying the interface
 * for a list of an arbitrary data type.
 */
/**
 * IMPORTANT: this is not the list ADT. It is a C++ implementation
 *            of the idea of a list ADT.
 */
 
template <typename T>
class List {
 public:
  List() { }
  virtual ~List() { /* do nothing */ };

  /**
   * Determines the size of the list.
   * @return The number of elements in the list.
   */
  virtual int getSize() = 0;

  /**
   * Determines whether the list is empty.
   * @return true if the list is empty; false if it is not.
   */
  virtual bool isEmpty() = 0;

  /**
   * Retrieves the first element of the list.
   * @return The element at index 0 of this list.
   * @throws runtime_error If the list is empty.
   */
  virtual T peekHead() = 0;

  /**
   * Retrieves the last element of the list.
   * @return The element at the last index of this list.
   * @throws runtime_error If the list is empty.
   */
  virtual T peekTail() = 0;

  /**
   * Retrieves a reference to the element from the list at index i.
   * @param i The index for the element to retrieve.
   * @return A reference to the element at that index.
   * @throws runtime_error If there is no index i in this list.
   */
  virtual T& at(int i) = 0;

  /**
   * Retrieves a reference to the element from the list at index i.
   * @param i The index for the element to retrieve.
   * @return A reference to the element at that index.
   * Note: this method does not test if index is in the list
   *       so it is potentially memory unsafe
   */
  virtual T& operator[](int i) = 0;

  /**
   * Inserts a value at the beginning of this list.
   * @param value The value to insert.
   */
  virtual void insertAtHead(T value) = 0;

  /**
   * Inserts the value at the end of this list.
   * @param value The value to insert.
   */
  virtual void insertAtTail(T value) = 0;

  /**
   * Removes the first element from this list.
   * @return The element that was removed.
   * @throws runtime_error If the list was empty.
   */
  virtual void removeHead() = 0;

  /**
   * Removes the last element from this list.
   * @return The element that was removed.
   * @throws runtime_error If the list was empty.
   */
  virtual void removeTail() = 0;
};

#endif //ADTS_LIST_H
