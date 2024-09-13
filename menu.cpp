/*
 * menu.cpp - logic for menu selection, etc.
 *
 */

// Standard
#include <iostream>

// Local
#include "menu.h"
#include "traffic_data.h"
#include "link_opener.h"

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
    LinkOpener linkOpener;
    switch (choice)
    {
    case 1:
        addTrafficData();
        break;
    case 2:
        viewTrafficData();
        break;
    case 3:
        linkOpener.openSeperetWebsite();
        break;
    case 4:
        linkOpener.openSeperetYouTube();
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