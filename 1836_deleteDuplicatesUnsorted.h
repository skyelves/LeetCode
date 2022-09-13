//
// Created by 王柯 on 9/13/22.
//

#ifndef LEETCODE_1836_DELETEDUPLICATESUNSORTED_H
#define LEETCODE_1836_DELETEDUPLICATESUNSORTED_H

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
class DeleteDuplicatesUnsorted {
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

    ListNode *deleteDuplicatesUnsorted(ListNode *head) {
        map<int, int> mm;
        ListNode *tmp = head, *remain;
//        mm[tmp->val]++;
        while (tmp != NULL) {
            auto iter = mm.find(tmp->val);
            if (iter != mm.end()) {
                (iter->second)++;
            } else {
                mm.insert({tmp->val, 1});
            }
            tmp = tmp->next;
        }
        tmp = head;

        bool flag = true;
        while (tmp != NULL) {
            if (mm[tmp->val] == 1) {
                if (flag) {
                    flag = false;
                    head = tmp;
                    remain = tmp;
                    tmp = tmp->next;
                    remain->next = NULL;
                } else {
                    remain->next = tmp;
                    remain = tmp;
                    tmp = tmp->next;
                    remain->next = NULL;
                }
            } else {
                tmp = tmp->next;
            }
        }
        return flag ? NULL : head;
    }
};

#endif //LEETCODE_1836_DELETEDUPLICATESUNSORTED_H
