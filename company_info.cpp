/*
 * company_info.cpp - logic for updating company information
 *
 */

#include <iostream>
#include <fstream>
#include <limits>
#include <csignal>
#include "company_info.h"

CompanyInfo companyInfo;
bool companyInfoUpdated = false; // Initialize flad from header file

/*
 * function that handles SIGINT (exit) when in menus
 *
 */
void signalHandler(int signum)
{
    if (!companyInfoUpdated)
    {
        std::cout << "\033[31m\nCompany information was NOT changed due to the process being ended.\n\033[0m"; // Red text
    }
    exit(signum);
}

/*
 * function that changes company info and runs another function that saves it to a text file locally
 *
 */
void changeCompanyInfo()
{
    // clears the input buffer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // 'Edit Company Info' form:
    std::cout << "\n\nEditing Company Info\n\n";
    std::cout << "Enter new company name: ";
    std::getline(std::cin, companyInfo.name);

    std::cout << "\nEnter new company address: ";
    std::getline(std::cin, companyInfo.address);

    std::cout << "\nEnter new company phone number: ";
    std::getline(std::cin, companyInfo.phone);

    companyInfoUpdated = true; // sets flag to true

    std::cout << "\033[32m \nCompany information updated successfully.\n \033[0m";

    // Runs function - saves entered info for the future
    saveCompanyInfo("company_info.txt");
}

/*
 * the actual function **for saving the info into a text file locally**
 */
void saveCompanyInfo(const std::string &filename)
{
    std::ofstream outFile(filename);
    if (outFile.is_open())
    {
        outFile << companyInfo.name << "\n";
        outFile << companyInfo.address << "\n";
        outFile << companyInfo.phone << "\n";
        outFile.close();
        std::cout << "\033[32m \nCompany information saved to \n \033[0m" << filename << "\n";
    }
    else
    {
        std::cerr << "\033[31m \nUnable to open file for writing.\n \033[0m";
    }
}

/*
 * function that loads the saved information when program runs by checking if
 * the file exists, then going through each line. It then gives a confirmation.
 *
 */
void loadCompanyInfo(const std::string &filename)
{
    std::ifstream inFile(filename);
    if (inFile.is_open())
    {
        std::getline(inFile, companyInfo.name);
        std::getline(inFile, companyInfo.address);
        std::getline(inFile, companyInfo.phone);
        inFile.close();
        std::cout << "\033[32m \nCompany information loaded from \n \033[0m" << filename << "\n";
    }
    else
    {
        std::cerr << "\033[31m \nUnable to open file for reading.\n \033[0m";
    }
}