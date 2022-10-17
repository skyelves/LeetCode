//
// Created by 王柯 on 10/17/22.
//

#ifndef LEETCODE_23_MERGEKLISTS_H
#define LEETCODE_23_MERGEKLISTS_H

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

class MergeKLists {
public:
    struct ListNode {
        int val;
        ListNode *next;

        ListNode() : val(0), next(nullptr) {}

        ListNode(int x) : val(x), next(nullptr) {}

        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode *res = new ListNode, *curr = res;
        int n = lists.size();
        while (1) {
            ListNode *tmp = nullptr;
            int tmpIdx = -1;
            for (int i = 0; i < n; ++i) {
                if (lists[i] != nullptr) {
                    if (tmp == nullptr || tmp->val > lists[i]->val) {
                        tmp = lists[i];
                        tmpIdx = i;
                    }
                }
            }
            if (tmpIdx == -1)
                break;
            curr->next = tmp;
            curr = curr->next;
            lists[tmpIdx] = tmp->next;
        }

        return res->next;
    }
};

#endif //LEETCODE_23_MERGEKLISTS_H
