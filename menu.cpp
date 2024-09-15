/*
 * menu.cpp - logic for menu selection, etc.
 *
 */

// Standard
#include <iostream>
#include <map>

// Local
#include "menu.h"
#include "traffic_data.h"
#include "link_opener.h"
#include "company_info.h"
// #include "squarespace.h"
// #include "google_analytics_api.h"

/*
 * map for menu modularity by storing object names and printing
 * them as a current menu path for the user
 */
std::map<MenuState, std::string> menuPaths = {
    {MAIN_MENU, "Main Menu"},
    {TRAFFIC_DATA_MENU, "Traffic Data"},
    {COMPANY_INFO_MENU, "Company Information"},
    {SQUARESPACE_MENU, "Squarespace Account Info"}
    // Add other menu states as needed
};

/*
 * displayCurrentPath() function
 */
void displayCurrentPath(MenuState state)
{

    /*
     * shows current menu name (ADD OPTIONS as needed)
     */
    std::cout << companyInfo.name << "\n";
    std::cout << menuPaths[state] << "\n\n";
}

/*
 * displayMenu() function - displays different menus
 * (new menu states can be added)
 */
void displayMenu(MenuState state)
{
    // title banner
    std::cout << "\n\n********************\n\n";

    // calls function to display current menu location
    displayCurrentPath(state);

    /*
     * changes menu state (ADD OPTIONS as needed)
     */
    switch (state)
    {
    case MAIN_MENU:
        std::cout << "1. Traffic Data\n";
        std::cout << "2. Company Information\n";
        std::cout << "3. Connect Squarespace Account\n";
        std::cout << "4. View Google Analytics Data\n";
        std::cout << "5. Visit Seperet.com\n";
        std::cout << "6. Visit Our YouTube Channel\n";
        std::cout << "7. Exit\n";
        break;
    case COMPANY_INFO_MENU:
        std::cout << "1. Edit Company Information\n";
        std::cout << "2. View Company Information\n";
        std::cout << "3. Back\n";
        std::cout << "4. Exit\n";
        break;
    case SQUARESPACE_MENU:
        std::cout << "1. Enter Squarespace Account Information\n";
        std::cout << "2. Back\n";
        std::cout << "3. Exit\n";
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
            state = TRAFFIC_DATA_MENU;
            break;
        case 2:
            state = COMPANY_INFO_MENU;
            break;
        case 3:
            state = SQUARESPACE_MENU;
            break;
        case 4:
            // this will hold call to Google Analytics functions
        case 5:
            linkOpener.openSeperetWebsite();
            break;
        case 6:
            linkOpener.openSeperetYouTube();
            break;
        case 7:
            state = EXIT;
            std::cout << "\n********************\n";
            std::cout << "\nExiting...\n";
            break;
        default:
            std::cout << "\033[31m \nLooks like you typed an invalid choice.\n\033[0m";
            std::cout << "Please try again!\n";
            break;
        }
        break;

    // "Traffic Data" menu switch case
    case TRAFFIC_DATA_MENU:
        switch (choice)
        {
        case 1:
            addTrafficData();
            break;
        case 2:
            viewTrafficData();
            break;
        case 3:
            state = MAIN_MENU;
            break;
        case 4:
            state = EXIT;
            break;
        default:
            std::cout << "\033[31m \nLooks like you typed an invalid choice.\n\033[0m";
            std::cout << "Please try again!\n";
            break;
        }

    // 'Company Info' menu switch case
    case COMPANY_INFO_MENU:
        switch (choice)
        {
        case 1:
            changeCompanyInfo();
            break;
        case 2:
            viewCompanyInfo();
            break;
        case 3:
            state = MAIN_MENU;
            break;
        case 4:
            state = EXIT;
            break;
        default:
            std::cout << "\033[31m \nLooks like you typed an invalid choice.\n\033[0m";
            std::cout << "Please try again!\n";
            break;
        }
        break;

    case SQUARESPACE_MENU:
        switch (choice)
        {
        case 1:
            // connectSquarespaceAccount();
            break;
        case 2:
            state = MAIN_MENU;
            break;
        case 3:
            state = EXIT;
            break;
        default:
            std::cout << "\033[31m \nLooks like you typed an invalid choice.\n\033[0m";
            std::cout << "Please try again!\n";
            break;
        }
        break;
    }
}