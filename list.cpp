

#include "list.h"

#include "skater.h"

List::List() { head = nullptr; }

void List::addNode(std::string country, float score) {
    if (head == nullptr) {
        head = Skater();
    }
}