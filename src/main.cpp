

#include <stdlib.h>
#include <unistd.h>

#include <iostream>
#include <limits>
#include <string>

#include "list.h"

/*
Summary: Print the menu and store the responses
Begin:
    initialize variables
    print menu
    get selection
    if selection == 1:
        get country and score
    if selection == 2:
        print sorted list
    if selection == 0:
        exit program
End
*/
bool menu(List *skaters) {
    // initialize variables
    std::string selection_in, country;
    int selection;
    float score;

    // print menu
    std::cout << "\n*** MENU ***" << std::endl;
    std::cout << "1. Enter a new team and score\n"
              << "2. Print rankings\n"
              << "0. Exit\n"
              << "Selection: ";

    // get selection
    std::cin >> selection_in;
    try {
        selection = std::stoi(selection_in);
    } catch (std::invalid_argument _) {
        std::string red = "\033[1;31m \033[0m";
        red.insert(8, "Error: Selection must be 0, 1 or 2");
        std::cout << "\n" << red << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return true;
    }
    // if selection == 1:
    if (selection == 1) {
        // get country and score
        std::cout << "Enter nation: ";
        std::cin.ignore();
        std::getline(std::cin, country);
        std::cout << "Enter score: ";
        std::cin >> score;
        skaters->addNode(country, score);
        // if selection == 2:
    } else if (selection == 2) {
        // print sorted list
        std::cout << *skaters << std::endl;
        // if selection == 0:
    } else if (selection == 0) {
        // exit program
        std::cout << "Exiting" << std::endl;
        return false;
    }
    return true;
}

/*
Summary: Enter the program and call menu till cont == false
Begin:
    initialize list
    while cont:
        call menu
End
*/
int main() {
    // initialize list
    List skaters;
    bool cont = true;
    // while cont:
    while (cont) {
        // call menu
        cont = menu(&skaters);
    }
}