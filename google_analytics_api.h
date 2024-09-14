/*
 * Google API header file for google_analytics_api.cpp
 *
 */

#ifndef GOOGLE_ANALYTICS_API_H
#define GOOGLE_ANALYTICS_API_H

#include <string>

#ifndef ENABLE_GOOGLE_ANALYTICS
std::string fetchGoogleAnalyticsData(const std::string &apiKey, const std::string &viewId, const std::string &startDate, const std::string &endDate);
void viewGoogleAnalyticsData();
#endif // ENABLE_GOOGLE_ANALYTICS

#endif // GOOGLE_ANALYTICS_API_H