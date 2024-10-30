//
// Created by Ke Wang on 10/30/24.
//

#ifndef INC_2060_CHECKIFANORIGINALSTRINGEXISTSGIVENTWOENCODEDSTRINGS_H
#define INC_2060_CHECKIFANORIGINALSTRINGEXISTSGIVENTWOENCODEDSTRINGS_H

#include "solution.h"

class CheckIfAnOriginalStringExists : public solution {
    bool visited[41][41][10000] = {0};
public:
    bool possiblyEquals(string s1, string s2) {
        return dfs(s1, s2, 0, 0, 0);
    }

    bool dfs(string &s1, string &s2, int x, int y, int diff) {
        if (x == s1.size() && y == s2.size()) {
            return diff == 0;
        }
        if (visited[x][y][diff + 5000]) {
            return false;
        }
        visited[x][y][diff + 5000] = true;

        if (x < s1.size() && isDigit(s1[x])) {
            int val = 0;
            for (int i = x; i < s1.size() && isDigit(s1[i]); ++i) {
                val *= 10;
                val += s1[i] - '0';
                if (dfs(s1, s2, i + 1, y, diff + val)) {
                    return true;
                }
            }
            return false;
        }

        if (y < s2.size() && isDigit(s2[y])) {
            int val = 0;
            for (int i = y; i < s2.size() && isDigit(s2[i]); ++i) {
                val *= 10;
                val += s2[i] - '0';
                if (dfs(s1, s2, x, i + 1, diff - val)) {
                    return true;
                }
            }
            return false;
        }

        bool res;
        if (diff > 0) {
            res = y < s2.size() && dfs(s1, s2, x, y + 1, diff - 1);
        } else if (diff < 0) {
            res = x < s1.size() && dfs(s1, s2, x + 1, y, diff + 1);
        } else {
            res = x < s1.size() && y < s2.size() && s1[x] == s2[y] && dfs(s1, s2, x + 1, y + 1, diff);
        }

        return res;
    }

    inline bool isDigit(char c) {
        return c >= '0' && c <= '9';
    }

    void check () {
        string s1 = "internationalization", s2 = "i18n";
        cout << possiblyEquals(s1, s2) << endl;
    }
};

#endif //INC_2060_CHECKIFANORIGINALSTRINGEXISTSGIVENTWOENCODEDSTRINGS_H
