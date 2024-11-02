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
        auto [leftmost, rightmost] = toDoublyList(root);
        leftmost->left = rightmost;
        rightmost->right = leftmost;
        return leftmost;
    }

    pair<Node*, Node*> toDoublyList(Node* root) {
        Node *leftmost = root, *left = root, *rightmost = root, *right = root;
        if (root->left != nullptr) {
            auto tmp = toDoublyList(root->left);
            leftmost = tmp.first;
            left = tmp.second;
            left->right = root;
            root->left = left;
        }
        if (root->right != nullptr) {
            auto tmp = toDoublyList(root->right);
            right = tmp.first;
            rightmost = tmp.second;
            right->left = root;
            root->right = right;
        }

        leftmost->left = rightmost;
        rightmost->right = leftmost;

        return {leftmost, rightmost};
    }
};

#endif //LEETCODE_426_CONVERTBINARYSEARCHTREETOSORTEDDOUBLYLINKEDLIST_H
