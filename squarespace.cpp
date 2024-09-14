/*
 * squarespace.cpp file that stores logic for handling account info
 * in the squarespace switch case
 *
 */
#include <iostream>
#include <fstream>
#include <limits>
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
        std::cerr << "\033[31m \nUnable to open file for reading.\n \033[0m";
    }
}
