//
// Created by Ke Wang on 10/25/24.
//

#ifndef INC_270_CLOSESTBINARYSEARCHTREEVALUE_H
#define INC_270_CLOSESTBINARYSEARCHTREEVALUE_H
#include "solution.h"

class ClosestBSTValue : public solution {
private:
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
    int closestValue(TreeNode *root, double target) {
        if (root == nullptr) {
            return 3e9;
        }
        if (abs(root->val - target) < 1e-9) {
            return root->val;
        }
        if (target < root->val) {
            int tmp = closestValue(root->left, target);
            return abs(tmp - target) < abs(root->val - target) ? tmp : root->val;
        } else {
            int tmp = closestValue(root->right, target);
            return abs(tmp - target) < abs(root->val - target) ? tmp : root->val;
        }
    }
};

#endif //INC_270_CLOSESTBINARYSEARCHTREEVALUE_H
