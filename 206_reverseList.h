//
// Created by 王柯 on 1/2/23.
//

#ifndef LEETCODE_206_REVERSELIST_H
#define LEETCODE_206_REVERSELIST_H

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

    ListNode *reverseList(ListNode *head) {
        if (head == nullptr)
            return nullptr;
        auto tmp = head->next, prev = head;
        while (tmp) {
            auto n = tmp->next;
            tmp->next = prev;
            prev = tmp;
            tmp = n;
        }
        head->next = nullptr;
        return prev;
    }
};

#endif //LEETCODE_206_REVERSELIST_H
