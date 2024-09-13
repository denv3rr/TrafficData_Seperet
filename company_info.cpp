/*
 * company_info.cpp - logic for updating company information
 *
 */

#include <iostream>
#include "company_info.h"

CompanyInfo companyInfo;

void changeCompanyInfo()
{
    std::cout << "Enter new company name";
    std::cout << "Enter new company name: ";
    std::getline(std::cin, companyInfo.name);
    std::cout << "Enter new company address: ";
    std::getline(std::cin, companyInfo.address);
    std::cout << "Enter new company phone number: ";
    std::getline(std::cin, companyInfo.phone);
    std::cout << "Company information updated successfully.\n";
}