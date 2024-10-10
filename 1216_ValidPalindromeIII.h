//
// Created by Admin on 10/10/2024.
//

#ifndef LEETCODE_1216_VALIDPALINDROMEIII_H
#define LEETCODE_1216_VALIDPALINDROMEIII_H

#include "solution.h"

class ValidPalindromeIII : public solution {
public:
    bool isValidPalindrome(string s, int k) {
        vector<vector<int>> deleteCnt(s.size() + 1, vector<int>(s.size() + 1, -1));
        return dfs(s, 0, s.size() - 1, deleteCnt) <= k;
    }

    int dfs(string &s, int start, int end, vector<vector<int>> &deletCnt) {
        if (start >= end) {
            return 0;
        }
        if (deletCnt[start][end] != -1) {
            return deletCnt[start][end];
        }
        if (s[start] == s[end]) {
            deletCnt[start][end] = dfs(s, start + 1, end - 1, deletCnt);
        } else {
            deletCnt[start][end] = min(dfs(s, start + 1, end, deletCnt), dfs(s, start, end - 1, deletCnt)) + 1;
        }
        return deletCnt[start][end];
    }

    void check() {
        string s = "abbababa";
        int k = 1;
        cout << isValidPalindrome(s, k) << endl;
    }
};

#endif //LEETCODE_1216_VALIDPALINDROMEIII_H
