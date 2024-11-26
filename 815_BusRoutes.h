//
// Created by Ke Wang on 11/26/24.
//

#ifndef INC_815_BUSROUTES_H
#define INC_815_BUSROUTES_H

#include "solution.h"

class BusRoutes : public solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) {
            return 0;
        }
        unordered_map<int, vector<int>> stop2bus;
        unordered_map<int, unordered_set<int>> bus2bus;
        for (int i = 0; i < routes.size(); ++i) {
            for (auto j : routes[i]) {
                stop2bus[j].push_back(i);
            }
        }
        for (auto &tmp : stop2bus) {
            vector<int> &buses = tmp.second;
            for (int i = 0; i < buses.size(); ++i) {
                for (int j = 0; j < buses.size(); ++j) {
                    if (i != j) {
                        bus2bus[buses[i]].insert(buses[j]);
                    }
                }
            }
        }

        int res = 1;
        queue<int> curr;
        unordered_set<int> visited, end;
        for (auto i : stop2bus[target]) {
            end.insert(i);
        }
        for (auto i : stop2bus[source]) {
            curr.push(i);
            visited.insert(i);
        }

        while (!curr.empty()) {
            int len = curr.size();
            for (int i = 0; i < len; ++i) {
                int tmp = curr.front();
                curr.pop();
                if (end.find(tmp) != end.end()) {
                    return res;
                }
                for (auto j : bus2bus[tmp]) {
                    if (visited.find(j) == visited.end()) {
                        curr.push(j);
                        visited.insert(j);
                    }
                }
            }
            ++res;
        }

        return -1;
    }
};

#endif //INC_815_BUSROUTES_H
