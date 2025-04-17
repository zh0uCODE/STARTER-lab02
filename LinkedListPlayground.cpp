#include <iostream>
using namespace std;
class LinkedList { //this!!!!
private:
    struct Node {
        int data;
        Node* next;
    };

    Node* head;
    Node* tail;
    //start, middle, end : (head, next, tail
public:
    LinkedList() {
        //initialize head and tails
        head = nullptr;
        tail = nullptr;

    } //Constructor! Class name : init
    LinkedList(const LinkedList& source) { //copy constructor???????
        head = nullptr; //
        tail = nullptr; //
        Node* n = source.head; //movable
        while (n != nullptr) {
            //add the elements!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            this->push_back(n->data);
            n = n->next;
        }
    }
    ~LinkedList() { //delete all the nodes???
        Node* n = head;
        while (n != nullptr) {
            Node *temp = n->next; //save the next one!
            delete n; //delete the current one
            n = temp; //update the current one with the next one!
        }
    }
    void push_front(int value) {
        Node* n = new Node;;
        n->data = value;
        n->next = head; // shift old head up one!
        head = n; //update the head pointer with value n.
        if (tail == nullptr) {
            tail = n; //run out of tail? Update with N!
        }
    }
    void push_back(int value) {
        Node* n = new Node;
        n->data = value;
        n->next = nullptr; //the very last one!
        if (tail != nullptr) {
            tail->next = n; //if tail has something, set new tail with n
            tail = n;
        } else {
            tail = n; //run out? add something to tail
        }
        if (head == nullptr) {
            head = n;
        }
    }
    void printList() {
        Node *n = head;
        cout << '[';
        while (n != nullptr) {
            cout << n->data;
            if (n->next != nullptr) { //space if next still there!
                cout << " ";
            }
            n = n->next;
        }
        cout << "]" << endl;
    }
    int sum() {
        int sum = 0;
        Node *n = head;
        while (n != nullptr) {
            sum += n->data;
            n = n->next; //move the N!
        }
        return sum;
    }
    bool contains(int value) {
        Node *n = head;
        while (n != nullptr) {
            if (n->data == value) {
                return true;
            }
            n = n->next; //1s and zeros for true and false
        }
        return false;
    }
    int max() {
        int max;
        Node *n = head;
        if (n != nullptr) {
            max = n->data; //init max with something
        }
        while (n != nullptr) {
            if (n->data > max) {
                max = n->data;
            }
            n = n->next;
        }
        return max;
    }
    int count() {
        int count = 0;
        Node *n = head;
        while (n != nullptr) {
            count++;
            n = n->next;
        }
        return count;
    }
    int avg() {
        int sum = 0;
        int count = 0;
        Node *n = head;
        while (n != nullptr) {
            sum += n->data;
            n = n->next;
            count++;
        }
        return sum / count;
    }
    LinkedList& operator=(const LinkedList& source) {
        if (this == &source) {
            return *this;
        }
        delete head;
        delete tail;
        Node *n = source.head;
        while (n != nullptr) {
            this->push_back(n->data); //while n is something, add elements from the linked list to the copy!
            n = n->next; //move up one, check !
        }
        return *this;
    }
};
//good! no hc except initializing (only if necessary)
