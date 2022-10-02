//
// Created by 王柯 on 7/20/22.
//

#ifndef LEETCODE_316_REMOVEDUPLICATELETTERS_H
#define LEETCODE_316_REMOVEDUPLICATELETTERS_H

#include "solution.h"

class RemoveDuplicateLetters : public solution {
public:
    string removeDuplicateLetters(string s) {
        string res = "";
        set<char> flag;
        int len = s.size();
        for (int i = 0; i < len; ++i) {
            int res_len = res.size();
            if (res_len > 0) {
                if (res.find(s[i]) != string::npos)
                    continue; // exist
                for (int j = res_len - 1; j >= 0; --j) {
                    if (res[j] > s[i] && s.find(res[j], i) != string::npos) {
                        // delete the letter
                        res.pop_back();
                    } else {
                        break;
                    }
                }
                res += s[i];
            } else {
                res += s[i];
            }
        }
        return res;
    }

    void check() {
        string s = "abacb"; // abc
//        string s = "cbacdcbc"; //acdb
//        string s = "bcab"; // bca
//        string s = "bcabc"; // abc
        string res = removeDuplicateLetters(s);
        cout << res << endl;
    }
};

#endif //LEETCODE_316_REMOVEDUPLICATELETTERS_H
