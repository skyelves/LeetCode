//
// Created by Admin on 10/2/2024.
//

#ifndef LEETCODE_339_NESTEDLISTWEIGHTSUM_H
#define LEETCODE_339_NESTEDLISTWEIGHTSUM_H

#include "solution.h"

class NestedListWeightSum : public solution {
    class NestedInteger {
    public:
        // Constructor initializes an empty nested list.
        NestedInteger();     // Constructor initializes a single integer.
        NestedInteger(int value);

        // Return true if this NestedInteger holds a single integer, rather than a nested list.
        bool isInteger() const;

        // Return the single integer that this NestedInteger holds, if it holds a single integer
        // The result is undefined if this NestedInteger holds a nested list
        int getInteger() const;

        // Set this NestedInteger to hold a single integer.
        void setInteger(int value);

        // Set this NestedInteger to hold a nested list and adds a nested integer to it.
        void add(const NestedInteger &ni);

        // Return the nested list that this NestedInteger holds, if it holds a nested list
        // The result is undefined if this NestedInteger holds a single integer
        const vector<NestedInteger> &getList() const;
    };

public:
    int depthSum(vector<NestedInteger>& nestedList) {
        return getSum(nestedList, 1);
    }

    int getSum(const vector<NestedInteger> &nestedList, int depth) {
        int res = 0;
        for (const NestedInteger &tmp : nestedList) {
            if (tmp.isInteger()) {
                res += depth * tmp.getInteger();
            } else {
                res += getSum(tmp.getList(), depth + 1);
            }
        }
        return res;
    }
};

#endif //LEETCODE_339_NESTEDLISTWEIGHTSUM_H
