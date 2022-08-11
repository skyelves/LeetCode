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
        if (root->val <= lb || root->val >= ub) {
            return false;
        }
        bool res = true;
        if (root->left != NULL) {
            if (root->left->val >= root->val) {
                return false;
            }
            int64_t tmp_ub = ub < root->val ? ub : root->val;
            bool tmp = isValid(root->left, lb, tmp_ub);
            res &= tmp;
        }
        if (root->right != NULL) {
            if (root->right->val <= root->val) {
                return false;
            }
            int64_t tmp_lb = lb > root->val ? lb : root->val;
            bool tmp = isValid(root->right, tmp_lb, ub);
            res &= tmp;
        }
        return res;
    }

    bool isValidBST(TreeNode* root) {
       return isValid(root);
    }
};

#endif //LEETCODE_98_ISVALIDBST_H
