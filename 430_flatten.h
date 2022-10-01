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

//    void dfs(Node *head, queue<Node *> &flattenQueue) {
//        if (head == NULL)
//            return;
//        flattenQueue.push(head);
//        dfs(head->child, flattenQueue);
//        dfs(head->next, flattenQueue);
//    }
//
//    Node *flatten(Node *head) {
//        if (head == NULL)
//            return NULL;
//        queue<Node *> flattenQueue;
//        dfs(head, flattenQueue);
//        auto iter = flattenQueue.front();
//        flattenQueue.pop();
//        while (!flattenQueue.empty()) {
//            auto next = flattenQueue.front();
//            flattenQueue.pop();
//            iter->next = next;
//            iter->child = NULL;
//            next->prev = iter;
//            iter = next;
//        }
//        iter->child = NULL;
//        iter->next = NULL;
//        return head;
//    }

    Node* dfs(Node *head) {
        if (head->next == NULL && head->child == NULL)
            return head;
        Node *nextNode = head->next, *childNode = head->child, *lastNode = head;
        head->child = NULL;
        if (childNode != NULL) {
            head->next = childNode;
            childNode->prev = head;
            lastNode = dfs(childNode);
        }
        lastNode->next = nextNode;
        if (nextNode != NULL) {
            nextNode->prev = lastNode;
            lastNode = dfs(nextNode);
        }
        return lastNode;
    }

    Node* flatten(Node* head) {
        if (head == NULL)
            return NULL;
        dfs(head);
        return head;
    }
};

#endif //LEETCODE_430_FLATTEN_H
