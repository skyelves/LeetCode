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
        vector<int> sorted;
        for (auto i : IdScore) {
            sorted.push_back(i.second);
        }
        sort(sorted.begin(), sorted.end(), [](int &a, int &b){return a > b;});
        int res = 0;
        for (int i = 0; i < K; ++i) {
            res += sorted[i];
        }
        return res;
    }

    void reset(int playerId) {
        IdScore[playerId] = 0;
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
