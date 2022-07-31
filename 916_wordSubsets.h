//
// Created by 王柯 on 7/30/22.
//

#ifndef LEETCODE_916_WORDSUBSETS_H
#define LEETCODE_916_WORDSUBSETS_H

#include "solution.h"

class WordSubsets : public solution {
public:
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2) {
        vector<string> res;
        int words2_cnt[26] = {0};
        for (auto word : words2) {
            int tmp_cnt[26] = {0};
            for (auto letter : word) {
                tmp_cnt[letter - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                if (tmp_cnt[i] > words2_cnt[i]) {
                    words2_cnt[i] = tmp_cnt[i];
                }
            }
        }
        for (auto word: words1) {
            int tmp_cnt[26] = {0};
            for (auto letter : word) {
                tmp_cnt[letter - 'a']++;
            }
            bool flag = true;
            for (int i = 0; i < 26; i++) {
                if (tmp_cnt[i] < words2_cnt[i]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                res.push_back(word);
            }
        }
        return res;
    }

    void check() {

    }
};

#endif //LEETCODE_916_WORDSUBSETS_H
