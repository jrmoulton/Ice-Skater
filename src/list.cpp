
#include "list.h"

#include <iomanip>
#include <iostream>

#include "skater.h"

/*
Summary: Constructor for a list
Begin:
    set head to null
End
*/
List::List() {
    // set head to null
    head = nullptr;
}

/*
Summary: Add the new node in its sorted place
Begin:
    if head == null:
        set head to new node
    else:
        set pos to head
        move pos to correct location
    if new node is less than end of list:
        set new node to end of list
    else if new node is greater than head:
        set new node to head
    else if new node is inbetween two values in the list:
        set new node inbetween those two values
End
*/
void List::addNode(std::string country, float score) {
    Skater* new_node = new Skater(country, score);
    // if head == null:
    if (head == nullptr) {
        // set head to new node
        head = new_node;
    } else {
        // set pos to head
        Skater* pos = head;
        // move pos to correct location
        while (pos->getNext() && new_node < pos->getNext()) {
            pos = pos->getNext();
        }
        // if new node is less than end of list:
        if (!(pos->getNext()) && new_node <= pos) {
            // set new node to end of lis
            pos->setNext(new_node);
            // else if new node is greater than head:
        } else if (new_node >= head) {
            // set new node to head
            new_node->setNext(head);
            head = new_node;
            // else if new node is inbetween two values in the list:
        } else if (new_node <= pos &&
                   new_node >= pos->getNext()) {
            // set new node inbetween those two values
            new_node->setNext(pos->getNext());
            pos->setNext(new_node);
        }
    }
}

/*
Summary: Deconstructor to delete the allocated values
Begin:
    while list is not empty:
        temp = head
        head = next
        print deleting node
        delete node
End
*/
List::~List() {
    Skater* temp;
    // while list is not empty:
    while (head != nullptr) {
        // temp = head
        temp = head;
        // head = next
        head = head->getNext();
        // print deleting node
        std::cout << "Deleting: " << temp << std::endl;
        // delete node
        delete temp;
    }
}

/*
Summary: An overloaded function to print the rankings
*/
std::ostream& operator<<(std::ostream& os, const List& m) {
    Skater* temp = m.head;
    os << "\n***RANKINGS***\n";
    while (temp != nullptr) {
        os << std::setw(18) << std::left << temp->getCountry() << std::setw(5)
           << "\t" << temp->getScore() << "\n";
        temp = temp->getNext();
    }
    return os;
}