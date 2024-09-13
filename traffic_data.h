/*
 * traffic_data.cpp header file
 *
 */
#ifndef TRAFFIC_DATA_H
#define TRAFFIC_DATA_H

#include <vector>
#include <string>

struct TrafficData
{
    std::string url;
    int visitors;
    int pageViews;
    double bandwidth; // in MB
};

void addTrafficData();
void viewTrafficData();
void saveTrafficData(const std::string &filename);
void loadTrafficData(const std::string &filename);

#endif // TRAFFIC_DATA_H