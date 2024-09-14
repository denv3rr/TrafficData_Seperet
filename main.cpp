/*
 * main.cpp - main entry
 *
 */

// Standard
#include <iostream>
#include <csignal>

// Local
#include "menu.h"
#include "company_info.h"
#include "traffic_data.h"
#include "squarespace.h"

/*
 * start of main function here
 *
 */
int main()
{
    signal(SIGINT, signalHandler); // Registers the signal handler

    loadCompanyInfo("company_info.txt");                // Loads any previous info at start of program
    loadSquarespaceAccount("squarespace_acccount.txt"); // Load any known info at start

    MenuState state = MAIN_MENU;
    int choice;

    std::cout << "\n\n********************\n\n";
    std::cout << "By Denver Clark\n";
    std::cout << "\nVisit seperet.com";

    while (state != EXIT)
    {
        displayMenu(state);
        std::cin >> choice;
        handleMenuSelection(state, choice);
    }

    return 0;
}