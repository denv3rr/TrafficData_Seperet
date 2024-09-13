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
    std::cout << "Traffic data added successfully.\n";
};

void viewTrafficData()
{
    std::cout << "Internet Traffic Data:\n\n";
    for (const auto &data : trafficDataList)
    {
        std::cout << "URL: " << data.url << "\n, Visitors: " << data.visitors << "\n, Page Views: ";
        std::cout << data.pageViews << "\n, Bandwidth: " << data.bandwidth << " MB\n\n\n";
    }
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
        std::cout << "Traffic data saved to " << filename << "\n\n\n";
    }
    else
    {
        std::cout << "Unable to open this file for writing. Please try again.\n\n\n";
    }
};

void loadTrafficData(const std::string &filename)
{
    std::ifstream inFile(filename);
    if (!inFile)
    {
        std::cout << "A data file does not yet exist. If it does exist, the filenames do not match.\n";
        std::cout << "We currently have an empty dataset.\n";
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
        std::cout << "Traffic data loaded from " << filename << "\n";
    }
    else
    {
        std::cerr << "Unable to open file for reading. Please try again.\n\n\n";
    }
}