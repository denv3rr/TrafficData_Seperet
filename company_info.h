/*
 * company_info.h - header file for company_info.cpp
 *
 */

#ifndef COMPANY_INFO_H
#define COMPANY_INFO_H

#include <string>

struct CompanyInfo
{
    std::string name;
    std::string address;
    std::string phone;
};

extern CompanyInfo companyInfo;
extern bool companyInfoUpdated; // Flags to check if the info was updated

void changeCompanyInfo();
void saveCompanyInfo(const std::string &filename);
void loadCompanyInfo(const std::string &filename);

#endif // COMPANY_INFO_H