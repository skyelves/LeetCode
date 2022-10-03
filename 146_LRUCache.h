//
// Created by 王柯 on 10/2/22.
//

#ifndef LEETCODE_146_LRUCACHE_H
#define LEETCODE_146_LRUCACHE_H

#include "solution.h"

class LRUCache {
public:
    list<int> l;
    int n;
    unordered_map<int, list<int>::iterator> mm;
    unordered_map<int, int> kv;

    LRUCache(int capacity) {
        n = capacity;
    }

    int get(int key) {
        auto iter = mm.find(key);
        if (iter != mm.end()) {
            int value = kv[key];
            l.push_front(key);
            l.erase(iter->second);
            iter->second = l.begin();
            return value;
        } else {
            return -1;
        }
    }

    void put(int key, int value) {
        auto iter = mm.find(key);
        if (iter == mm.end()) {
            if (mm.size() == n) {
                kv.erase(l.back());
                mm.erase(l.back());
                l.pop_back();
            }
            kv[key] = value;
            l.push_front(key);
            mm.insert({key, l.begin()});
        } else {
            kv[key] = value;
            l.push_front(key);
            l.erase(iter->second);
            iter->second = l.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

#endif //LEETCODE_146_LRUCACHE_H
