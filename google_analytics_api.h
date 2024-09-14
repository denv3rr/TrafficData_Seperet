/*
 * Google API header file for google_analytics_api.cpp
 *
 */

#ifndef GOOGLE_ANALYTICS_API_H
#define GOOGLE_ANALYTICS_API_H

#include <string>

std::string fetchGoogleAnalyticsData(const std::string &apiKey, const std::string &viewId, const std::string &startDate, const std::string &endDate);
void viewGoogleAnalyticsData(); // Declare the function

#endif // GOOGLE_ANALYTICS_API_H