#ifndef SKATER_H
#define SKATER_H

#include <string>

#include "skater.h"

class Skater {
   public:
    Skater(std::string c, float s);
    std::string getCountry();
    float getScore();
    Skater *getNext();
    void setNext(Skater *p);

   private:
    std::string country;
    float score;
    Skater *next;
};

#endif