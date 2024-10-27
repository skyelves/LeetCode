//
// Created by Ke Wang on 10/27/24.
//

#ifndef INC_129_SUMROOTTOLEAFNUMBERS_H
#define INC_129_SUMROOTTOLEAFNUMBERS_H

#include "solution.h"

class SumRootToLeafNumbers : public solution {
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
    int sumNumbers(TreeNode *root) {
        int sum = 0;
        dfs(root, 0, sum);
        return sum;
    }

    void dfs(TreeNode *root, int tmp, int &sum) {
        if (root == nullptr) {
            return;
        }
        tmp *= 10;
        tmp += root->val;
        if (root->left == nullptr && root->right == nullptr) {
            sum += tmp;
            return;
        }
        dfs(root->left, tmp, sum);
        dfs(root->right, tmp, sum);
    }
};

#endif //INC_129_SUMROOTTOLEAFNUMBERS_H
