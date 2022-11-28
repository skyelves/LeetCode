//
// Created by 王柯 on 11/27/22.
//

#ifndef LEETCODE_1702_MAXIMUMBINARYSTRING_H
#define LEETCODE_1702_MAXIMUMBINARYSTRING_H

#include "solution.h"

class MaximumBinaryString : public solution {
public:
    string maximumBinaryString(string binary) {
        int firstZero = binary.find('0');
        int oneCnt = 0;
        for (int j = firstZero; j < binary.size(); ++j) {
            if (binary[j] == '1') {
                binary[j] = '0';
                ++oneCnt;
            }
        }
        for (int i = binary.size() - 1; i >= binary.size() - oneCnt; --i) {
            binary[i] = '1';
        }
        for (int i = firstZero; i < binary.size() - oneCnt - 1; ++i) {
            binary[i] = '1';
        }

        return binary;
    }

    void check() {
        string binary = "01111001100000110010";
        auto res = maximumBinaryString(binary);
        cout << res << endl;
    }
};

#endif //LEETCODE_1702_MAXIMUMBINARYSTRING_H
