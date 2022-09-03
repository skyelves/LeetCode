//
// Created by 王柯 on 9/2/22.
//

#ifndef LEETCODE_637_AVERAGEOFLEVELS_H
#define LEETCODE_637_AVERAGEOFLEVELS_H

#include "solution.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class AverageOfLevels : public solution {
public:

    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode() : val(0), left(nullptr), right(nullptr) {}

        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

    vector<double> averageOfLevels(TreeNode *root) {
        set<TreeNode *> currLevel;
        vector<double> res;
        currLevel.insert(root);
        while (!currLevel.empty()) {
            double tmp = 0;
            set<TreeNode *> nextLevel;
            for (auto i : currLevel) {
                if (i->left != NULL)
                    nextLevel.insert(i->left);
                if (i->right != NULL)
                    nextLevel.insert(i->right);
                tmp += i->val;
            }
            tmp /= currLevel.size();
            res.push_back(tmp);
            currLevel = nextLevel;
        }
        return res;
    }

    void check() {

    }
};

#endif //LEETCODE_637_AVERAGEOFLEVELS_H
