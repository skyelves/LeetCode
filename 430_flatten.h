//
// Created by 王柯 on 10/1/22.
//

#ifndef LEETCODE_430_FLATTEN_H
#define LEETCODE_430_FLATTEN_H

#include "solution.h"

class Flatten {
public:
// Definition for a Node.
    class Node {
    public:
        int val;
        Node *prev;
        Node *next;
        Node *child;
    };

    void dfs(Node *head, queue<Node *> &flattenQueue) {
        if (head == NULL)
            return;
        flattenQueue.push(head);
        dfs(head->child, flattenQueue);
        dfs(head->next, flattenQueue);
    }

    Node *flatten(Node *head) {
        if (head == NULL)
            return NULL;
        queue<Node *> flattenQueue;
        dfs(head, flattenQueue);
        auto iter = flattenQueue.front();
        flattenQueue.pop();
        while (!flattenQueue.empty()) {
            auto next = flattenQueue.front();
            flattenQueue.pop();
            iter->next = next;
            iter->child = NULL;
            next->prev = iter;
            iter = next;
        }
        iter->child = NULL;
        iter->next = NULL;
        return head;
    }
};

#endif //LEETCODE_430_FLATTEN_H
