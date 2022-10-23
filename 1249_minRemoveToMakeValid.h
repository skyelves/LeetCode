//
// Created by 王柯 on 10/23/22.
//

#ifndef LEETCODE_1249_MINREMOVETOMAKEVALID_H
#define LEETCODE_1249_MINREMOVETOMAKEVALID_H

#include "solution.h"

class MinRemoveToMakeValid : public solution {
public:
    string minRemoveToMakeValid(string s) {
        int cnt = 0;
        string res;
        vector<bool> remove(s.size(), false);
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                ++cnt;
            } else if (s[i] == ')') {
                if (cnt > 0) {
                    --cnt;
                } else {
                    remove[i] = true;
                }
            }
        }
        cnt = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == ')') {
                ++cnt;
            } else if (s[i] == '(') {
                if (cnt > 0) {
                    --cnt;
                } else {
                    remove[i] = true;
                }
            }
        }
        for (int i = 0; i < s.size(); ++i) {
            if (!remove[i]) {
                res += s[i];
            }
        }
        return res;
    }

    void check() {

    }
};

#endif //LEETCODE_1249_MINREMOVETOMAKEVALID_H
