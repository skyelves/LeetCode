//
// Created by Admin on 10/9/2024.
//

#ifndef LEETCODE_938_RANGESUMOFBST_H
#define LEETCODE_938_RANGESUMOFBST_H

#include "solution.h"

class RangeSumOfBST : public solution {
private:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode() : val(0), left(nullptr), right(nullptr) {}

        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

public:
    int dfs(TreeNode *root, int low, int high) {
        if (root == nullptr) {
            return 0;
        }
        int res = 0, curr = root->val;
        if (curr < low) {
            res = dfs(root->right, low, high);
        } else if (curr > high) {
            res = dfs(root->left, low, high);
        } else {
            res = curr + dfs(root->right, low, high); + dfs(root->left, low, high);;
        }

        return res;
    }

    int rangeSumBST(TreeNode *root, int low, int high) {
        return dfs(root, low, high);
    }
};

#endif //LEETCODE_938_RANGESUMOFBST_H
