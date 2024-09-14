/*
 * header file for squarespace.cpp
 *
 */

#ifndef SQUARESPACE_H
#define SQUARESPACE_H

#include <string>

struct SquarespaceAccount
{
    std::string email;
    std::string password;
};

extern SquarespaceAccount squarespaceAccount;

void connectSquarespaceAccount();
void saveSquarespaceAccount(const std::string &filename);
void loadSquarespaceAccount(const std::string &filename);

#endif // SQUARESPACE_H