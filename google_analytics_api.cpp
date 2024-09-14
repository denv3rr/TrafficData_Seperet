/*
 * Google API interaction C++ file
 *
 */
#include <iostream>
#include <curl/curl.h>
#include "google_analytics_api.h"

// Helper function to write data to a string
size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string *)userp)->append((char *)contents, size * nmemb);
    return size * nmemb;
}

std::string fetchGoogleAnalyticsData(const std::string &apiKey, const std::string &viewId, const std::string &startDate, const std::string &endDate)
{
    CURL *curl;
    CURLcode res;
    std::string readBuffer;

    curl = curl_easy_init();
    if (curl)
    {
        std::string url = "https://analyticsreporting.googleapis.com/v4/reports:batchGet?key=" + apiKey;
        std::string postData = R"({
            "reportRequests": [
                {
                    "viewId": ")" +
                               viewId + R"(",
                    "dateRanges": [
                        {
                            "startDate": ")" +
                               startDate + R"(",
                            "endDate": ")" +
                               endDate + R"("
                        }
                    ],
                    "metrics": [
                        {
                            "expression": "ga:sessions"
                        },
                        {
                            "expression": "ga:pageviews"
                        }
                    ]
                }
            ]
        })";

        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/json");

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postData.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }

    return readBuffer;
}

void viewGoogleAnalyticsData()
{
    std::string googleAnalyticsApiKey = "your_google_analytics_api_key";
    std::string viewId = "your_view_id";
    std::string startDate = "2023-01-01";
    std::string endDate = "2023-12-31";

    std::string analyticsData = fetchGoogleAnalyticsData(googleAnalyticsApiKey, viewId, startDate, endDate);

    std::cout << "Google Analytics Data:\n";
    std::cout << analyticsData << "\n";
}