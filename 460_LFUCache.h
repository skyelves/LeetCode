//
// Created by 王柯 on 11/4/22.
//

#ifndef LEETCODE_LFUCACHE_H
#define LEETCODE_LFUCACHE_H

#include "solution.h"

class LFUCache {
public:
    int c;
    int t;
    int minCnt;
    unordered_map<int, int> kv;
    unordered_map<int, int> cnts;
    unordered_map<int, list<int>> lists;

    LFUCache(int capacity) {
        c = capacity;
        t = 0;
        minCnt = 0;
    }

    int get(int key) {
        if (kv.find(key) != kv.end()) {
            int cnt = cnts[key];
            auto &list = lists[cnt];
            list.remove(key);
            if (list.size() == 0 && cnt == minCnt) {
                ++minCnt;
            }
            ++cnt;
            cnts[key] = cnt;
            lists[cnt].push_front(key);
            return kv[key];
        }
        return -1;
    }

    void put(int key, int value) {
        if (kv.find(key) != kv.end()) {
            kv[key] = value;
            get(key);
        } else if (c > 0) {
            if (kv.size() >= c) {
                auto tmp = lists[minCnt].back();
                kv.erase(tmp);
                cnts.erase(tmp);
                lists[minCnt].pop_back();
            }
            minCnt = 1;
            kv[key] = value;
            cnts[key] = 1;
            lists[1].push_front(key);
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

#endif //LEETCODE_LFUCACHE_H
