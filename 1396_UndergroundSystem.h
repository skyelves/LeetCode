//
// Created by 王柯 on 10/1/22.
//

#ifndef LEETCODE_1396_UNDERGROUNDSYSTEM_H
#define LEETCODE_1396_UNDERGROUNDSYSTEM_H

#include "solution.h"

class UndergroundSystem {
public:
    map<pair<string, string>, int> totalTime, totalNum;
    map<int, pair<string, int> > checkInRecord;
    UndergroundSystem() {

    }

    void checkIn(int id, string stationName, int t) {
        checkInRecord.insert({id, {stationName, t}});
    }

    void checkOut(int id, string stationName, int t) {
        auto tmp = checkInRecord[id];
        totalNum[{tmp.first, stationName}]++;
        totalTime[{tmp.first, stationName}] += t - tmp.second;
        checkInRecord.erase(id);
    }

    double getAverageTime(string startStation, string endStation) {
        return (double) totalTime[{startStation, endStation}] / totalNum[{startStation, endStation}];
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */

#endif //LEETCODE_1396_UNDERGROUNDSYSTEM_H
