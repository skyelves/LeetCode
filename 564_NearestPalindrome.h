//
// Created by Admin on 8/24/2024.
//

#ifndef LEETCODE_564_NEARESTPALINDROME_H
#define LEETCODE_564_NEARESTPALINDROME_H

#include "solution.h"

class NearestPalindromic : public solution {
private:
    string res = "99999999999999999999999999";
    string minDiff = "99999999999999999999999999";

    map<char, vector<char>> mm{
            {'0', {'9', '0', '1'}},
            {'1', {'0', '1', '2'}},
            {'2', {'1', '2', '3'}},
            {'3', {'2', '3', '4'}},
            {'4', {'3', '4', '5'}},
            {'5', {'4', '5', '6'}},
            {'6', {'5', '6', '7'}},
            {'7', {'6', '7', '8'}},
            {'8', {'7', '8', '9'}},
            {'9', {'8', '9', '0'}},
    };

public:
    string nearestPalindromic(string n) {
        if (n.size() == 1) {
            res = n;
            res[0] -= 1;
            return res;
        }
        // compare with 99...99 or 100...01
        string option1(n.size() - 1, '9'), option2(n.size() - 1, '0');
        option2.append("1");
        option2 = "1" + option2;
        minDiff = calculateDifference(n, option1);
        res = option1;

        string option2Diff = calculateDifference(n, option2);
        if (smaller(option2Diff, minDiff)) {
            minDiff = option2Diff;
            res = option2;
        }

        string tmp = n;
        recursiveSearch(n, tmp, 0);
        return res;
    }

    void recursiveSearch(string &n, string &tmp, int index) {
        int len = n.size();
        for (auto c: mm[n[index]]) {
            tmp[index] = c;

            if ((len % 2 == 0 && index == len / 2 - 1) || (len % 2 == 1 && index == len / 2)) {
                // complete the string with the palindrome property
                for (int i = index + 1; i < len; ++i) {
                    tmp[i] = tmp[len - i - 1];
                }
                // calculate tmpDiff
                string tmpDiff = calculateDifference(n, tmp);
                // compare with minDiff, and set result if tmpDiff < minDiff
                if (smaller(tmpDiff, minDiff)) {
                    minDiff = tmpDiff;
                    res = tmp;
                } else if (tmpDiff == minDiff && smaller(tmp, res)) {
                    res = tmp;
                }
                continue;
            }
            recursiveSearch(n, tmp, index + 1);
        }
    }

    string calculateDifference(string &n1, string &n2) {
        if (n1 == n2) {
            return "99999999999999999999999999";
        }
        if (smaller(n1, n2)) {
            return calculateDifference(n2, n1);
        }
        string diff = n1;
        int borrow = 0, i1 = n1.size() - 1, i2 = n2.size() - 1;
        for (; i2 >= 0; --i1, --i2) {
            int diff_num = n1[i1] - n2[i2] - borrow;
            if (diff_num >= 0) {
                diff[i1] = '0' + diff_num;
                borrow = 0;
            } else {
                diff[i1] = '0' + diff_num + 10;
                borrow = 1;
            }
        }
        if (i1 >= 0) {
            diff[i1] -= borrow;
        }
        trimZero(diff);
        return diff;
    }

    void trimZero(string &n) {
        while(n[0] == '0') {
            n.erase(n.begin());
        }
    }

    bool smaller(string &n1, string &n2) {
        if (n1.size() < n2.size()) {
            return true;
        } else if (n1.size() > n2.size()) {
            return false;
        }
        return n1 < n2;
    }

    void check() override {
        string n = "99";
        cout << nearestPalindromic(n) << endl;
    }
};

#endif //LEETCODE_564_NEARESTPALINDROME_H
