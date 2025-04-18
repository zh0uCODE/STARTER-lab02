// intlist.cpp
// Implements class IntList
// YOUR NAME(S), AND DATE

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    head = nullptr;
    tail = nullptr;
    Node *n = source.head;
    while (n != nullptr) {
      this->push_back(n->info);
      n = n->next;
    }
}

// destructor deletes all nodes
IntList::~IntList() {
    Node *n = head;
    while (n != nullptr) {
      Node *temp = n->next;
      delete n; 
      n = temp;
    }
}


// return sum of values in list
int IntList::sum() const {
    int sum = 0;
    Node *n = head;
    while (n != nullptr) {
      sum += n->info;
      n = n->next;
    }
    return sum; // REPLACE THIS NON-SOLUTION
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node *n = head;
    while (n != nullptr) {
      if (n->info == value) {
        return true;
      }
      n = n->next;
    }
    return false;  // REPLACE THIS NON-SOLUTION
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    int max;
    Node *n = head;
    if (n != nullptr) {
      max = n->info;
    } else {
        max = 0;
    }
    while (n != nullptr) {
      if (n->info > max) {
        max = n->info;
      }
      n = n->next;
    }
    return max;  // REPLACE THIS NON-SOLUTION
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    int sum = 0;
    int count = 0;
    Node *n = head;
    while (n != nullptr) {
      sum += n->info;
      n = n->next;
      count++;
    }
    if (count == 0) {
      return 0;
    }
    return sum / count; // REPLACE THIS NON-SOLUTION
}

// inserts value as new node at beginning of list
void IntList::push_front(int value) {
    Node *n = new Node;
    n->info = value;
    n->next = head;
    head = n;
    if (tail == nullptr) {
      tail = n;
    }
}

// append value at end of list
void IntList::push_back(int value) {
    Node *n = new Node;
    n->info = value;
    n->next = nullptr;
    if (tail != nullptr) {
      tail->next = n;
      tail = n;
    } else {
      tail = n;
    }
    if (head == nullptr) {
      head = n;
    }
}

// return count of values
int IntList::count() const {
    int count = 0;
    Node *n = head;
    while (n != nullptr) {
      count++;
      n=n->next;
    }
    return count;
}


//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    if (this == &source) {
      return *this;
    }
    head = nullptr;
    tail = nullptr;
    Node *n = source.head;
    while (n != nullptr) {
      this->push_back(n->info);
      n=n->next;
    }
    return *this;
}

// constructor sets up empty list
IntList::IntList(){ 
    head = nullptr;
    tail = nullptr; 
}


// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = head;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

