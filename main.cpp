/*
 * main.cpp - main entry
 *
 */
#include <iostream>
#include "menu.h"
#include "traffic_data.h"

int main()
{
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