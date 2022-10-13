//
// Created by 王柯 on 10/13/22.
//

#ifndef LEETCODE_1153_CANCONVERT_H
#define LEETCODE_1153_CANCONVERT_H

#include "solution.h"

class CanConvert : public solution {
public:
    bool canConvert(string str1, string str2) {
        if (str1 == str2)
            return true;
        int c2c[27] = {-1}, cnt = 0;
        memset(c2c, -1, sizeof(c2c));
        int len = str1.size();
        for (int i = 0; i < len; ++i) {
            if (c2c[str1[i] - 'a'] == -1) {
                c2c[str1[i] - 'a'] = str2[i] - 'a';
            } else {
                if (c2c[str1[i] - 'a'] == str2[i] - 'a')
                    continue;
                else
                    return false;
            }
        }
        bool visited[26] = {0};
        for (int i = 0; i < len; ++i) {
            if (!visited[str2[i] - 'a']) {
                ++cnt;
                visited[str2[i] - 'a'] = true;
            }
        }
        if (cnt == 26)
            return false;
        else
            return true;
    }

    void check() {
        string str1 = "ab", str2 = "ba";
        bool res = canConvert(str1, str2);
        cout << res << endl;
    }
};

#endif //LEETCODE_1153_CANCONVERT_H
