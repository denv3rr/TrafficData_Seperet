/*
 * main.cpp - main entry
 *
 */
#include <iostream>
#include <csignal>
#include "menu.h"
#include "company_info.h"
#include "traffic_data.h"

int main()
{
    signal(SIGINT, signalHandler); // Registers the signal handler

    loadCompanyInfo("company_info.txt"); // Loads any previous info at start of program

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