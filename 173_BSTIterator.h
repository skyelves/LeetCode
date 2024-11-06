//
// Created by Ke Wang on 11/6/24.
//

#ifndef INC_173_BSTITERATOR_H
#define INC_173_BSTITERATOR_H
#include "solution.h"

class BSTIterator : public solution {
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

    stack<TreeNode *> parent;

public:
    BSTIterator(TreeNode* root) {
        pushAllNode(root);
    }

    void pushAllNode(TreeNode *root) {
        while (root != nullptr) {
            parent.push(root);
            root = root->left;;
        }
    }

    int next() {
        if (hasNext()) {
            TreeNode *curr = parent.top();
            parent.pop();
            pushAllNode(curr->right);
            return curr->val;
        }
        throw runtime_error("error");
    }

    bool hasNext() {
        return !parent.empty();
    }
};

#endif //INC_173_BSTITERATOR_H
