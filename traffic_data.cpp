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

void viewTrafficData() {

};