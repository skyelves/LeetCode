//
// Created by 王柯 on 11/27/22.
//

#ifndef LEETCODE_617_MERGETWOBINARYTREES_H
#define LEETCODE_617_MERGETWOBINARYTREES_H

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

    void dfs(TreeNode *root1, TreeNode *root2) {
        root1->val += root2->val;
        if (root1->left != nullptr) {
            if (root2->left != nullptr) {
                dfs(root1->left, root2->left);
            }
        } else {
            if (root2->left != nullptr) {
                root1->left = root2->left;
            }
        }
        if (root1->right != nullptr) {
            if (root2->right != nullptr) {
                dfs(root1->right, root2->right);
            }
        } else {
            if (root2->right != nullptr) {
                root1->right = root2->right;
            }
        }
    }

    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
        if (root1 == nullptr)
            return root2;
        if (root2 == nullptr)
            return root1;
        dfs(root1, root2);
        return root1;
    }
};

#endif //LEETCODE_617_MERGETWOBINARYTREES_H
