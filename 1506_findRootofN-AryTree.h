//
// Created by 王柯 on 10/30/22.
//

#ifndef LEETCODE_1506_FINDROOTOFN_ARYTREE_H
#define LEETCODE_1506_FINDROOTOFN_ARYTREE_H

#include "solution.h"

class Solution {
public:

    // Definition for a Node.
    class Node {
    public:
        int val;
        vector<Node *> children;

        Node() {}

        Node(int _val) {
            val = _val;
        }

        Node(int _val, vector<Node *> _children) {
            val = _val;
            children = _children;
        }
    };

    Node *findRoot(vector<Node *> tree) {
        map<Node *, int> cnt;
        for (auto &i : tree) {
            for (auto &j : i->children)
                ++cnt[j];
            cnt[i] += 0;
        }
        for (auto iter = cnt.begin(); iter != cnt.end(); ++iter) {
            if (iter->second == 0)
                return iter->first;
        }
        return nullptr;
    }
};

#endif //LEETCODE_1506_FINDROOTOFN_ARYTREE_H
