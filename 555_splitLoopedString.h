//
// Created by 王柯 on 10/13/22.
//

#ifndef LEETCODE_555_SPLITLOOPEDSTRING_H
#define LEETCODE_555_SPLITLOOPEDSTRING_H

#include "solution.h"

class SplitLoopedString : public solution {
public:
    string splitLoopedString(vector<string> &strs) {
        string totalStr;
        for (auto &str : strs) {
            string tmp = string(str.rbegin(), str.rend());
            str = max(tmp, str);
            totalStr += str;
        }
        string res = totalStr;
        int len = totalStr.size();
        for (int i = 0, stridx = 0, l = 0; i < len; i += l, ++stridx) {
            l = strs[stridx].size();
            for (int j = 0; j < l; ++j) {
                string currStr = string(strs[stridx].rbegin(), strs[stridx].rend());
                string tmp =
                        currStr.substr(j, l - j) + totalStr.substr(i + l, len - i - l) + totalStr.substr(0, i) +
                        currStr.substr(0, j);
                res = max(res, tmp);
                res = max(res, totalStr.substr(i + j, len - i - j) + totalStr.substr(0, i + j));
            }
        }
        return res;
    }

    void check() {
        vector<string> strs{"awe", "zzzdcasf", "awefawz", "awefawfae", "awefaw", "ewaee"};
        string res = splitLoopedString(strs);
        cout << res << endl;
    }
};

#endif //LEETCODE_555_SPLITLOOPEDSTRING_H
