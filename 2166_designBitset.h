//
// Created by 王柯 on 7/20/22.
//

#ifndef LEETCODE_2166_DESIGNBITSET_H
#define LEETCODE_2166_DESIGNBITSET_H

#include "solution.h"

class Bitset {
private:
    bool *bits = NULL; // represent the virtual bitset, combined with flipped to form the real bitset
    int _size = 0;
    int cnt = 0; // counts the number of '1' in the virtual bitset rather than the real Bitset
    bool flipped = false;
public:
    Bitset(int size) {
        _size = size;
        cnt = 0;
        bits = new bool[size];
        flipped = false;
        memset(bits, 0, size);
    }

    void fix(int idx) {
        cnt = flipped ? cnt - bits[idx] : cnt + !bits[idx];
        bits[idx] = !flipped;
    }

    void unfix(int idx) {
        cnt = flipped ? cnt + !bits[idx] : cnt - bits[idx];
        bits[idx] = flipped;
    }

    void flip() {
        flipped = !flipped;
//        cnt = _size - cnt;
    }

    bool all() {
        return flipped ? cnt == 0 : cnt == _size;
    }

    bool one() {
        return flipped ? cnt != _size : cnt > 0;
    }

    int count() {
        return flipped ? _size - cnt : cnt;
    }

    string toString() {
        string res = "";
        for (int i = 0; i < _size; ++i) {
            if (bits[i] == flipped) {
                res += "0";
            } else {
                res += "1";
            }
        }
        return res;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */

#endif //LEETCODE_2166_DESIGNBITSET_H
