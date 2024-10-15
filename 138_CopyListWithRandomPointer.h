//
// Created by Admin on 10/14/2024.
//

#ifndef LEETCODE_138_COPYLISTWITHRANDOMPOINTER_H
#define LEETCODE_138_COPYLISTWITHRANDOMPOINTER_H

#include "solution.h"

class CopyListWithRandomPointer : public solution {
private:
    class Node {
    public:
        int val;
        Node* next;
        Node* random;

        Node(int _val) {
            val = _val;
            next = NULL;
            random = NULL;
        }
    };

    unordered_map<Node*, Node*> nodeMap;

public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        if (nodeMap.find(head) != nodeMap.end()) {
            return nodeMap[head];
        }
        Node *newNode = new Node(head->val);
        nodeMap[head] = newNode;
        newNode->next = copyRandomList(head->next);
        newNode->random = copyRandomList(head->random);
        return newNode;
    }
};

#endif //LEETCODE_138_COPYLISTWITHRANDOMPOINTER_H
