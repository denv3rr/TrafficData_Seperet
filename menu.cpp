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

void handleMenuSelection(int choice)
{
    switch (choice)
    {
    case 1:
        addTrafficData();
        break;
    case 2:
        viewTrafficData();
        break;
    case 3:
        std::cout << "Visit: https://seperet.com\n";
        break;
    case 4:
        std::cout << "Visit: https:youtube.com/@seperet?sub_confirmation=1\n";
        break;
    case 5:
        std::cout << "Exiting...\n";
        break;

    default:
        std::cout << "Looks like you typed an invalid choice.\n";
        std::cout << "Please try again!\n";
        break;
    }
}