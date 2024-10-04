//
// Created by Admin on 10/3/2024.
//

#ifndef LEETCODE_340_LONGESTSUBSTRRING_H
#define LEETCODE_340_LONGESTSUBSTRRING_H

#include "solution.h"

class LongestSubstring : public solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (k == 0) {
            return 0;
        }
        int res = 0, tmpRes = 0;
        int distinct = 0;
        map<char, int> charCnt;
        for (int i = 0, j = 0; j < s.length(); ++j) {
            if (charCnt[s[j]] == 0) {
                ++distinct;
                ++charCnt[s[j]];
                if (distinct > k) {
                    res = max(res, tmpRes);
                    while(i < j) {
                        --tmpRes;
                        --charCnt[s[i]];
                        if (charCnt[s[i]] == 0) {
                            ++i;
                            --distinct;
                            break;
                        } else {
                        ++i;
                        }
                    }
                }
            } else {
                ++charCnt[s[j]];
            }
            ++tmpRes;
        }
        res = max(res, tmpRes);
        return res;
    }

    void check() {
        string s = "abee";
        int k = 1;
        cout << lengthOfLongestSubstringKDistinct(s, k) << endl;
    }
};

#endif //LEETCODE_340_LONGESTSUBSTRRING_H
