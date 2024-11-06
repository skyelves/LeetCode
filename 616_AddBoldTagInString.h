//
// Created by Ke Wang on 11/5/24.
//

#ifndef INC_616_ADDBOLDTAGINSTRING_H
#define INC_616_ADDBOLDTAGINSTRING_H

#include "solution.h"

class AddBoldTagInString : public solution {
private:
    const string leftTag = "<b>", rightTag = "</b>";
public:
    string addBoldTag(string s, vector<string>& words) {
        int n = s.size(), end = -1;
        vector<bool> wrapped(n, false);
        for (int i = 0; i < n; ++i) {
            for (string &word : words) {
                if (i + (int)word.size() - 1 > end && i + word.size() <= n && word == s.substr(i, word.size())) {
                    for (int j = max(i, end); j < i + word.size(); ++j) {
                        wrapped[j] = true;
                    }
                    end = i + word.size() - 1;
                }
            }
        }
        string res = "";
        bool flag = false;
        for (int i = 0; i < n; ++i) {
            if (wrapped[i]) {
                if (!flag) {
                    res += leftTag;
                }
                flag = true;
            } else {
                if (flag) {
                    res += rightTag;
                }
                flag = false;
            }
            res.push_back(s[i]);
        }
        if (flag) {
            res += rightTag;
        }
        return res;
    }

    void check () {
        string s = "abcxyz123";
        vector<string> words{"abc","123"};
        cout << addBoldTag(s, words) << endl;
    }
};

#endif //INC_616_ADDBOLDTAGINSTRING_H
