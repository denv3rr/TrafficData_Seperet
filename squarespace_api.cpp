/*
 * squarespace_api.cpp for getting info from squarespace API
 */
#include <iostream>
#include <curl/curl.h>
#include "squarespace_api.h"

// Helper function to write data to a string
size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string *)userp)->append((char *)contents, size * nmemb);
    return size * nmemb;
}

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