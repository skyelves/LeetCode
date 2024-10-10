//
// Created by Admin on 10/10/2024.
//

#ifndef LEETCODE_1013_PARTITIONARRAY_H
#define LEETCODE_1013_PARTITIONARRAY_H

#include "solution.h"

class PartitionArrayIntoThreeParts : public solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int n = arr.size();
        int left = 0, right = n - 1;
        int tmp = 0, sum = 0;
        for (int i : arr) {
            sum += i;
        }
        if (sum % 3 != 0) {
            return false;
        }
        sum = sum / 3;
        while (left < n) {
            tmp += arr[left];
            if (tmp == sum) {
                break;
            }
            ++left;
        }
        tmp = 0;
        while (right > left) {
            tmp += arr[right];
            if (tmp == sum) {
                break;
            }
            --right;
        }
        if (right > left + 1) {
            return true;
        }
        return false;
    }
};


#endif //LEETCODE_1013_PARTITIONARRAY_H
