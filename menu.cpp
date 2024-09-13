/*
 * menu.cpp - logic for menu selection, etc.
 *
 */

#include <iostream>
#include "menu.h"
#include "traffic_data.h"

/*
 * displayMenu() function - self explanitory
 */
void displayMenu()
{
    std::cout << "Internet Traffic Auditor\n\n";
    std::cout << "1. Add Traffic Data\n";
    std::cout << "2. View Traffic Data\n";
    std::cout << "3. Visit Seperet.com\n";
    std::cout << "4. Visit Our YouTube Channel\n";
    std::cout << "5. Exit\n";
    std::cout << "\n";
    std::cout << "Enter selection:\n";
}