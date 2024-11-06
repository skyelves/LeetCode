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
        vector<string> res;
        string curr = chars[digits[0]];
        vector<string> nextRes = move(letterCombinations(digits.substr(1)));
        if (nextRes.empty()) {
            for (int i = 0; i < curr.size(); ++i) {
                res.push_back({curr[i]});
            }
            return res;
        }
        for (int i = 0; i < curr.size(); ++i) {
            for (string &tmp : nextRes) {
                res.push_back(curr[i] + tmp);
            }
        }
        return res;
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
