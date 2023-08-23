//
// Created by 王柯 on 8/22/23.
//

#ifndef LEETCODE_767_REORGANIZESTRING_H
#define LEETCODE_767_REORGANIZESTRING_H

#endif //LEETCODE_767_REORGANIZESTRING_H

#include "solution.h"

class ReorganizeString : public solution {
public:
    string reorganizeString(string s) {
        string res = "";
        int len = s.size();
        int charCnt[26] = {0};
        for (auto &i : s) {
            ++charCnt[i-'a'];
        }
        int last = -1;
        for (int i = 0; i < len; ++i) {
            int tmpMax = 0, tmpIdx = -1;
            for (int j = 0; j < 26; ++j) {
                if (j == last || charCnt[j] == 0) continue;
                if (charCnt[j] > tmpMax) {
                    tmpIdx = j;
                    tmpMax = charCnt[j];
                }
            }
            if (tmpIdx != -1) {
                res.push_back('a' + tmpIdx);
                --charCnt[tmpIdx];
                last = tmpIdx;
            } else {
                return "";
            }
        }
        return res;
    }

    void check() {
        cout << reorganizeString("aaab") << endl;
    }
};
