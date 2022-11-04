//
// Created by 王柯 on 11/3/22.
//

#ifndef LEETCODE_399_CALCEQUATION_H
#define LEETCODE_399_CALCEQUATION_H

#include "solution.h"

class CalcEquation : public solution {
public:
    map<string, pair<string, double>> mm;

    pair<string, double> find(string s) {
        if (mm.find(s) == mm.end()) {
            mm[s] = {s, 1};
        }
        pair<string, double> parent = mm[s];
        if (parent.first != s) {
            pair<string, double> newParent = find(parent.first);
            mm[s] = {newParent.first, newParent.second * parent.second};
        }
        return mm[s];
    }

    void myUnion(string s1, string s2, double v) {
        pair<string, double> tmp1 = find(s1);
        pair<string, double> tmp2 = find(s2);
        if (tmp1.first != tmp2.first) {
            mm[tmp2.first] = {tmp1.first, tmp1.second / tmp2.second * v};
        }
    }

//    double dfs(const string &curr, const string &dst, map<string, map<string, double>> &mm, set<string> &visited) {
//        if (visited.find(curr) != visited.end()) {
//            return -1;
//        }
//        visited.insert(curr);
//        if (mm[curr].find(dst) != mm[curr].end()) {
//            return mm[curr][dst];
//        }
//        map<string, double> next = mm[curr];
//        for (auto iter = next.begin(); iter != next.end(); ++iter) {
//            double tmp = dfs(iter->first, dst, mm, visited);
//            if (tmp != -1) {
//                tmp *= iter->second;
//                mm[curr][dst] = tmp;
//                return tmp;
//            }
//        }
//        visited.erase(curr);
//        return -1;
//    }

    vector<double>
    calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries) {
//        vector<double> res;
//        map<string, map<string, double>> mm;
//        for (int i = 0; i < equations.size(); ++i) {
//            mm[equations[i][0]][equations[i][1]] = values[i];
//            mm[equations[i][1]][equations[i][0]] = 1 / values[i];
//        }
//        for (auto &query : queries) {
//            set<string> visited;
//            if (query[0] == query[1]) {
//                if (mm.find(query[0]) != mm.end()) {
//                    res.push_back(1);
//                } else {
//                    res.push_back(-1);
//                }
//                continue;
//            }
//            double tmp = dfs(query[0], query[1], mm, visited);
//            res.push_back(tmp);
//        }
//
//        return res;

/*
 * Union Find solution / Disjoint Set
 */
        vector<double> res;
        for (int i = 0; i < equations.size(); ++i) {
            myUnion(equations[i][0], equations[i][1], values[i]);
        }
        for (auto &query : queries) {
            if (mm.find(query[0]) == mm.end() || mm.find(query[1]) == mm.end()) {
                res.push_back(-1);
                continue;
            }
            auto res1 = find(query[0]);
            auto res2 = find(query[1]);
            if (res1.first == res2.first) {
                res.push_back(res2.second / res1.second);
            } else {
                res.push_back(-1);
            }
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
