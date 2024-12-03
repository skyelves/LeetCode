//
// Created by Ke Wang on 12/2/24.
//

#ifndef INC_536_CONSTRUCTBINARYTREEFROMSTRING_H
#define INC_536_CONSTRUCTBINARYTREEFROMSTRING_H

#include "solution.h"

class ConstructBinaryTreeFromString : public solution {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode() : val(0), left(nullptr), right(nullptr) {
        }

        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
        }

        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {
        }
    };

public:
    TreeNode* str2tree(string s) {
        if (s.empty()) {
            return nullptr;
        }
        int idx = 0;
        int val = getNumber(idx, s);
        TreeNode *left_child = getChild(idx, s), *right_child = getChild(idx, s);
        return new TreeNode(val, left_child, right_child);
    }

    int getNumber(int &idx, string &s) {
        int res = 0, sign = 1;
        if (s[idx] == '-') {
            sign = -1;
            ++idx;
        }
        while (idx < s.size() && s[idx] >= '0' && s[idx] <= '9') {
            res *= 10;
            res += s[idx] - '0';
            ++idx;
        }
        return res * sign;
    }

    TreeNode *getChild(int &idx, string &s) {
        if (idx >= s.size()) {
            return nullptr;
        }
        ++idx;
        int start = idx, cnt = 1;
        while (idx < s.size() && cnt > 0) {
            if (s[idx] == '(') {
                ++cnt;
            } else if (s[idx] == ')') {
                --cnt;
            }
            ++idx;
        }
        return str2tree(s.substr(start, idx - start));
    }
};

#endif //INC_536_CONSTRUCTBINARYTREEFROMSTRING_H
