#ifndef SKATER_H
#define SKATER_H

#include <string>

class Skater {
   public:
    Skater(std::string c, float s);
    std::string getCountry();
    float getScore();
    Skater *getNext();
    void setNext(Skater *p);
    bool operator<(const Skater &rhs);
    bool operator>(const Skater &rhs);

   private:
    std::string country;
    float score;
    Skater *next;
};

#endif