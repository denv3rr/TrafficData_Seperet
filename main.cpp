/*
 * main.cpp - main entry
 *
 */
#include <iostream>
#include "menu.h"
#include "traffic_data.h"

int main()
{
    const std::string filename = "traffic_data.txt"; // this will be the name of the output file
    loadTrafficData(filename);

    int choice;

    do
    {
        displayMenu();
        std::cin >> choice;
        handleMenuSelection(choice);
    } while (choice != 5); // change this depending on exit function location

    saveTrafficData(filename);
    return 0;
}