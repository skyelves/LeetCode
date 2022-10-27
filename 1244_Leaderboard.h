//
// Created by 王柯 on 10/1/22.
//

#ifndef LEETCODE_1244_LEADERBOARD_H
#define LEETCODE_1244_LEADERBOARD_H

#include "solution.h"

class Leaderboard {
public:
    struct comp {
        bool operator()(const pair<int, int> &a, const pair<int, int> &b) const {
            if (a.second != b.second) {
                return a.second > b.second;
            } else {
                return a.first > b.first;
            }
        }
    };

    unordered_map<int, map<pair<int, int>, int>::iterator> IdScore;
    map<pair<int, int>, int, comp> rever;

    Leaderboard() {

    }

    void addScore(int playerId, int score) {
        auto iter = IdScore.find(playerId);
        if (iter == IdScore.end()) {
            pair<int, int> tmp{playerId, score};
            rever.insert({tmp, score});
            IdScore[playerId] = rever.find(tmp);
        } else {
            pair<int, int> tmp{playerId, (iter->second->second) + score};
            rever.erase(iter->second);
            rever.insert({tmp, tmp.second});
            IdScore[playerId] = rever.find(tmp);
        }
    }

    int top(int K) {
        int res = 0;
        for (auto iter = rever.begin(); iter != rever.end() && K > 0; ++iter, --K) {
            res += iter->second;
        }
        return res;
    }

    void reset(int playerId) {
        auto iter = IdScore.find(playerId);
        rever.erase(iter->second);
        IdScore.erase(iter);
    }
//    map<int, int> IdScore;
//
//    Leaderboard() {
//
//    }
//
//    void addScore(int playerId, int score) {
//        auto iter = IdScore.find(playerId);
//        if (iter == IdScore.end()) {
//            IdScore.insert({playerId, score});
//        } else {
//            iter->second += score;
//        }
//    }
//
//    int top(int K) {
//        priority_queue<int, vector<int>, greater<int> > pq;
//        auto iter = IdScore.begin();
//        for (int i = 0; i < K; ++i) {
//            pq.push(iter->second);
//            iter++;
//        }
//        while (iter != IdScore.end()) {
//            int tmp = pq.top();
//            if (tmp < iter->second) {
//                pq.pop();
//                pq.push(iter->second);
//            }
//            iter++;
//        }
//        int res = 0;
//        while (!pq.empty()) {
//            res += pq.top();
//            pq.pop();
//        }
//        return res;
//    }
//
//    void reset(int playerId) {
//        IdScore.erase(playerId);
//    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */

#endif //LEETCODE_1244_LEADERBOARD_H
