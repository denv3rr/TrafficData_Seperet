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

void changeCompanyInfo();

#endif // COMPANY_INFO_H