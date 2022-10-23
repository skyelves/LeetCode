//
// Created by 王柯 on 10/23/22.
//

#ifndef LEETCODE_117_CONNECT_H
#define LEETCODE_117_CONNECT_H

#include "solution.h"

class Solution {
public:

    // Definition for a Node.
    class Node {
    public:
        int val;
        Node *left;
        Node *right;
        Node *next;

        Node() : val(0), left(NULL), right(NULL), next(NULL) {}

        Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

        Node(int _val, Node *_left, Node *_right, Node *_next)
                : val(_val), left(_left), right(_right), next(_next) {}
    };

    Node *connect(Node *root) {
        Node *tmp = root;
        while(tmp != nullptr) {
            Node *prev = nullptr, *nextLevel = nullptr;
            while(tmp != nullptr) {
                if (tmp->left != nullptr) {
                    if (prev == nullptr) {
                        nextLevel = tmp->left;
                    } else {
                        prev->next = tmp->left;
                    }
                    prev = tmp->left;
                }
                if (tmp->right != nullptr) {
                    if (prev == nullptr) {
                        nextLevel = tmp->right;
                    } else {
                        prev->next = tmp->right;
                    }
                    prev = tmp->right;
                }
                tmp = tmp->next;
            }
            tmp = nextLevel;
        }
        return root;
//        queue<Node *> qq;
//        if (root == nullptr) return root;
//        qq.push(root);
//        while (!qq.empty()) {
//            queue<Node *> tmp;
//            Node *prev = nullptr;
//            while (!qq.empty()) {
//                Node *curr = qq.front();
//                qq.pop();
//                if (prev != nullptr) {
//                    prev->next = curr;
//                }
//                prev = curr;
//                if (curr->left != nullptr) {
//                    tmp.push(curr->left);
//                }
//                if (curr->right != nullptr) {
//                    tmp.push(curr->right);
//                }
//            }
//            qq = tmp;
//        }
//        return root;
    }
};

#endif //LEETCODE_117_CONNECT_H
