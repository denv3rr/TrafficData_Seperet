/*
 * traffic_data.cpp - will get traffic data from a given site but
 * currently requires *manually* entering of data.
 *
 */
#include <iostream>
#include <fstream>
#include "traffic_data.h"

std::vector<TrafficData> trafficDataList;

void addTrafficData()
{
    TrafficData data;
    std::cout << "Enter URL: ";
    std::cin >> data.url;
    std::cout << "Enter number of visitors: ";
    std::cin >> data.visitors;
    std::cout << "Enter number of page views: ";
    std::cin >> data.pageViews;
    std::cout << "Enter bandwidth usage (in MB): ";
    std::cin >> data.bandwidth;
    trafficDataList.push_back(data);
    std::cout << "\033[32m \nTraffic data added successfully.\n\n \033[0m";
};

void viewTrafficData()
{
    std::cout << "Internet Traffic Data:\n\n";
    for (const auto &data : trafficDataList)
    {
        std::cout << "URL: " << data.url << "\n, Visitors: " << data.visitors << "\n, Page Views: ";
        std::cout << data.pageViews << "\n, Bandwidth: " << data.bandwidth << " MB\n\n\n";
    };

    void viewAnalyticsData()
    {
        std::string squarespaceApiKey = "your_squarespace_api_key";

        std::string analyticsData = fetchSquarespaceAnalyticsData(squarespaceApiKey);

        std::cout << "Squarespace Analytics Data:\n\n";
        std::cout << analyticsData << "\n";
    };
};

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
        std::cout << "\033[32m \nTraffic data saved to " << filename << "\n\n\n \033[0m";
    }
    else
    {
        std::cout << "\033[31m \nUnable to open this file for writing. Please try again.\n\n \033[0m";
    }
};

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
        while (inFile >> data.url >> data.visitors >> data.pageViews >> data.bandwidth)
        {
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