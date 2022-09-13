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
        ListNode *res = new ListNode;
        ListNode *res_tmp = res;
        while (l1 != NULL && l2 != NULL) {
            int tmp = l1->val + l2->val + carry;
            if (tmp >= 10){
                carry = 1;
                tmp -= 10;
            } else {
                carry = 0;
            }
            ListNode *tmp_node = new ListNode(tmp);
            res_tmp->next = tmp_node;
            res_tmp = tmp_node;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != NULL) {
            int tmp = l1->val + carry;
            if (tmp >= 10){
                carry = 1;
                tmp -= 10;
            } else {
                carry = 0;
            }
            ListNode *tmp_node = new ListNode(tmp);
            res_tmp->next = tmp_node;
            res_tmp = tmp_node;
            l1 = l1->next;
        }
        while (l2 != NULL) {
            int tmp = l2->val + carry;
            if (tmp >= 10){
                carry = 1;
                tmp -= 10;
            } else {
                carry = 0;
            }
            ListNode *tmp_node = new ListNode(tmp);
            res_tmp->next = tmp_node;
            res_tmp = tmp_node;
            l2 = l2->next;
        }
        if (carry == 1) {
            ListNode *tmp_node = new ListNode(carry);
            res_tmp->next = tmp_node;
        }
        return res->next;
    }

    void check() {

    };
};

#endif //LEETCODE_2_ADDTWONUMBERS_H
