//
// Created by 王柯 on 9/4/22.
//

#ifndef LEETCODE_987_VERTICALTRAVERSAL_H
#define LEETCODE_987_VERTICALTRAVERSAL_H

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
class VerticalTraversal {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode() : val(0), left(nullptr), right(nullptr) {}

        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

    multimap<int, pair<int, int> > mm;
    int minCol, maxCol;

    void dfs(TreeNode *tmp, int c = 0, int r = 0) {
        if (tmp == NULL)
            return;
        minCol = min(minCol, c);
        maxCol = max(maxCol, c);
        mm.insert({c, {r, tmp->val}});
        dfs(tmp->left, c - 1, r + 1);
        dfs(tmp->right, c + 1, r + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode *root) {
        vector<vector<int>> res;
        dfs(root);
        for (int i = minCol; i <= maxCol; ++i) {
            auto tmp = mm.equal_range(i);
            vector<pair<int, int>> oneCol;
            vector<int> tmpRes;
            for (auto j = tmp.first; j != tmp.second; j++) {
                oneCol.push_back(j->second);
            }
            // sort oneCol both by row and value
            sort(oneCol.begin(), oneCol.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
                if (a.first == b.first) {
                    return a.second < b.second;
                }
                return a.first < b.first;
            });
            for (auto j : oneCol) {
                tmpRes.push_back(j.second);
            }
            res.push_back(tmpRes);
        }
        return res;
    }
};

#endif //LEETCODE_987_VERTICALTRAVERSAL_H
