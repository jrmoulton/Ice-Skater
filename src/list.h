
#ifndef LIST_H
#define LIST_H

#include <string>

#include "skater.h"

class List {
   public:
    List();
    void addNode(std::string country, float score);
    void printList();
    ~List();
    friend std::ostream& operator<<(std::ostream& os, const List& m);

   private:
    Skater* head;
};
std::ostream& operator<<(std::ostream& os, const List& m);

#endif