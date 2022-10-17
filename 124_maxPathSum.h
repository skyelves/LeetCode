//
// Created by 王柯 on 10/17/22.
//

#ifndef LEETCODE_124_MAXPATHSUM_H
#define LEETCODE_124_MAXPATHSUM_H

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
class MaxPathSum {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode() : val(0), left(nullptr), right(nullptr) {}

        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

    int res = INT_MIN;

    int dfs(TreeNode *root) {
        // leaf node
        if (root == nullptr)
            return INT_MIN / 3;
        int leftV = dfs(root->left), rightV = dfs(root->right);
        int tmp = max(0, max(leftV, rightV)) + root->val;
        res = max(res, max(tmp, leftV + rightV + root->val));
        return tmp;
    }

    int maxPathSum(TreeNode *root) {
        dfs(root);
        return res;
    }
};

#endif //LEETCODE_124_MAXPATHSUM_H
