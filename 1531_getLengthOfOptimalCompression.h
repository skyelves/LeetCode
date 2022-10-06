//
// Created by 王柯 on 10/5/22.
//

#ifndef LEETCODE_1531_GETLENGTHOFOPTIMALCOMPRESSION_H
#define LEETCODE_1531_GETLENGTHOFOPTIMALCOMPRESSION_H

#include "solution.h"

class GetLengthOfOptimalCompression : public solution {
public:
    unordered_map<int, int> mm;

    int generateKey(int idx, char lastChar, int lastCharCnt, int k) {
        return idx * 101 * 101 * 27 + (lastChar - 'a') * 101 * 101 + lastCharCnt * 101 + k;
    }

    int dp(string &s, int idx, char lastChar, int lastCharCnt, int k) {
        // 101, 27, 101, 101
        if (k < 0)
            return INT_MAX;
        if (idx == s.length())
            return 0;
        int res = INT_MAX;
        int key = generateKey(idx, lastChar, lastCharCnt, k);
        auto iter = mm.find(key);
        if (iter != mm.end()) {
            return iter->second;
        }

        int deleteChar = dp(s, idx + 1, lastChar, lastCharCnt, k - 1);
        int keepChar;
        if (s[idx] == lastChar) {
            keepChar = dp(s, idx + 1, lastChar, lastCharCnt + 1, k) + (lastCharCnt == 1) + (lastCharCnt == 9) +
                       (lastCharCnt == 99);
        } else {
            keepChar = dp(s, idx + 1, s[idx], 1, k) + 1;
        }
        res = min(keepChar, deleteChar);
        mm.insert({key, res});

        return res;
    }

    int getLengthOfOptimalCompression(string s, int k) {
        int res = dp(s, 0, 'a' + 26, 0, k);
        return res;
    }

    void check() {
        string s = "aaaaaaaaaaa";
        int k = 0;
        int res = getLengthOfOptimalCompression(s, k);
        cout << res << endl;
    }
};

#endif //LEETCODE_1531_GETLENGTHOFOPTIMALCOMPRESSION_H
