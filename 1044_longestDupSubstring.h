//
// Created by 王柯 on 7/29/22.
//

#ifndef LEETCODE_1044_LONGESTDUPSUBSTRING_H
#define LEETCODE_1044_LONGESTDUPSUBSTRING_H

#include "solution.h"

class LongestDupSubstring : public solution {
public:
    int power_num = 23;

    string findStringN(int n, string &s) {
        unsigned long long power_value = 1;
        for (int i = 0; i < n - 1; ++i) {
            power_value *= power_num;
        }
        string res = "";
        int len = s.length();
        unsigned long long hash_value = 0;
        multimap<unsigned long long, int> hashing;
        for (int i = 0; i < n; ++i) {
            hash_value *= power_num;
            hash_value += s[i] - 'a';
        }
        hashing.insert(make_pair(hash_value, n - 1));
        for (int i = n; i < len; ++i) {
            hash_value -= power_value * (s[i - n] - 'a');
            hash_value *= power_num;
            hash_value += s[i] - 'a';
            auto iter = hashing.find(hash_value);
            if (iter != hashing.end()) {
                int cnt = hashing.count(hash_value);
                for (int k = 0; k < cnt; ++k, iter++) {
                    int prev_idx = iter->second;
                    bool flag = true;
                    for (int j = 0; j < n; ++j) {
                        if (s[prev_idx - n + 1 + j] != s[i - n + 1 + j]) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag) {
                        res = s.substr(i - n + 1, n);
                        return res;
                    }
                }
            }
            hashing.insert(make_pair(hash_value, i));
        }
        return res;
    }

    string longestDupSubstring(string s) {
        int len = s.length();
        string res = "";
        int left = 0, right = len;
        while (left < right) {
            int middle = (left + right) / 2;
            string tmp_res = findStringN(middle, s);
            if (tmp_res != "") {
                res = tmp_res;
                left = middle + 1;
            } else {
                right = middle;
            }
        }

        return res;
    }

    void check() {
        string s = "abcabc";
        auto res = longestDupSubstring(s);
        cout << res << endl;
    }
};

#endif //LEETCODE_1044_LONGESTDUPSUBSTRING_H
