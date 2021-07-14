#include "UnsortedList.h"
#include <iostream>


//exceptions that can be thrown
class FullList 
{};
class DuplicateItem
{};
class OutOfBound
{};
class ItemNotFound
{};
//Constructors--------------
template <class ItemType>
UnsortedList<ItemType>::UnsortedList() {
  length = 0;
  Max_Items = 50;
  info = new ItemType[Max_Items];
} //default

template <class ItemType>
UnsortedList<ItemType>::UnsortedList(int size) {
  length = 0;
  Max_Items = size;
  info = new ItemType[Max_Items];
} //one argument

//Destructor-----------------
template <class ItemType>
UnsortedList<ItemType>::~UnsortedList() {
  delete [] info;
  makeEmpty();
} //destructor

//Const Methods--------------
template <class ItemType>
bool UnsortedList<ItemType>::isEmpty() const {
  if (length == 0) {
    return true;
  } else {
    return false;
  }
} //isEmpty

template <class ItemType>
bool UnsortedList<ItemType>::isFull() const {
  if (length == Max_Items) {
    return true;
  } else {
    return false;
  }
} //isFull

template <class ItemType>
int UnsortedList<ItemType>::getLength() const {
  return length;
} //getLength

template <class ItemType>
ItemType UnsortedList<ItemType>::getAt(int index) const {
  if (index < 0 || index >= length) {
    throw OutOfBound();
  } else {
    return info[index];
  }
} //getAt

//-----Helper-Const-----------
template <class ItemType>
int UnsortedList<ItemType>::findIndex(ItemType item) const {
  int index = -1;
  for (int i = 0; i < getLength(); i++) {
    if (info[i] == item) {
      index = i;
    }
  }
  return index;
} //findIndex

//Regular Methods----------------
template <class ItemType>
void UnsortedList<ItemType>::putItem(ItemType newItem) {
  if (getLength() == Max_Items) {
    throw FullList();
  }
  if (findIndex(newItem) != -1) {
    throw DuplicateItem();
  }
  info[length] = newItem;
  length++;
} //putItem

template <class ItemType>
void UnsortedList<ItemType>::deleteItem(ItemType Item) {
  if (findIndex(Item) == -1) {
    throw ItemNotFound();
  }
  int index = findIndex(Item);
  info[index] = info[length - 1];
  length--;
} //deleteItem

template <class ItemType>
void UnsortedList<ItemType>::makeEmpty() {
  length = 0;
} //makeEmpty
