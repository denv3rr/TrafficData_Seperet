/*
 * company_info.h - header file for company_info.cpp
 *
 */

#ifndef COMPANY_INFO_H
#define COMPANY_INFO_H

// Standard
#include <string>

// Local
#include "squarespace_api.h"

struct CompanyInfo
{
    std::string name;
    std::string address;
    std::string phone;
};

extern CompanyInfo companyInfo;
extern bool companyInfoUpdated; // Flags to check if the info was updated

void changeCompanyInfo();
void viewCompanyInfo();
void saveCompanyInfo(const std::string &filename);
void loadCompanyInfo(const std::string &filename);
void signalHandler(int signum);

#endif // COMPANY_INFO_H