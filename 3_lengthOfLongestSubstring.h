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
        for (int i = 0; i < len; ++i) {
            int j = 0;
            bool visited[256] = {false};
//            memset(visited, false, sizeof(visited));
            while (i + j < len) {
                char tmp = s[i+j];
                if (!visited[tmp]) {
                    j++;
                    visited[tmp] = true;
                } else {
                    res = max(res, j);
                    break;
                }
            }
            if (i + j == len) {
                res = max(res, j);
            }
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
