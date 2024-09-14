/*
 * squarespace_api.cpp for getting info from squarespace API
 */

#ifndef ENABLE_SQUARESPACE

// Standard
#include <iostream>
#include <curl/curl.h>

// Local
#include "squarespace_api.h"
#include "write_callback.h"

std::string fetchSquarespaceAnalyticsData(const std::string &apiKey)
{
    CURL *curl;
    CURLcode res;
    std::string readBuffer;

    curl = curl_easy_init();
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, "https://api.squarespace.com/1.0/commerce/orders");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, "Authorization: Bearer " + apiKey);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }

    return readBuffer;
}

void viewAnalyticsData()
{
    std::string squarespaceApiKey = "your_squarespace_api_key";

    std::string analyticsData = fetchSquarespaceAnalyticsData(squarespaceApiKey);

    std::cout << "Squarespace Analytics Data:\n\n";
    std::cout << analyticsData << "\n";
}

#endif // ENABLE_SQUARESPACE