//
// Created by 王柯 on 12/8/22.
//

#ifndef LEETCODE_706_MYHASHMAP_H
#define LEETCODE_706_MYHASHMAP_H

#include "solution.h"

class MyHashMap {
#define HASH_RANGE 10000
    vector<vector<pair<int, int>>> ht;
public:
    MyHashMap() {
        ht.resize(HASH_RANGE);
    }

    inline int myHash(int key) {
        return key % HASH_RANGE;
    }

    void put(int key, int value) {
        int idx = myHash(key);
        for (auto &kv : ht[idx]) {
            if (kv.first == key) {
                kv.second = value;
                return;
            }
        }
        ht[idx].push_back({key, value});
    }

    int get(int key) {
        int idx = myHash(key);
        for (auto &kv : ht[idx]) {
            if (kv.first == key) {
                return kv.second;
            }
        }
        return -1;
    }

    void remove(int key) {
        int idx = myHash(key);
        auto &kvs = ht[idx];
        for (int i = 0; i < kvs.size(); ++i) {
            if (kvs[i].first == key) {
                kvs.erase(kvs.begin() + i);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

#endif //LEETCODE_706_MYHASHMAP_H
