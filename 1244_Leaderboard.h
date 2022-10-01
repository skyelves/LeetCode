//
// Created by 王柯 on 10/1/22.
//

#ifndef LEETCODE_1244_LEADERBOARD_H
#define LEETCODE_1244_LEADERBOARD_H

#include "solution.h"

class Leaderboard {
public:
    map<int, int> IdScore;

    Leaderboard() {

    }

    void addScore(int playerId, int score) {
        auto iter = IdScore.find(playerId);
        if (iter == IdScore.end()) {
            IdScore.insert({playerId, score});
        } else {
            iter->second += score;
        }
    }

    int top(int K) {
        priority_queue<int, vector<int>, greater<int> > pq;
        auto iter = IdScore.begin();
        for (int i = 0; i < K; ++i) {
            pq.push(iter->second);
            iter++;
        }
        while (iter != IdScore.end()) {
            int tmp = pq.top();
            if (tmp < iter->second) {
                pq.pop();
                pq.push(iter->second);
            }
            iter++;
        }
        int res = 0;
        while (!pq.empty()) {
            res += pq.top();
            pq.pop();
        }
        return res;
    }

    void reset(int playerId) {
        IdScore.erase(playerId);
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */

#endif //LEETCODE_1244_LEADERBOARD_H
