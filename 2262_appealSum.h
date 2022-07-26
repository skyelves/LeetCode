//
// Created by 王柯 on 7/25/22.
//

#ifndef LEETCODE_2262_APPEALSUM_H
#define LEETCODE_2262_APPEALSUM_H

#include "solution.h"

class AppealSum : public solution {
public:
    long long appealSum(string s) {
        bool occured[26] = {0};
        int prev[26] = {0};
        long long sum = 0;
        long long newly_sum = 0;
        int len = s.size();
        for (int l = 0; l < len; ++l) {
            if (occured[s[l] - 'a']) {
                newly_sum += (l - prev[s[l] - 'a']);
                sum += newly_sum;
                prev[s[l] - 'a'] = l;
            } else {
                occured[s[l] - 'a'] = true;
                prev[s[l] - 'a'] = l;
                newly_sum += l + 1;
                sum += newly_sum;
            }
        }
        return sum;
    }

    void check() {
        string s = "abb";
        long long res = appealSum(s);
        cout << res << endl;
    }
};

#endif //LEETCODE_2262_APPEALSUM_H
