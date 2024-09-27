//
// Created by Admin on 9/26/2024.
//

#ifndef LEETCODE_199_BINARYTREERIGHTSIDEVIEW_H
#define LEETCODE_199_BINARYTREERIGHTSIDEVIEW_H

#include "solution.h"


class BinaryTreeRightSideView : public solution {
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
private:
    queue<TreeNode*> currLayer, nextLayer;

public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        currLayer.push(root);
        while(!currLayer.empty()) {
            TreeNode *tmp = nullptr;
            while(!currLayer.empty()) {
                tmp = currLayer.front();
                currLayer.pop();
                if (tmp->left != nullptr) {
                    nextLayer.push(tmp->left);
                }
                if (tmp->right != nullptr) {
                    nextLayer.push(tmp->right);
                }
            }
            res.push_back(tmp->val);
            currLayer = nextLayer;
            nextLayer = queue<TreeNode*>();
        }

        return res;
    }


};

#endif //LEETCODE_199_BINARYTREERIGHTSIDEVIEW_H
