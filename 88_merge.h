//
// Created by 王柯 on 10/11/22.
//

#ifndef LEETCODE_88_MERGE_H
#define LEETCODE_88_MERGE_H

#include "solution.h"

class Merge : public solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n -1;
        while (i >= 0 && j >= 0) {
            if (nums1[i] < nums2[j]) {
                nums1[k] = nums2[j];
                --j;
            } else {
                nums1[k] = nums1[i];
                --i;
            }
            --k;
        }
        while (j >= 0) {
            nums1[j] = nums2[j];
            --j;
        }
    }
};

#endif //LEETCODE_88_MERGE_H
