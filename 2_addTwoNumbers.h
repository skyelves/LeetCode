//
// Created by 王柯 on 7/19/22.
//

#ifndef LEETCODE_2_ADDTWONUMBERS_H
#define LEETCODE_2_ADDTWONUMBERS_H

#include "solution.h"

class AddTwoNumbers : public solution {
public:
/*
 * Definition for singly-linked list.
 */
    struct ListNode {
        int val;
        ListNode *next;

        ListNode() : val(0), next(nullptr) {}

        ListNode(int x) : val(x), next(nullptr) {}

        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int carry = 0;
        int len1 = 0, len2 = 0;
        ListNode *t1 = l1, *t2 = l2, *lastNode = l1;
        while (t1 != nullptr || t2 != nullptr) {
            int tmp = carry;
            if (t1 != nullptr) tmp += t1->val;
            if (t2 != nullptr) tmp += t2->val;
            if (tmp >= 10) {
                carry = 1;
                tmp %= 10;
            } else {
                carry = 0;
            }
            if (t1 != nullptr) {
                t1->val = tmp;
                lastNode = t1;
                t1 = t1->next;
                ++len1;
            }
            if (t2 != nullptr) {
                t2->val = tmp;
                lastNode = t2;
                t2 = t2->next;
                ++len2;
            }
        }
        if (carry) {
            ListNode *newNode = new ListNode(1);
            lastNode->next = newNode;
        }

        return len1 > len2 ? l1 : l2;
    }

    void check() {

    };
};

#endif //LEETCODE_2_ADDTWONUMBERS_H
