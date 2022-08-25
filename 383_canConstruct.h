//
// Created by 王柯 on 8/25/22.
//

#ifndef LEETCODE_383_CANCONSTRUCT_H
#define LEETCODE_383_CANCONSTRUCT_H

#include "solution.h"

class CanConstruct : public solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int dic[26] = {0};
        for (auto i : magazine) {
            dic[i - 'a']++;
        }
        for (auto i : ransomNote) {
            dic[i - 'a']--;
            if (dic[i - 'a'] < 0)
                return false;
        }
        return true;
    }

    void check() {
        string ransomNote = "aaab", magazine = "aaba";
        bool res = canConstruct(ransomNote, magazine);
        cout << res << endl;
    }
};

#endif //LEETCODE_383_CANCONSTRUCT_H
