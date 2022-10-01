//
// Created by 王柯 on 10/1/22.
//

#ifndef LEETCODE_394_DECODESTRING_H
#define LEETCODE_394_DECODESTRING_H

#include "solution.h"

class DecodeString : public solution {
public:
    string recur(string &s, int &i) {
        string res;
        int len = s.size();
        while (i < len) {
            int tmpNum = 0;
            while (s[i] >= '0' && s[i] <= '9') {
                tmpNum = tmpNum * 10 + s[i] - '0';
                i++;
            }
            if (s[i] == '[') {
                i++;
                string tmp = recur(s, i);
                for (int j = 0; j < tmpNum; ++j) {
                    res += tmp;
                }
            } else if (s[i] == ']') {
                break;
            } else {
                res += s[i];
            }
            i++;
        }
        return res;
    }

    string decodeString(string s) {
        int i = 0;
        string res = recur(s, i);
        return res;
    }

    void check() {
        string s = "2[abc]3[cd]ef";
        string res = decodeString(s);
        cout << res << endl;
    }
};

#endif //LEETCODE_394_DECODESTRING_H
