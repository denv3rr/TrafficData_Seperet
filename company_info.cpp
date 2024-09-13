/*
 * company_info.cpp - logic for updating company information
 *
 */

#include <iostream>
#include "company_info.h"

CompanyInfo companyInfo;

void changeCompanyInfo()
{
    std::cout << "\n\nEditing Company Info\n\n";
    std::cout << "Enter new company name: ";
    std::getline(std::cin, companyInfo.name);
    std::cout << "\nEnter new company address: \n";
    std::getline(std::cin, companyInfo.address);
    std::cout << "\nEnter new company phone number: \n";
    std::getline(std::cin, companyInfo.phone);
    std::cout << "\nCompany information updated successfully.\n";
}