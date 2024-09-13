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
#include "company_info.h"

/*
 * displayMenu() function - self explanitory
 */
void displayMenu(MenuState state)
{
    std::cout << "\n\n********************\n\n";
    std::cout << "Internet Traffic Auditor";
    std::cout << "\n\n********************\n\n";

    /*
     * changes menu state (ADD OPTIONS as needed)
     */
    switch (state)
    {
    case MAIN_MENU:
        std::cout << "1. Add Traffic Data\n";
        std::cout << "2. View Traffic Data\n";
        std::cout << "3. Visit Seperet.com\n";
        std::cout << "4. Visit Our YouTube Channel\n";
        std::cout << "5. Change Company Information\n";
        std::cout << "6. Exit\n";
        break;
    case COMPANY_INFO_MENU:
        std::cout << "1. Edit Company Information\n";
        std::cout << "2. Back\n";
        break;

        /*
         * add menu option cases here (changes menu state)
         */
    }

    std::cout << "\n";
    std::cout << "Enter selection:\n";
}

void handleMenuSelection(MenuState &state, int choice)
{
    LinkOpener linkOpener;
    switch (state)
    {
    // Main menu switch case
    case MAIN_MENU:
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
            state = COMPANY_INFO_MENU;
            break;
        case 6:
            std::cout << "\n********************\n";
            std::cout << "\nExiting...\n";
            break;
        default:
            std::cout << "Looks like you typed an invalid choice.\n";
            std::cout << "Please try again!\n";
            break;
        }
        break;

    // 'Company Info' menu switch case
    case COMPANY_INFO_MENU:
        switch (choice)
        {
        case 1:
            changeCompanyInfo();
            break;
        case2:
            state = MAIN_MENU;
            break;
        default:
            std::cout << "Looks like you typed an invalid choice.\n";
            std::cout << "Please try again!\n";
            break;
        }
        break;
    }
}