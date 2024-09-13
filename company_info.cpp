/*
 * company_info.cpp - logic for updating company information
 *
 */

#include <iostream>
#include "company_info.h"

CompanyInfo companyInfo;

void changeCompanyInfo()
{
    int choice;
    std::cout << "1. Edit Company Information\n";
    std::cout << "2. Exit\n";
    std::cout << "Enter selection: ";
    std::cin >> choice;

    if (choice == 2)
    {
        std::cout << "\nExiting 'Edit Company Information' page.\n\n";
        return;
    }

    std::cout << "Enter new company name";
    std::cout << "Enter new company name: ";
    std::getline(std::cin, companyInfo.name);
    std::cout << "Enter new company address: ";
    std::getline(std::cin, companyInfo.address);
    std::cout << "Enter new company phone number: ";
    std::getline(std::cin, companyInfo.phone);
    std::cout << "Company information updated successfully.\n";
}