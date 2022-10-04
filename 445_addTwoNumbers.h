//
// Created by 王柯 on 10/4/22.
//

#ifndef LEETCODE_445_ADDTWONUMBERS_H
#define LEETCODE_445_ADDTWONUMBERS_H

#include "solution.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class AddTwoNumbers {
public:
    struct ListNode {
        int val;
        ListNode *next;

        ListNode() : val(0), next(nullptr) {}

        ListNode(int x) : val(x), next(nullptr) {}

        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    ListNode *reverseList(ListNode *head) {
        ListNode *next, *last = NULL;
        while(head != NULL) {
            next = head->next;
            head->next = last;
            last = head;
            head = next;
        }
        return last;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *res = new ListNode, *last = res;
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        int carry = 0;
        while (l1 != NULL || l2 != NULL) {
            int val1 = l1 != NULL ? l1->val : 0, val2 = l2 != NULL ? l2->val : 0;
            int tmp = val1 + val2 + carry;
            carry = tmp >= 10;
            tmp = tmp % 10;
            ListNode *curr = new ListNode;
            curr->val = tmp;
            last->next = curr;
            last = curr;
            l1 = l1 != NULL ? l1->next : NULL;
            l2 = l2 != NULL ? l2->next : NULL;
        }
        if (carry != 0) {
            ListNode *curr = new ListNode;
            curr->val = 1;
            last->next = curr;
            last = curr;
        }
        res = reverseList(res);
        return res;
    }
};

#endif //LEETCODE_445_ADDTWONUMBERS_H
