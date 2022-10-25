//
// Created by 王柯 on 10/25/22.
//

#ifndef LEETCODE_38_COUNTANDSAY_H
#define LEETCODE_38_COUNTANDSAY_H

#include "solution.h"

class CountAndSay : public solution {
public:
    string countAndSay(int n) {
        if (n == 1)
            return "1";
        string prev = countAndSay(n - 1);
        char curr = 'a';
        int cnt = 1;
        string res;
        for (auto &c : prev) {
            if (c == curr) {
                ++cnt;
            } else if (curr != 'a') {
                res += to_string(cnt) + curr;
                curr = c;
                cnt = 1;
            } else {
                curr = c;
                cnt = 1;
            }
        }
        res += to_string(cnt) + curr;
        return res;
    }

    void check() {
        int n = 30;
        string res = countAndSay(n);
        cout << res << endl;
    }
};

#endif //LEETCODE_38_COUNTANDSAY_H
