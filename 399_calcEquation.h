//
// Created by 王柯 on 11/3/22.
//

#ifndef LEETCODE_399_CALCEQUATION_H
#define LEETCODE_399_CALCEQUATION_H

#include "solution.h"

class CalcEquation : public solution {
public:
    double dfs(const string &curr, const string &dst, map<string, map<string, double>> &mm, set<string> &visited) {
        if (visited.find(curr) != visited.end()) {
            return -1;
        }
        visited.insert(curr);
        if (mm[curr].find(dst) != mm[curr].end()) {
            return mm[curr][dst];
        }
        map<string, double> next = mm[curr];
        for (auto iter = next.begin(); iter != next.end(); ++iter) {
            double tmp = dfs(iter->first, dst, mm, visited);
            if (tmp != -1) {
                tmp *= iter->second;
                mm[curr][dst] = tmp;
                return tmp;
            }
        }
        visited.erase(curr);
        return -1;
    }

    vector<double>
    calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries) {
        vector<double> res;
        map<string, map<string, double>> mm;
        for (int i = 0; i < equations.size(); ++i) {
            mm[equations[i][0]][equations[i][1]] = values[i];
            mm[equations[i][1]][equations[i][0]] = 1 / values[i];
        }
        for (auto &query : queries) {
            set<string> visited;
            if (query[0] == query[1]) {
                if (mm.find(query[0]) != mm.end()) {
                    res.push_back(1);
                } else {
                    res.push_back(-1);
                }
                continue;
            }
            double tmp = dfs(query[0], query[1], mm, visited);
            res.push_back(tmp);
        }

        return res;
    }

    void check() {
        vector<vector<string>> equations{{"a", "b"},
                                         {"b", "c"}};
        vector<double> values{2.0, 3.0};
        vector<vector<string>> queries{{"a", "c"},
                                       {"b", "a"},
                                       {"a", "e"},
                                       {"a", "a"},
                                       {"x", "x"}};
        auto res = calcEquation(equations, values, queries);
        for (auto i : res) {
            cout << i << endl;
        }
    }
};

#endif //LEETCODE_399_CALCEQUATION_H
