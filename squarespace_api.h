/*
 * header file for squarespace_api.cpp
 */
#ifndef SQUARESPACE_API_H
#define SQUARESPACE_API_H

#include <string>

std::string fetchSquarespaceTrafficData(const std::string &apiKey);
std::string fetchGoogleSheetsData(const std::string &spreadsheetId, const std::string &range);

#endif // SQUARESPACE_API_H
