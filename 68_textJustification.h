//
// Created by 王柯 on 8/23/23.
//

#ifndef LEETCODE_68_TEXTJUSTIFICATION_H
#define LEETCODE_68_TEXTJUSTIFICATION_H

#include "solution.h"

class TextJustification : public solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res{};
        int num = words.size();
        int tmpSize = words[0].size(), left = 0;
        for (int i = 1; i < num; ++i) {
            if (tmpSize + words[i].size() + 1 <= maxWidth) {
                tmpSize += words[i].size() + 1;
            } else {
                res.push_back(fillLine(words, left, i, maxWidth - tmpSize + i - left - 1));
                tmpSize = words[i].size();
                left = i;
            }
        }
        res.push_back(leftJustify(words, left, num, maxWidth - tmpSize + num - left - 1));
        return res;
    }

    string fillLine(vector<string>& words, int left, int right, int spaceNum) {
        string res = words[left];
        if (right - left == 1) {
            string tmp(spaceNum, ' ');
            return res + tmp;
        }
        int intervalNum = right - left - 1;
        string minSpace(spaceNum / intervalNum, ' ');
        string maxSpace = spaceNum % intervalNum == 0 ? minSpace : minSpace + " ";
        int maxIntervalCnt = spaceNum - (spaceNum / intervalNum) * intervalNum;
        for (int i = 1; i < right - left; ++i) {
            if (i <= maxIntervalCnt) {
                res += maxSpace;
            } else {
                res += minSpace;
            }
            res += words[left + i];
        }
        return res;
    }

    string leftJustify(vector<string>& words, int left, int right, int spaceNum) {
        string res = words[left];
        for (int i = 1; i < right - left; ++i) {
            res += " " + words[left + i];
            --spaceNum;
        }
        string tmp(spaceNum, ' ');
        return res + tmp;
    }

    void check() {
        vector<string> words{"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"};
        int maxWidth = 20;
        vector<string> res = fullJustify(words, maxWidth);
        for (auto &i : res) {
            cout << i << endl;
        }
    }
};

#endif //LEETCODE_68_TEXTJUSTIFICATION_H
