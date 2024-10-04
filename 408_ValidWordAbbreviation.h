//
// Created by Admin on 10/3/2024.
//

#ifndef LEETCODE_408_VALIDWORDABBREVIATION_H
#define LEETCODE_408_VALIDWORDABBREVIATION_H

#include "solution.h"

class ValidWordAbbreviation : public solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0, j = 0;
        while(i < word.length() && j < abbr.length()) {
            if (isLetter(abbr[j])) {
                if (word[i] == abbr[j]) {
                    ++i;
                    ++j;
                } else {
                    return false;
                }
            } else {
                int num = abbr[j] - '0';
                if (num == 0) {
                    return false;
                }
                ++j;
                for (; j < abbr.length(); ++j) {
                    if (isLetter(abbr[j])) {
                        i += num;
                        break;
                    } else {
                        num *= 10;
                        num += abbr[j] - '0';
                    }
                }
                if (j == abbr.length()) {
                    i += num;
                }
            }
        }
        if (i == word.length() && j == abbr.length()) {
            return true;
        } else {
            return false;
        }
    }

    bool isLetter(char c) {
        return c >= 'a' && c <= 'z';
    }

    void check() {
        string word = "internationalization", abbr = "i12iz4n";
        cout << validWordAbbreviation(word, abbr) << endl;
    }
};

#endif //LEETCODE_408_VALIDWORDABBREVIATION_H
