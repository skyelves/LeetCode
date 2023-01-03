//
// Created by 王柯 on 1/2/23.
//

#ifndef LEETCODE_234_PALINDROMELINKEDLIST_H
#define LEETCODE_234_PALINDROMELINKEDLIST_H

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

    bool isPalindrome(ListNode *head) {
        int len = 0;
        auto tmp = head;
        while (tmp) {
            tmp = tmp->next;
            ++len;
        }
        int mid = len / 2;
        tmp = head;
        for (int i = 0; i < mid; ++i) {
            tmp = tmp->next;
        }
        if (len % 2)
            tmp = tmp->next;
        // reverse the first half list
        if (mid >= 2) {
            auto curr = head->next, prev = head;
            for (int i = 1; i < mid; ++i) {
                auto n = curr->next;
                curr->next = prev;
                prev = curr;
                curr = n;
            }
            head->next = nullptr;
            head = prev;
        }

        for (int i = 0; i < mid; ++i) {
            if (head->val != tmp->val) {
                return false;
            }
            head = head->next;
            tmp = tmp->next;
        }
        return true;
    }
};

#endif //LEETCODE_234_PALINDROMELINKEDLIST_H
