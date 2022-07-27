//
// Created by 王柯 on 7/27/22.
//

#ifndef LEETCODE_114_FLATTEN_H
#define LEETCODE_114_FLATTEN_H

#include "solution.h"

/**
 * Definition for a binary tree node.
 */

class Flatten {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode() : val(0), left(nullptr), right(nullptr) {}

        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

    TreeNode *traverse(TreeNode *tmp) {
        if (tmp == NULL)
            return NULL;
        TreeNode *tmp_left = tmp->left;
        TreeNode *tmp_right = tmp->right;
        if (tmp_left == NULL && tmp_right == NULL)
            return tmp;
        if (tmp_left != NULL) {
            TreeNode *curr = traverse(tmp_left);
            tmp->left = NULL;
            tmp->right = tmp_left;
            curr->left = NULL;
            curr->right = tmp_right;
            if (tmp_right != NULL) {
                curr = traverse(tmp_right);
            }
            return curr;
        } else {
            TreeNode *curr = traverse(tmp_right);
            return curr;
        }
    }

    void flatten(TreeNode *root) {
        traverse(root);
    }
};

#endif //LEETCODE_114_FLATTEN_H
