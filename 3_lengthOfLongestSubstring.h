//
// Created by 王柯 on 8/10/22.
//

#ifndef LEETCODE_3_LENGTHOFLONGESTSUBSTRING_H
#define LEETCODE_3_LENGTHOFLONGESTSUBSTRING_H

#include "solution.h"

class LengthOfLongestSubstring : public solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        int res = 0, currLen = 0;
        vector<int> visited(256, -1);
        for (int i = 0; i < len; ++i) {
            if (visited[s[i]] == -1) {
                ++currLen;
            } else {
                res = max(res, currLen);
                currLen = min(currLen + 1, i - visited[s[i]]);
            }
            visited[s[i]] = i;
        }
        res = max(res, currLen);
        return res;
    }

    void check() {
        string s = "abcabcbb";
        int res = lengthOfLongestSubstring(s);
        cout << res << endl;
    }
};

#endif //LEETCODE_3_LENGTHOFLONGESTSUBSTRING_H
