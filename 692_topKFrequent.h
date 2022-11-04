//
// Created by 王柯 on 11/4/22.
//

#ifndef LEETCODE_692_TOPKFREQUENT_H
#define LEETCODE_692_TOPKFREQUENT_H

#include "solution.h"

class TopKFrequent : public solution {
public:
    class cmp{
    public:
        bool operator() (const pair<string, int> &a, const pair<string, int> &b) {
            if (a.second != b.second) {
                return a.second > b.second;
            } else {
                return a < b;
            }
        }
    };

    bool myCmp (const pair<string, int> &a, const pair<string, int> &b) {
        if (a.second != b.second) {
            return a.second > b.second;
        } else {
            return a < b;
        }
    }

    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> res;
        unordered_map<string, int> mm;
        for (auto &word : words) {
            ++mm[word];
        }
        priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> pq;
        for (auto &i : mm) {
            if (pq.size() < k) {
                pq.push(i);
            } else {
                if (myCmp(i, pq.top())) {
                    pq.pop();
                    pq.push(i);
                }
            }
        }
        while (!pq.empty()) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        reverse(res.begin(), res.end());

        return res;
    }

    void check() {

    }
};

#endif //LEETCODE_692_TOPKFREQUENT_H
