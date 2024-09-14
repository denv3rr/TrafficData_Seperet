
/*
 * squarespace.cpp file that stores logic for handling account info
 * in the squarespace switch case
 *
 */

// Standard
#include <iostream>
#include <fstream>
#include <limits>
#include <conio.h> // for blocking password with asteriks

// Local
#include "squarespace.h"

SquarespaceAccount squarespaceAccount;

/*
 * functions that create data in text file of entered account info
 * for future use
 *
 */
void connectSquarespaceAccount()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer
    std::cout << "\n\nConnecting Squarespace Account\n\n";
    std::cout << "Enter Squarespace email: ";
    std::getline(std::cin, squarespaceAccount.email);

    std::cout << "Enter Squarespace password: ";
    char ch;
    squarespaceAccount.password.clear();

    // Read characters until the 'enter' key is pressed
    while ((ch = _getch()) != '\r')
    {
        if (ch == '\b') // handles backspace character
        {
            if (!squarespaceAccount.password.empty())
            {
                std::cout << "\b \b"; // this erases the last character
                squarespaceAccount.password.pop_back();
            }
        }
        else
        {
            squarespaceAccount.password.push_back(ch);
            std::cout << "*"; // Displays an asterik for each character (for privacy)
        }
    }
    std::getline(std::cin, squarespaceAccount.password);

    std::cout << "\033[32m\nSquarespace account connected successfully.\n\033[0m"; // Green text with reset

    saveSquarespaceAccount("squarespace_account.txt"); // Save the account info
}

void saveSquarespaceAccount(const std::string &filename)
{
    std::ofstream outFile(filename);
    if (outFile.is_open())
    {
        outFile << squarespaceAccount.email << "\n";
        outFile << squarespaceAccount.password << "\n";
        outFile.close();
        std::cout << "\033[32m\nSquarespace account information saved to " << filename << "\n\033[0m\n";
    }
    else
    {
        std::cerr << "\033[31m \nUnable to open file for writing.\n \033[0m";
    }
}

void loadSquarespaceAccount(const std::string &filename)
{
    std::cout << "Loading Squarespace account info...";
    std::ifstream inFile(filename);
    if (inFile.is_open())
    {
        std::getline(inFile, squarespaceAccount.email);
        std::getline(inFile, squarespaceAccount.password);
        inFile.close();
        std::cout << "\033[32m\nSquarespace account information loaded from " << filename << "\n\033[0m\n";
    }
    else
    {
        std::cerr << "\033[31m \nUnable to load Squarespace account info.\n\033[0m";
        std::cerr << "\033[31mThere was a fetch error or it does not exist.\n\n\033[0m";
    }
}
