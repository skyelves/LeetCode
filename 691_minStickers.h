//
// Created by 王柯 on 8/25/22.
//

#ifndef LEETCODE_691_MINSTICKERS_H
#define LEETCODE_691_MINSTICKERS_H

#include "solution.h"

class MinStickers : public solution {
public:
    unordered_map<string, int> minCnt;
    vector<unordered_set<string>> reverseMap;

    int minStickers(vector<string>& stickers, string target) {
        reverseMap.resize(26);
        for (int i = 0; i < stickers.size(); ++i) {
            sort(stickers[i].begin(), stickers[i].end());
            for (int j = 0; j < stickers[i].size(); ++j) {
                reverseMap[stickers[i][j] - 'a'].insert(stickers[i]);
            }
        }
        sort(target.begin(), target.end());
        return dfs(target);
    }

    int dfs(string target) {
        if (target.empty()) {
            return 0;
        }
        if (minCnt.find(target) != minCnt.end()) {
            return minCnt[target];
        }
        int res = INT32_MAX;
        for (int i = 0; i < target.size(); ++i) {
            if (reverseMap[target[i] - 'a'].empty()) {
                minCnt[target] = -1;
                return -1;
            }
            for (const string &sticker : reverseMap[target[i] - 'a']) {
                string newTarget = deduct(target, sticker);
                res = min(res, dfs(newTarget));
            }
        }

        if (res == INT32_MAX) {
            minCnt[target] = -1;
            return -1;
        }
        ++res;
        minCnt[target] = res;
        return res;
    }

    string deduct(string &target, const string &sticker) {
        string res;
        int i = 0, j = 0;
        while(i < target.size() && j < sticker.size()) {
            if (target[i] == sticker[j]) {
                ++i;
                ++j;
            } else if (target[i] < sticker[j]) {
                res.push_back(target[i]);
                ++i;
            } else {
                ++j;
            }
        }
        while(i < target.size()) {
            res.push_back(target[i]);
            ++i;
        }
        return res;
    }

    void check() {
        vector<string> stickers{"notice","possible"};
        string target = "basicbasic";
        int res = minStickers(stickers, target);
        cout << res << endl;
    }

};

#endif //LEETCODE_691_MINSTICKERS_H
