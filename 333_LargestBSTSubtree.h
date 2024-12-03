//
// Created by Ke Wang on 12/3/24.
//

#ifndef INC_333_LARGESTBSTSUBTREE_H
#define INC_333_LARGESTBSTSUBTREE_H

#include "solution.h"

class LargestBSTSubtree : public solution {
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
    int largestBSTSubtree(TreeNode *root) {
        auto res = dfs(root);
        return res[1];
    }

    vector<int> dfs(TreeNode *root) {
        if (root == nullptr) {
            return {1, 0, 0, 0}; // isBST, nodeNum, smallest, largest
        }
        auto left = dfs(root->left), right = dfs(root->right);
        if (left[0] == 0 || right[0] == 0) {
            return {0, max(left[1], right[1]), 0, 0};
        }
        if ((left[1] == 0 || left[3] < root->val) && (right[1] == 0 || right[2] > root->val)) {
            int left_min = left[1] == 0 ? root->val : left[2];
            int right_max = right[1] == 0 ? root->val : right[3];
            return {1, left[1] + right[1] + 1, left_min, right_max};
        }
        return {0, max(left[1], right[1]), 0, 0};
    }
};

#endif //INC_333_LARGESTBSTSUBTREE_H
