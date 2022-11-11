//
// Created by 王柯 on 11/11/22.
//

#ifndef LEETCODE_1366_RANKTEAMS_H
#define LEETCODE_1366_RANKTEAMS_H

#include "solution.h"

class RankTeams : public solution {
public:
    string rankTeams(vector<string> &votes) {
        string res;
        bitset<26> used(false);
        vector<vector<int>> score(26, vector<int>(26, 0));
        for (auto &vote : votes) {
            for (int i = 0; i < vote.size(); ++i) {
                ++score[vote[i] - 'A'][i];
                used[vote[i] - 'A'] = true;
            }
        }
        vector<pair<char, vector<int>>> toSort;
        for (int i = 0; i < 26; ++i) {
            toSort.push_back({'A' + i, score[i]});
        }
        sort(toSort.begin(), toSort.end(), [](const pair<char, vector<int>> &a, const pair<char, vector<int>> &b) {
            if (a.second != b.second) {
                return a.second > b.second;
            }
            return a.first < b.first;
        });
        for (int i = 0; i < 26; ++i) {
            if (used[toSort[i].first - 'A'])
                res += toSort[i].first;
        }

        return res;
    }

    void check() {
        vector<string> votes{"ABC", "ACB", "ABC", "ACB", "ACB"};
        string res = rankTeams(votes);
        cout << res << endl;
    }
};

#endif //LEETCODE_1366_RANKTEAMS_H
