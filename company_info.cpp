/*
 * company_info.cpp - logic for updating company information
 *
 */

#include <iostream>
#include <limits>
#include "company_info.h"

CompanyInfo companyInfo;

void changeCompanyInfo()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clears the input buffer
    std::cout << "\n\nEditing Company Info\n\n";
    std::cout << "Enter new company name: ";
    std::getline(std::cin, companyInfo.name);

    std::cout << "\nEnter new company address: ";
    std::getline(std::cin, companyInfo.address);

    std::cout << "\nEnter new company phone number: ";
    std::getline(std::cin, companyInfo.phone);

    std::cout << "\033[32m \nCompany information updated successfully.\n \033[0m";
}