//
// Created by 王柯 on 10/21/22.
//

#ifndef LEETCODE_1650_LOWESTCOMMONANCESTOR_H
#define LEETCODE_1650_LOWESTCOMMONANCESTOR_H

#include "solution.h"

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class LowestCommonAncestor {
public:
    // Definition for a Node.
    class Node {
    public:
        int val;
        Node *left;
        Node *right;
        Node *parent;
    };


    Node *lowestCommonAncestor(Node *p, Node *q) {
        vector<Node *> parentP, parentQ;
        Node *res = nullptr, *tmp = p;
        while(tmp != nullptr) {
            parentP.push_back(tmp);
            tmp = tmp->parent;
        }
        tmp = q;
        while(tmp != nullptr) {
            parentQ.push_back(tmp);
            tmp = tmp->parent;
        }
        int i = parentP.size() - 1, j = parentQ.size() - 1;
        while(i >= 0 && j >= 0 && parentP[i] == parentQ[j]) {
            res = parentP[i];
            --i;
            --j;
        }
        return res;
    }
};

#endif //LEETCODE_1650_LOWESTCOMMONANCESTOR_H
