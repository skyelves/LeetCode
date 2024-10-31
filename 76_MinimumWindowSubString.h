//
// Created by Ke Wang on 10/30/24.
//

#ifndef INC_76_MINIMUMWINDOWSUBSTRING_H
#define INC_76_MINIMUMWINDOWSUBSTRING_H

#include "solution.h"

class MinimumWindowSubString : public solution {
public:
    bool isContain(unordered_map<char, int>&tMap) {
        for (auto &tmp: tMap) {
            if (tmp.second > 0) {
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        string res = "";
        int minLen = INT32_MAX;
        unordered_map<char, int> tMap;
        for (char c : t) {
            ++tMap[c];
        }
        int i = 0, j = 0;
        while (j < s.size()) {
            while (j < s.size() && !isContain(tMap)) {
                auto iter = tMap.find(s[j]);
                ++j;
                if (iter != tMap.end()) {
                    --iter->second;
                }
            }
            while (i < j && isContain(tMap)) {
                auto iter = tMap.find(s[i]);
                ++i;
                if (iter != tMap.end()) {
                    ++iter->second;
                    if (iter->second > 0) {
                        if (j - i + 1 < minLen) {
                            minLen = j - i + 1;
                            res = s.substr(i - 1, j - i + 1);
                        }
                        break;
                    }
                }
            }
        }

        return res;
    }
};

#endif //INC_76_MINIMUMWINDOWSUBSTRING_H
