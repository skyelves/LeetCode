//
// Created by 王柯 on 11/2/22.
//

#ifndef LEETCODE_61_ROTATERIGHT_H
#define LEETCODE_61_ROTATERIGHT_H

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

    ListNode *rotateRight(ListNode *head, int k) {
        if (k == 0 || head == nullptr) return head;
        ListNode *left = head, *right = head;
        int cnt = 0;
        while (right->next != nullptr && cnt < k) {
            right = right->next;
            ++cnt;
        }
        if (cnt == k) {
            while (right->next != nullptr) {
                right = right->next;
                left = left->next;
            }
            ListNode *res = left->next;
            left->next = nullptr;
            right->next = head;
            return res;
        } else {
            k %= (cnt + 1);
            return rotateRight(head, k);
        }
    }
};

#endif //LEETCODE_61_ROTATERIGHT_H
