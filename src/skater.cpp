
#include "skater.h"

/*
Summary: Constructor for Skater
Begin:
    set variables and set next to null
End
*/
Skater::Skater(std::string c, float s) {
    // set variables and set next to null
    country = c;
    score = s;
    next = nullptr;
}

/*
Summary: Set next node
Begin:
    set next node to the input
End
*/
void Skater::setNext(Skater* p) {
    // set next node to the input
    next = p;
}

/*
Summary: Get country
Begin:
    return country
End
*/
std::string Skater::getCountry() {
    // return country
    return country;
}

/*
Summary: Get score
Begin:
    return score
End
*/
float Skater::getScore() {
    // return score
    return score;
}

/*
Summary: Get next node
Begin:
    return next node
End
*/
Skater* Skater::getNext() {
    // return next node
    return next;
}

// bool Skater::operator<(const Skater& rhs) {
//     if (score < rhs.score) {
//         return true;
//     } else {
//         return false;
//     }
// }
// bool Skater::operator>(const Skater& rhs) {
//     if (score > rhs.score) {
//         return true;
//     } else {
//         return false;
//     }
// }