//
// Created by 王柯 on 9/14/22.
//

#ifndef LEETCODE_49_GROUPANAGRAMS_H
#define LEETCODE_49_GROUPANAGRAMS_H

#include "solution.h"

class GroupAnagrams : public solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        vector<vector<string>> res;
        map<vector<int>, vector<string> > mm;
        for (int i = 0; i < strs.size(); ++i) {
            vector<int> cnt(26, 0);
            string tmp = strs[i];
            for (int j = 0; j < tmp.size(); ++j) {
                cnt[tmp[j] - 'a']++;
            }
            auto iter = mm.find(cnt);
            if (iter != mm.end()) {
                iter->second.push_back(tmp);
            } else {
                vector<string> new_kind{tmp};
                mm.insert({cnt, new_kind});
            }
        }
        for (auto i : mm) {
            res.push_back(i.second);
        }
        return res;
    }

    void check() {

    }
};

#endif //LEETCODE_49_GROUPANAGRAMS_H
