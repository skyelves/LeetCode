//
// Created by 王柯 on 11/14/22.
//

#ifndef LEETCODE_443_STRINGCOMPRESSION_H
#define LEETCODE_443_STRINGCOMPRESSION_H

#include "solution.h"

class StringCompression : public solution {
public:
    void int2Str(int cnt, int &res, vector<char> &chars) {
        vector<char> tmp;
        if (cnt <= 1)
            return;
        while (cnt > 0) {
            tmp.push_back('0' + (cnt % 10));
            cnt /= 10;
        }
        for (int i = tmp.size() - 1; i >= 0; --i) {
            chars[res++] = tmp[i];
        }
    }

    int compress(vector<char> &chars) {
        int res = 0, len = chars.size();
        int cnt = 0;
        char lastChar = '\0';
        for (int i = 0; i < len; ++i) {
            if (chars[i] != lastChar) {
                int2Str(cnt, res, chars);
                cnt = 1;
                chars[res] = chars[i];
                lastChar = chars[i];
                ++res;
            } else {
                ++cnt;
            }
        }
        int2Str(cnt, res, chars);
        chars.resize(res);
        return res;
    }

    void check() {

    }
};

#endif //LEETCODE_443_STRINGCOMPRESSION_H
