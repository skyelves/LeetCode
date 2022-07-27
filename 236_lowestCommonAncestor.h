//
// Created by 王柯 on 7/26/22.
//

#ifndef LEETCODE_236_LOWESTCOMMONANCESTOR_H
#define LEETCODE_236_LOWESTCOMMONANCESTOR_H

#include "solution.h"


class Solution : public solution {
public:
/**
 * Definition for a binary tree node.
 */
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    bool find_node(TreeNode *tmp, TreeNode *target, vector<TreeNode *> &path) {
        if (tmp == NULL)
            return false;
        if (tmp == target) {
            path.push_back(tmp);
            return true;
        }
        if (find_node(tmp->left, target, path)) {
            path.push_back(tmp);
            return true;
        } else if (find_node(tmp->right, target, path)) {
            path.push_back(tmp);
            return true;
        }
        return false;
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        vector<TreeNode *> path1, path2;
        find_node(root, p, path1);
        find_node(root, q, path2);
        int len1 = path1.size() - 1, len2 = path2.size() - 1;
        TreeNode *res = root;
        while (len1 >= 0 && len2 >= 0 && path1[len1] == path2[len2]) {
            res = path1[len1];
            len1--;
            len2--;
        }
        return res;
    }

    void check() {

    }
};

#endif //LEETCODE_236_LOWESTCOMMONANCESTOR_H
