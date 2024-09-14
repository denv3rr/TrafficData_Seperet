/*
 * header file for squarespace_api.cpp
 */
#ifndef SQUARESPACE_API_H
#define SQUARESPACE_API_H

#include <string>

#ifndef ENABLE_SQUARESPACE
std::string fetchSquarespaceAnalyticsData(const std::string &apiKey);
void viewAnalyticsData();
#endif // ENABLE_SQUARESPACE

#endif // SQUARESPACE_API_H
