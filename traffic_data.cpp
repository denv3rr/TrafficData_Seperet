/*
 * traffic_data.cpp - will get traffic data from a given site but
 * currently requires *manually* entering of data.
 *
 */

// Standard
#include <iostream>
#include <fstream>
#include <limits>
#include <csignal>

// Local
#include "traffic_data.h"
#include "google_analytics_api.h"
#include "squarespace_api.h"

std::vector<TrafficData> trafficDataList;

/*
 * Function to manually add traffic data
 *
 */
void addTrafficData()
{
    TrafficData data;
    std::cout << "\n\n";
    std::cout << "********************";
    std::cout << "\n\n";
    std::cout << "Enter URL: ";
    std::cin >> data.url;
    std::cout << "\nEnter number of visitors: ";
    std::cin >> data.visitors;
    std::cout << "\nEnter number of page views: ";
    std::cin >> data.pageViews;
    std::cout << "\nEnter bandwidth usage (in MB): ";
    std::cin >> data.bandwidth;
    trafficDataList.push_back(data);
    std::cout << "\033[32m \n\nTraffic data added successfully.\n\n \033[0m";

    // Append new data to the file
    std::ofstream outFile("traffic_data.txt", std::ios_base::app);
    if (outFile.is_open())
    {
        outFile << data.url << "\n"
                << data.visitors << "\n"
                << data.pageViews << "\n"
                << data.bandwidth << "\n";
        outFile.close();
    }
    else
    {
        std::cout << "\033[31m \n\nUnable to open this file for writing. Please try again.\n\n \033[0m";
    }
};

/*
 * Function to display Squarespace analytics data
 *
 */
/*
void viewAnalyticsData()
{
    std::string squarespaceApiKey = "your_squarespace_api_key";

    std::string analyticsData = fetchSquarespaceAnalyticsData(squarespaceApiKey);

    std::cout << "Squarespace Analytics Data:\n\n";
    std::cout << analyticsData << "\n";
};
*/

/*
 * Function to display Google Analytics data
 *
 */
/*
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
*/

/*
 * Main function for displaying analytics data from manual
 * entry as well as API integration
 *
 */
void viewTrafficData()
{
    std::ifstream inFile("traffic_data.txt");
    if (!inFile)
    {
        std::cout << "\033[31m \n\nA data file does not yet exist. If it does exist, the filenames do not match.\n \033[0m";
        std::cout << "We currently have an empty dataset.\n\n";
        return;
    }

    if (inFile.is_open())
    {
        TrafficData data;
        std::cout << "\n\n";
        std::cout << "********************";
        std::cout << "\n\n";
        std::cout << "TRAFFIC DATA REPORT:\n\n";
        while (std::getline(inFile, data.url) && inFile >> data.visitors >> data.pageViews >> data.bandwidth)
        {
            inFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the newline character after bandwidth
            std::cout << "URL: " << data.url << "\nVisitors: " << data.visitors << "\nPage Views: ";
            std::cout << data.pageViews << "\nBandwidth: " << data.bandwidth << " MB\n\n\n";
            std::cout << "\n\n\n";
        }

        std::cout << "\033[32m \n\nEnd of report.\n\n \033[0m";
        std::cout << "\n\n";
        std::cout << "********************";
        std::cout << "\n\n";
        inFile.close();
    }
    else
    {
        std::cerr << "\033[31m \n\nUnable to open file for reading. Please try again.\n\n \033[0m";
    }

    /*
    #ifdef ENABLE_SQUARESPACE
        if (!squarespaceApiKey.empty())
        {
            viewAnalyticsData();
        }
        else
        {
            std::cout << "Squarespace API key not found. Skipping Squarespace analytics data.\n";
        }
    #endif

    #ifdef ENABLE_GOOGLE_ANALYTICS
        if (!googleAnalyticsApiKey.empty())
        {
            viewGoogleAnalyticsData();
        }
        else
        {
            std::cout << "Google Analytics API key not found. Skipping Google Analytics data.\n";
        }
    #endif
    }
    */
}

/*
 * Saves changes to data text file
 *
 */
void saveTrafficData(const std::string &filename)
{
    std::ofstream outFile(filename);
    if (outFile.is_open())
    {
        for (const auto &data : trafficDataList)
        {
            outFile << data.url << " " << data.visitors << " " << data.pageViews << " " << data.bandwidth << "\n\n\n";
        }
        outFile.close();
        std::cout << "\033[32m \nTraffic data saved to:\n";
        std::cout << filename << "\n\n\n \033[0m";
    }
    else
    {
        std::cout << "\033[31m \n\nUnable to open this file for writing. Please try again.\n\n \033[0m";
    }
}

/*
 * Loads traffic data from a text file
 *
 */
void loadTrafficData(const std::string &filename)
{
    std::ifstream inFile(filename);
    if (!inFile)
    {
        std::cout << "\033[31m \n\nA data file does not yet exist. If it does exist, the filenames do not match.\n \033[0m";
        std::cout << "We currently have an empty dataset.\n\n";
        return;
    }

    if (inFile.is_open())
    {
        TrafficData data;
        while (std::getline(inFile, data.url) && inFile >> data.visitors >> data.pageViews >> data.bandwidth)
        {
            inFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the newline character after bandwidth
            trafficDataList.push_back(data);
        }
        inFile.close();
        std::cout << "\033[32m \n\nTraffic data loaded from: " << filename << "\n\n \033[0m";
    }
    else
    {
        std::cerr << "\033[31m \n\nUnable to open file for reading. Please try again.\n\n \033[0m";
    }
}