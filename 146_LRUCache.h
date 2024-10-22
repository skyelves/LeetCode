//
// Created by 王柯 on 10/2/22.
//

#ifndef LEETCODE_146_LRUCACHE_H
#define LEETCODE_146_LRUCACHE_H

#include "solution.h"

class LRUCache {
public:
    map<int, list<pair<int, int> >::iterator > iterMap;
    list<pair<int, int> > lru;
    int _cap;

    LRUCache(int capacity) {
        _cap = capacity;
    }

    int get(int key) {
        auto iter = iterMap.find(key);
        if (iter != iterMap.end()) {
            int value = iter->second->second;
            prioritize(key, value);
            return value;
        }
        return -1;
    }

    void put(int key, int value) {
        if (iterMap.find(key) != iterMap.end()) {
            prioritize(key, value);
        }
        else {
            if (iterMap.size() < _cap) {
                pushFront(key, value);
            } else {
                replace(key, value);
            }
        }
    }

    void pushFront(int key, int value) {
        lru.emplace_front(key, value);
        iterMap.insert({key, lru.begin()});
    }

    void prioritize(int key, int value) {
        lru.erase(iterMap[key]);
        lru.emplace_front(key, value);
        iterMap[key] = lru.begin();
    }

    void replace(int key, int value) {
        int removedKey = lru.back().first;
        lru.pop_back();
        iterMap.erase(removedKey);
        lru.emplace_front(key, value);
        iterMap[key] = lru.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

#endif //LEETCODE_146_LRUCACHE_H
