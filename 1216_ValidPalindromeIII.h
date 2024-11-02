//
// Created by Admin on 10/10/2024.
//

#ifndef LEETCODE_1216_VALIDPALINDROMEIII_H
#define LEETCODE_1216_VALIDPALINDROMEIII_H

#include "solution.h"

class ValidPalindromeIII : public solution {
public:
    bool isValidPalindrome(string s, int k) {
        int n = s.size();
        vector<vector<int>> remove(n, vector<int>(n, -1));
        return dfs(0, n - 1, s, remove) <= k;
    }

    int dfs(int x, int y, string &s, vector<vector<int>> &remove) {
        int i = x, j = y;
        if (i >= j) {
            return 0;
        }
        if (remove[i][j] != -1) {
            return remove[i][j];
        }
        while (i < j) {
            if (s[i] == s[j]) {
                ++i;
                --j;
            } else {
                int removeLeft = dfs(i + 1, j, s, remove) + 1;
                int removeRight = dfs(i, j - 1, s, remove) + 1;
                remove[x][y] = min(removeLeft, removeRight);
                return remove[x][y];
            }
        }
        remove[x][y] = 0;
        return 0;
    }

    void check() {
        string s = "abbababa";
        int k = 1;
        cout << isValidPalindrome(s, k) << endl;
    }
};

#endif //LEETCODE_1216_VALIDPALINDROMEIII_H
