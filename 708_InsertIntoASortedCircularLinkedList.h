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
    void insertNode(Node *curr, Node *next, Node *new_node) {
        curr->next = new_node;
        new_node->next = next;
    }

    Node* insert(Node* head, int insertVal) {
        Node *new_node = new Node(insertVal);
        if (head == nullptr) {
            new_node->next = new_node;
            return new_node;
        }
        Node *curr = head, *next = curr->next;
        while (next != head) {
            if (next->val >= curr->val) {
                if (curr->val <= insertVal && next->val >= insertVal) {
                    curr->next = new_node;
                    insertNode(curr, next, new_node);
                    return head;
                }
            } else {
                // next->val < curr->val
                if (insertVal >= curr->val || insertVal < next->val) {
                    insertNode(curr, next, new_node);
                    return head;
                }
            }
            curr = next;
            next = next->next;
        }
        insertNode(curr, next, new_node);
        return head;
    }
};

#endif //INC_708_INSERTINTOASORTEDCIRCULARLINKEDLIST_H
