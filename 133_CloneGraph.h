//
// Created by Admin on 10/14/2024.
//

#ifndef LEETCODE_133_CLONEGRAPH_H
#define LEETCODE_133_CLONEGRAPH_H

#include "solution.h"

class CloneGraph : public solution {
private:
    class Node {
    public:
        int val;
        vector<Node*> neighbors;
        Node() {
            val = 0;
            neighbors = vector<Node*>();
        }
        Node(int _val) {
            val = _val;
            neighbors = vector<Node*>();
        }
        Node(int _val, vector<Node*> _neighbors) {
            val = _val;
            neighbors = _neighbors;
        }
    };

    unordered_map<int, Node*> visited;

public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }
        if (visited.find(node->val) != visited.end()) {
            return visited[node->val];
        }
        Node *newNode = new Node(node->val);
        visited[newNode->val] = newNode;
        for (Node *neighbor: node->neighbors) {
            newNode->neighbors.push_back(cloneGraph(neighbor));
        }

        return newNode;
    }
};

#endif //LEETCODE_133_CLONEGRAPH_H
