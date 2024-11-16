//
// Created by 王柯 on 10/23/22.
//

#ifndef LEETCODE_1249_MINREMOVETOMAKEVALID_H
#define LEETCODE_1249_MINREMOVETOMAKEVALID_H

#include "solution.h"

class MinRemoveToMakeValid : public solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        vector<bool> removed(n, false);
        stack<int> ss;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                ss.push(i);
            } else if (s[i] == ')') {
                if (!ss.empty()) {
                    ss.pop();
                } else {
                    removed[i] = true;
                }
            }
        }
        while(!ss.empty()) {
            removed[ss.top()] = true;
            ss.pop();
        }
        string res = "";
        for (int i = 0; i < n; ++i) {
            if (!removed[i]) {
                res.push_back(s[i]);
            }
        }
        return res;
    }

    void check() {

    }
};

#endif //LEETCODE_1249_MINREMOVETOMAKEVALID_H
