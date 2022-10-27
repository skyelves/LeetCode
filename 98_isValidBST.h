//
// Created by 王柯 on 8/10/22.
//

#ifndef LEETCODE_98_ISVALIDBST_H
#define LEETCODE_98_ISVALIDBST_H

#include "solution.h"


// Definition for a binary tree node.

class IsValidBST {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

    bool isValid(TreeNode *root, int64_t lb = INT64_MIN, int64_t ub = INT64_MAX) {
        if (root == nullptr)
            return true;
        if (root->val >= ub || root->val <= lb)
            return false;
        bool resLeft = isValid(root->left, lb, min(ub, (int64_t)root->val));
        if (!resLeft)
            return false;
        bool resRight = isValid(root->right, max(lb, (int64_t)root->val), ub);
        if (!resRight)
            return false;
        return true;
    }

    bool isValidBST(TreeNode* root) {
       return isValid(root);
    }
};

#endif //LEETCODE_98_ISVALIDBST_H
