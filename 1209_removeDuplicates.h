//
// Created by 王柯 on 9/13/22.
//

#ifndef LEETCODE_1209_REMOVEDUPLICATES_H
#define LEETCODE_1209_REMOVEDUPLICATES_H

#include "solution.h"

class RemoveDuplicates : public solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int> > ss;
        int cnt = 0;
        int len = s.size();
        for (int i = 0; i < len; ++i) {
            if (!ss.empty()) {
                auto last = ss.top();
                if (last.first == s[i]) {
                    ss.pop();
                    last.second++;
                } else {
                    last = {s[i], 1};
                }
                if (last.second < k) {
                    ss.push(last);
                }
            } else {
                ss.push({s[i], 1});
            }
        }
        string res;
        while (!ss.empty()) {
            auto tmp = ss.top();
            ss.pop();
            string tmp_ss(tmp.second, tmp.first);
            res += tmp_ss;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    void check() {
        string s = "pbbcggttciiippooaais";
        int k = 2;
        string res = removeDuplicates(s, k);
        cout << res << endl;
    }
};

#endif //LEETCODE_1209_REMOVEDUPLICATES_H
