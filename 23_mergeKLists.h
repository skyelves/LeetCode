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

    struct cmp {
        bool operator() (const pair<int, ListNode *> &a, const pair<int, ListNode *> &b) {
            return a.first < b.first;
        }
    };

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode *res = new ListNode, *curr = res;
        int n = lists.size();
        priority_queue<pair<int, ListNode *>, vector<pair<int, ListNode *>>, cmp> pq;
        for (auto &node : lists) {
            if (node != nullptr)
                pq.push({node->val, node});
        }
        while (!pq.empty()) {
            ListNode *tmp = pq.top().second;
            pq.pop();
            if (tmp->next != nullptr) {
                pq.push({tmp->next->val, tmp->next});
            }
            curr->next = tmp;
            curr = tmp;
        }

        return res->next;
    }
};

#endif //LEETCODE_23_MERGEKLISTS_H
