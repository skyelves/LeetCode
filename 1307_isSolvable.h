//
// Created by 王柯 on 10/10/22.
//

#ifndef LEETCODE_1307_ISSOLVABLE_H
#define LEETCODE_1307_ISSOLVABLE_H

#include "solution.h"

class IsSolvable : public solution {
public:
    int c2i[26];
    char i2c[10];

    bool dfs(int idx, int digit, int sum, const vector<string> &words, const string &result) {
        if (digit == result.size()) {
            if (sum == 0) {
                if (c2i[result[digit - 1] - 'A'] != 0)
                    return true;
            }
            return false;
        }
        // move to the next digit
        if (idx == words.size()) {
            int tmp = sum % 10;
            if (c2i[result[digit] - 'A'] != -1) {
                if (tmp == c2i[result[digit] - 'A'])
                    return dfs(0, digit + 1, sum / 10, words, result);
            } else if (i2c[tmp] == '\0') {
                // leading digit of result not zero
                if (tmp == 0 && (result.size() - 1 == digit) && result.size() > 1)
                    return false;
                c2i[result[digit] - 'A'] = tmp;
                i2c[tmp] = result[digit];
                bool res = dfs(0, digit + 1, sum / 10, words, result);
                i2c[tmp] = '\0';
                c2i[result[digit] - 'A'] = -1;
                return res;
            }
            return false;
        }
        // current digit larger than words.length()
        if (digit >= words[idx].size())
            return dfs(idx + 1, digit, sum, words, result);
        // current char already been assigned
        if (c2i[words[idx][digit] - 'A'] != -1) {
            if (c2i[words[idx][digit] - 'A'] != 0 ||
                digit != (words[idx].size() - 1) ||
                words[idx].size() == 1)
                return dfs(idx + 1, digit, sum + c2i[words[idx][digit] - 'A'], words, result);
            else
                return false;
        }
        for (int i = 0; i < 10; ++i) {
            if (i2c[i] != '\0') continue;
            if (i == 0 && digit == (words[idx].size() - 1) && words[idx].size() > 1) continue;
            i2c[i] = words[idx][digit];
            c2i[words[idx][digit] - 'A'] = i;
            bool res = dfs(idx + 1, digit, sum + i, words, result);
            c2i[words[idx][digit] - 'A'] = -1;
            i2c[i] = '\0';
            if (res)
                return true;
        }
        return false;
    }

    bool isSolvable(vector<string> &words, string result) {
        for (auto &word : words) {
            if (word.size() > result.size())
                return false;
        }
        memset(c2i, -1, sizeof(c2i));
        memset(i2c, '\0', sizeof(i2c));
        for (auto &i : words) {
            reverse(i.begin(), i.end());
        }
        reverse(result.begin(), result.end());
        return dfs(0, 0, 0, words, result);
    }

    void check() {
        vector<string> words{"A", "A"};
        string result = "AA";
        bool res = isSolvable(words, result);
        cout << res << endl;
    }
};

#endif //LEETCODE_1307_ISSOLVABLE_H
