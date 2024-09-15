/*
 * main.cpp - main entry
 *
 */

// Standard
#include <iostream>
#include <csignal>
#include <thread>
#include <chrono>

// Local
#include "menu.h"
#include "company_info.h"
#include "traffic_data.h"
#include "squarespace.h"

/*
 * Opening title banner function
 *
 */
void displayTitleBanner()
{
    const std::string title = "Internet Traffic Auditor\n\nBy Denver Clark\n\nVisit seperet.com";
    const std::string border = "********************";
    const int delay = 50; // Delay in milliseconds

    std::cout << "\n\n";
    for (char c : border)
    {
        std::cout << c;
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    }
    std::cout << "\n\n";

    for (char c : title)
    {
        std::cout << c;
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    }
    std::cout << "\n\n";

    for (char c : border)
    {
        std::cout << c;
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    }
    std::cout << "\n\n";
}

/*
 * start of main function here
 *
 */
int main()
{
    displayTitleBanner();
    signal(SIGINT, signalHandler); // Registers the signal handler

    loadCompanyInfo("company_info.txt");                // Loads any previous company info at start
    loadSquarespaceAccount("squarespace_acccount.txt"); // Load any known Squarespace info at start
    loadTrafficData("traffic_data.txt");

    MenuState state = MAIN_MENU;
    int choice;

    while (state != EXIT)
    {
        displayMenu(state);
        std::cin >> choice;
        handleMenuSelection(state, choice);
    }

    return 0;
}