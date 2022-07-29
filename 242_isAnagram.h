//
// Created by 王柯 on 7/28/22.
//

#ifndef LEETCODE_242_ISANAGRAM_H
#define LEETCODE_242_ISANAGRAM_H

#include "solution.h"

class IsAnagram : public solution {
public:
    bool isAnagram(string s, string t) {
        int len1 = s.length();
        int len2 = t.length();
        cout << len1 << " " << len2 << endl;
        if (len1 != len2)
            return false;
        for (int i = 0; i < 26; ++i) {
            int tmp1 = count(s.begin(), s.end(), 'a' + i);
            int tmp2 = count(t.begin(), t.end(), 'a' + i);
            if (tmp1 != tmp2)
                return false;
        }
        return true;
    }

    void check() {
        string s = "ab", t = "ab";
        bool res = isAnagram(s, t);
        cout << res << endl;
    }
};

#endif //LEETCODE_242_ISANAGRAM_H
