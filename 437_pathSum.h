//
// Created by 王柯 on 10/30/22.
//

#ifndef LEETCODE_437_PATHSUM_H
#define LEETCODE_437_PATHSUM_H

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
class Solution {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode() : val(0), left(nullptr), right(nullptr) {}

        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

    int pathSum(TreeNode *root, int targetSum) {
        if (root == nullptr)
            return 0;
        int res = 0;
        queue<pair<TreeNode *, vector<long long>>> qq;
        qq.push({root, {root->val}});
        if (root->val == targetSum)
            ++res;
        while (!qq.empty()) {
            queue<pair<TreeNode *, vector<long long>>> nextQ;
            while (!qq.empty()) {
                auto tmp = qq.front();
                qq.pop();
                if (tmp.first->left != nullptr) {
                    vector<long long> vv{tmp.first->left->val};
                    if (tmp.first->left->val == targetSum)
                        ++res;
                    for (auto i : tmp.second) {
                        long long tmpSum = i + tmp.first->left->val;
                        if (tmpSum == targetSum)
                            ++res;
                        vv.push_back(tmpSum);
                    }
                    nextQ.push({tmp.first->left, vv});
                }
                if (tmp.first->right != nullptr) {
                    vector<long long> vv{tmp.first->right->val};
                    if (tmp.first->right->val == targetSum)
                        ++res;
                    for (auto i : tmp.second) {
                        long long tmpSum = i + tmp.first->right->val;
                        if (tmpSum == targetSum)
                            ++res;
                        vv.push_back(tmpSum);
                    }
                    nextQ.push({tmp.first->right, vv});
                }
            }
            qq = nextQ;
        }

        return res;
    }
};

#endif //LEETCODE_437_PATHSUM_H
