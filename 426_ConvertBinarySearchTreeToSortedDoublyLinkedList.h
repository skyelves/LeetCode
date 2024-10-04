//
// Created by Admin on 10/3/2024.
//

#ifndef LEETCODE_426_CONVERTBINARYSEARCHTREETOSORTEDDOUBLYLINKEDLIST_H
#define LEETCODE_426_CONVERTBINARYSEARCHTREETOSORTEDDOUBLYLINKEDLIST_H

#include "solution.h"

class ConvertBinarySearchTreeToSortedDoublyLinkedList : public solution {
    class Node {
    public:
        int val;
        Node* left;
        Node* right;

        Node() {}

        Node(int _val) {
            val = _val;
            left = NULL;
            right = NULL;
        }

        Node(int _val, Node* _left, Node* _right) {
            val = _val;
            left = _left;
            right = _right;
        }
    };
public:
    Node* treeToDoublyList(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }
        pair<Node*, Node*> resPair = convert(root);
        resPair.first->left = resPair.second;
        resPair.second->right = resPair.first;
        return resPair.first;
    }

    pair<Node*, Node*> convert(Node *root) {
        pair<Node*, Node*> leftBranch, rightBranch, res{root, root};
        if (root->left != nullptr) {
            leftBranch = convert(root->left);
            leftBranch.second->right = root;
            root->left = leftBranch.second;
            res.first = leftBranch.first;
        }
        if (root->right != nullptr) {
            rightBranch = convert(root->right);
            rightBranch.first->left = root;
            root->right = rightBranch.first;
            res.second = rightBranch.second;
        }
        return res;
    }
};

#endif //LEETCODE_426_CONVERTBINARYSEARCHTREETOSORTEDDOUBLYLINKEDLIST_H
