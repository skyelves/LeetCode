//
// Created by 王柯 on 12/6/22.
//

#ifndef LEETCODE_996_NUMSQUAREFULPERMS_H
#define LEETCODE_996_NUMSQUAREFULPERMS_H

#include "solution.h"

class NumSquarefulPerms : public solution {
public:
    inline bool isSquare(int n) {
        int sq = sqrt(n);
        return n == sq * sq;
    }

    int dfs(vector<int> &tmp, map<int, int> &mm, set<vector<int>> &ss, int n) {
        if (ss.find(tmp) != ss.end())
            return 0;
        if (tmp.size() == n)
            return 1;
        int res = 0;
        ss.insert(tmp);
        for (auto &i : mm) {
            if (i.second != 0 && isSquare(tmp.back() + i.first)) {
                tmp.push_back(i.first);
                --mm[i.first];
                res += dfs(tmp, mm, ss, n);
                tmp.pop_back();
                ++mm[i.first];
            }
        }
        return res;
    }

    int numSquarefulPerms(vector<int> &nums) {
        int res = 0;
        map<int, int> mm;
        set<vector<int>> ss;
        for (auto &i : nums) {
            ++mm[i];
        }
        for (auto &i : mm) {
            vector<int> tmp{i.first};
            --mm[i.first];
            res += dfs(tmp, mm, ss, nums.size());
            ++mm[i.first];
        }

        return res;
    }

    void check() {
        vector<int> nums{1, 17, 8};
        int res = numSquarefulPerms(nums);
        cout << res << endl;
    }
};

#endif //LEETCODE_996_NUMSQUAREFULPERMS_H
