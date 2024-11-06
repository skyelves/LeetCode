//
// Created by Ke Wang on 11/5/24.
//

#ifndef INC_17_LETTERCOMBINATIONSOFAPHONENUMBER_H
#define INC_17_LETTERCOMBINATIONSOFAPHONENUMBER_H

#include "solution.h"

class LetterCombinationsOfAPhoneNumber : public solution {
    unordered_map<char, string> chars{
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        vector<string> res = {};
        string comb(digits.size(), '0');
        dfs(0, comb, digits, res);
        return res;
    }

    void dfs(int idx, string &comb, string &digits, vector<string> &res) {
        if (idx == digits.size()) {
            res.push_back(comb);
        }
        string curr = chars[digits[idx]];
        for (char c : curr) {
            comb[idx] = c;
            dfs(idx + 1, comb, digits, res);
        }
    }

    void check() {
        string digits = "23";
        auto res = letterCombinations(digits);
        for (string &tmp : res) {
            cout << tmp << " ";
        }
    }
};

#endif //INC_17_LETTERCOMBINATIONSOFAPHONENUMBER_H
