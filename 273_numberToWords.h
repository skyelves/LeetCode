//
// Created by 王柯 on 12/8/22.
//

#ifndef LEETCODE_273_NUMBERTOWORDS_H
#define LEETCODE_273_NUMBERTOWORDS_H

#include "solution.h"

class NumberToWords : public solution {
public:
    unordered_map<int, string> one{
            {0,  ""},
            {1,  "One"},
            {2,  "Two"},
            {3,  "Three"},
            {4,  "Four"},
            {5,  "Five"},
            {6,  "Six"},
            {7,  "Seven"},
            {8,  "Eight"},
            {9,  "Nine"},
            {10, "Ten"},
            {11, "Eleven"},
            {12, "Twelve"},
            {13, "Thirteen"},
            {14, "Fourteen"},
            {15, "Fifteen"},
            {16, "Sixteen"},
            {17, "Seventeen"},
            {18, "Eighteen"},
            {19, "Nineteen"}};
    unordered_map<int, string> two{
            {2, "Twenty"},
            {3, "Thirty"},
            {4, "Forty"},
            {5, "Fifty"},
            {6, "Sixty"},
            {7, "Seventy"},
            {8, "Eighty"},
            {9, "Ninety"}};
    unordered_map<int, string> mm{{0, ""},
                                  {1, " Thousand"},
                                  {2, " Million"},
                                  {3, " Billion"}};

    string threeNumToWords(int num) {
        if (num >= 100) {
            int hundreds = num / 100;
            num %= 100;
            string res = one[hundreds] + " Hundred";
            if (num > 0)
                res += " " + threeNumToWords(num % 100);
            return res;
        } else if (num < 20) {
            return one[num];
        } else {
            int tens = num / 10;
            return num % 10 != 0 ? two[tens] + " " + one[num % 10] : two[tens];
        }
    }

    string numberToWords(int num) {
        if (num == 0)
            return "Zero";
        string res;
        int cnt = 0;
        while (num > 0) {
            if (num % 1000 > 0)
                res = res.length() > 0 ? threeNumToWords(num % 1000) + mm[cnt] + " " + res :
                      threeNumToWords(num % 1000) + mm[cnt];
            num /= 1000;
            ++cnt;
        }

        return res;
    }

    void check() {
        string res = numberToWords(1000000);
        cout << res << endl;
    }
};

#endif //LEETCODE_273_NUMBERTOWORDS_H
