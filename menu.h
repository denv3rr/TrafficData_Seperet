/*
 * menu.cpp header
 *
 */

#ifndef MENU_H
#define MENU_H

enum MenuState
{
    MAIN_MENU,
    COMPANY_INFO_MENU,
    /*
     * this is where new menu states
     * can be added if you need them
     * at any point
     *
     */
};

void displayMenu();
void handleMenuSelection(int choice);

#endif // MENU_H