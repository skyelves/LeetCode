//
// Created by Ke Wang on 10/20/24.
//

#ifndef INC_708_INSERTINTOASORTEDCIRCULARLINKEDLIST_H
#define INC_708_INSERTINTOASORTEDCIRCULARLINKEDLIST_H

#include "solution.h"

class InsertIntoASortedCircularLinkedList : public solution {
private:
    class Node {
    public:
        int val;
        Node* next;

        Node() {}

        Node(int _val) {
            val = _val;
            next = NULL;
        }

        Node(int _val, Node* _next) {
            val = _val;
            next = _next;
        }
    };

public:
    Node* insert(Node* head, int insertVal) {
        Node *res = new Node(insertVal);
        if (head == nullptr) {
            res->next = res;
            return res;
        }
        Node *tmp = head, *nextNode = head->next;
        bool flag = true;
        do {
            if (nextNode->val >= tmp->val) {
                if (tmp->val <= insertVal && insertVal <= nextNode->val) {
                    tmp->next = res;
                    res->next = nextNode;
                    flag = false;
                    break;
                }
            } else {
                // nextNode->val < tmp->val: reaching the end of the list
                if (insertVal <= nextNode->val || insertVal >= tmp->val) {
                    tmp->next = res;
                    res->next = nextNode;
                    flag = false;
                    break;
                }
            }
            nextNode = nextNode->next;
            tmp = tmp->next;
        } while (tmp != head);
        if (flag) {
            tmp->next = res;
            res->next = nextNode;
        }

        return head;
    }
};

#endif //INC_708_INSERTINTOASORTEDCIRCULARLINKEDLIST_H
