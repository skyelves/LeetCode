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
        int res = 0;
        vector<int> visited(256, -1);
        int i = 0, j = 0;
        for (i = 0; i < len; ++i) {
            if (visited[s[i]] != -1) {
                j = max(j, visited[s[i]] + 1);
            }
            res = max(res, i - j + 1);
            visited[s[i]] = i;
        }
        return res;
    }

    void check() {
        string s = "abcabcbb";
        int res = lengthOfLongestSubstring(s);
        cout << res << endl;
    }
};

#endif //LEETCODE_3_LENGTHOFLONGESTSUBSTRING_H
