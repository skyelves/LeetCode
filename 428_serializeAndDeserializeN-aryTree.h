//
// Created by 王柯 on 11/28/22.
//

#ifndef LEETCODE_428_SERIALIZEANDDESERIALIZEN_ARYTREE_H
#define LEETCODE_428_SERIALIZEANDDESERIALIZEN_ARYTREE_H

#include "solution.h"

class Codec {
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

    void dfs(Node *root, string &res) {
        if (root == nullptr)
            return;
        stringstream ss;
        ss << root->val;
        res += ss.str() + ",";
        for (auto &i: root->children) {
            dfs(i, res);
        }
        res += "#";
    }

    Node *dedfs(string &data, int &idx) {
        if (idx >= data.size() || data[idx] == '#') {
            ++idx;
            return nullptr;
        }
        Node *root = new Node;
        int len = data.find(',', idx) - idx;
        root->val = stoi(data.substr(idx, len));
        idx += len + 1;
        Node *tmp = dedfs(data, idx);
        while (tmp != nullptr) {
            root->children.push_back(tmp);
            tmp = dedfs(data, idx);
        }
        return root;
    }

    // Encodes a tree to a single string.
    string serialize(Node *root) {
        string res;
        dfs(root, res);
        return res;
    }

    // Decodes your encoded data to tree.
    Node *deserialize(string data) {
        int idx = 0;
        Node *root = dedfs(data, idx);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));


#endif //LEETCODE_428_SERIALIZEANDDESERIALIZEN_ARYTREE_H
