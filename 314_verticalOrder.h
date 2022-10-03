//
// Created by 王柯 on 10/2/22.
//

#ifndef LEETCODE_314_VERTICALORDER_H
#define LEETCODE_314_VERTICALORDER_H

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

    void dfs(TreeNode *tmp, int r, int c, int &visitedNum, vector<vector<int> > &pq) {
        if (tmp == NULL)
            return;
        visitedNum++;
        pq.push_back({c, r, visitedNum, tmp->val});
        dfs(tmp->left, r + 1, c - 1, visitedNum, pq);
        dfs(tmp->right, r + 1, c + 1, visitedNum, pq);
    }

    vector<vector<int> > verticalOrder(TreeNode *root) {
        vector<vector<int> > res;
        vector<vector<int> > pq;
        int visitedNum = 0;
        dfs(root, 0, 0, visitedNum, pq);
        sort(pq.begin(), pq.end(), [](const vector<int> &a, const vector<int> &b) {
            if (a[0] != b[0])
                return a[0] < b[0];
            if (a[1] != b[1])
                return a[1] < b[1];
            return a[2] < b[2];
        });
        pq.push_back({100000, 0, 0, 0});
        int lastOne = pq[0][0];
        vector<int> tmp;
        for (int i = 0; i < pq.size(); ++i) {
            if (pq[i][0] != lastOne) {
                res.push_back(tmp);
                lastOne = pq[i][0];
                tmp.clear();
            }
            tmp.push_back(pq[i][3]);
        }
        return res;
    }
};

#endif //LEETCODE_314_VERTICALORDER_H
