//
// Created by Ke Wang on 11/19/24.
//

#ifndef INC_863_ALLNODESDISTANCEKINBINARYTREE_H
#define INC_863_ALLNODESDISTANCEKINBINARYTREE_H

#include "solution.h"

class AllNodesDistanceKInBinaryTree : public solution {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int x) : val(x), left(NULL), right(NULL) {
        }
    };

public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
        vector<pair<TreeNode *, int>> path;
        bool find_target = false;
        dfs(root, target, find_target, path);

        vector<int> res;
        for (int i = 0; i < path.size(); ++i) {
            if (path[i].second > k) {
                break;
            } else if (path[i].second == k) {
                res.push_back(path[i].first->val);
                break;
            } else {
                queue<TreeNode *> layer;
                if (i == 0) {
                    TreeNode *tmp = path[i].first;
                    int dis = path[i].second;
                    if (tmp->left != nullptr) {
                        layer.push(tmp->left);
                    }
                    if (tmp->right != nullptr) {
                        layer.push(tmp->right);
                    }
                    bfs(layer, k - dis, res);
                } else {
                    TreeNode *tmp = path[i].first;
                    int dis = path[i].second;
                    if (tmp->left != nullptr && tmp->left != path[i - 1].first) {
                        layer.push(tmp->left);
                    }
                    if (tmp->right != nullptr && tmp->right != path[i - 1].first) {
                        layer.push(tmp->right);
                    }
                    bfs(layer, k - dis, res);
                }
            }
        }
        return res;
    }

    void bfs(queue<TreeNode *> &layer, int dis, vector<int> &res) {
        int tmp = 1;
        while (!layer.empty() && tmp < dis) {
            int n = layer.size();
            for (int i = 0; i < n; ++i) {
                TreeNode *curr = layer.front();
                layer.pop();
                if (curr->left != nullptr) {
                    layer.push(curr->left);
                }
                if (curr->right != nullptr) {
                    layer.push(curr->right);
                }
            }
            ++tmp;
        }
        if (tmp == dis) {
            while (!layer.empty()) {
                res.push_back(layer.front()->val);
                layer.pop();
            }
        }
    }

    void dfs(TreeNode *root, TreeNode* target, bool &find_target, vector<pair<TreeNode *, int>> &path) {
        if (root == nullptr || find_target) {
            return;
        }
        if (root == target) {
            path.push_back({root, 0});
            find_target = true;
            return;
        }
        dfs(root->left, target, find_target, path);
        dfs(root->right, target, find_target, path);
        if (find_target) {
            path.push_back({root, path[path.size() - 1].second + 1});
        }
    }
};

#endif //INC_863_ALLNODESDISTANCEKINBINARYTREE_H
