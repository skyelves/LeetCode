//
// Created by Admin on 10/1/2024.
//

#ifndef LEETCODE_102_BINARYTREELEVELORDERTRAVERSAL_H
#define LEETCODE_102_BINARYTREELEVELORDERTRAVERSAL_H

#include "solution.h"

class BinaryTreeLevelOrderTraversal : public solution {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode() : val(0), left(nullptr), right(nullptr) {}

        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        vector<vector<int>> res;
        queue<TreeNode*> level;
        level.push(root);
        while (!level.empty()) {
            queue<TreeNode*> nextLevel;
            vector<int> tmpRes;
            while(!level.empty()) {
                TreeNode *tmp = level.front();
                level.pop();
                tmpRes.push_back(tmp->val);
                if (tmp->left != nullptr) {
                    nextLevel.push(tmp->left);
                }
                if (tmp->right != nullptr) {
                    nextLevel.push(tmp->right);
                }
            }
            res.push_back(tmpRes);
            level = nextLevel;
        }
        return res;
    }
};

#endif //LEETCODE_102_BINARYTREELEVELORDERTRAVERSAL_H
