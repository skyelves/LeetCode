//
// Created by 王柯 on 10/28/22.
//

#ifndef LEETCODE_19_REMOVENTHFROMEND_H
#define LEETCODE_19_REMOVENTHFROMEND_H

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
class Solution {
public:
    struct ListNode {
        int val;
        ListNode *next;

        ListNode() : val(0), next(nullptr) {}

        ListNode(int x) : val(x), next(nullptr) {}

        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *n1 = head, *n2 = head;
        for (int i = 1; i < n; ++i) {
            n1 = n1->next;
        }
        if (n1->next != nullptr) {
            n1 = n1->next;
        } else {
            return head->next;
        }
        while (n1->next != nullptr) {
            n1 = n1->next;
            n2 = n2->next;
        }
        n2->next = n2->next->next;
        return head;
    }
};

#endif //LEETCODE_19_REMOVENTHFROMEND_H
