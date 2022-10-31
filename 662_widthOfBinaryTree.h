//
// Created by 王柯 on 10/30/22.
//

#ifndef LEETCODE_662_WIDTHOFBINARYTREE_H
#define LEETCODE_662_WIDTHOFBINARYTREE_H

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

    int widthOfBinaryTree(TreeNode *root) {
        long long res = 0;
        queue<pair<TreeNode *, long long>> qq;
        qq.push({root, 0});
        while(!qq.empty()) {
            queue<pair<TreeNode *, long long>> nextQ;
            long long tmpCnt = qq.back().second - qq.front().second + 1;
            long long frontIdx = qq.front().second;
            res = max(tmpCnt, res);
            while(!qq.empty()) {
                auto t = qq.front();
                qq.pop();
                if (t.first->left != nullptr) {
                    nextQ.push({t.first->left, (t.second - frontIdx) * 2});
                }
                if (t.first->right != nullptr) {
                    nextQ.push({t.first->right, (t.second - frontIdx) * 2 + 1});
                }
            }
            qq = nextQ;
        }

        return res;
    }
};

#endif //LEETCODE_662_WIDTHOFBINARYTREE_H
