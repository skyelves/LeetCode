//
// Created by 王柯 on 7/29/22.
//

#ifndef LEETCODE_890_FINDANDREPLACEPATTERN_H
#define LEETCODE_890_FINDANDREPLACEPATTERN_H

#include "solution.h"

class FindAndReplacePattern : public solution {
public:
    vector<string> findAndReplacePattern(vector<string> &words, string pattern) {
        vector<string> res;
        int len = pattern.length();
        for (auto word : words) {
            map<char, char> mm;
            bool used[26] = {false};
            bool flag = true;
            for (int i = 0; i < len; ++i) {
                if (mm.find(word[i]) == mm.end()) {
                    if (used[pattern[i] - 'a']) {
                        flag = false;
                        break;
                    }
                    used[pattern[i] - 'a'] = true;
                    mm[word[i]] = pattern[i];
                } else {
                    if (mm[word[i]] != pattern[i]) {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag)
                res.push_back(word);
        }
        return res;
    }

    void check() {
        vector<string> words{"abc", "deq", "mee", "aqq", "dkd", "ccc"};
        string pattern = "abb";
        auto res = findAndReplacePattern(words, pattern);
        for (auto i : res) {
            cout << i << endl;
        }
    }
};

#endif //LEETCODE_890_FINDANDREPLACEPATTERN_H
