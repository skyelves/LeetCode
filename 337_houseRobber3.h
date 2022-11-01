//
// Created by 王柯 on 10/31/22.
//

#ifndef LEETCODE_337_HOUSEROBBER3_H
#define LEETCODE_337_HOUSEROBBER3_H

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
class HouseRobber3 {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode() : val(0), left(nullptr), right(nullptr) {}

        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

    pair<int, int> dfs(TreeNode *root) {
        if (root == nullptr)
            return {0, 0};
        auto leftRes = dfs(root->left);
        auto rightRes = dfs(root->right);
        return {max(leftRes.first, leftRes.second) + max(rightRes.first, rightRes.second), root->val + leftRes.first + rightRes.first};
    }

    int rob(TreeNode *root) {
        auto res = dfs(root);
        return max(res.first, res.second);
    }
};

#endif //LEETCODE_337_HOUSEROBBER3_H
