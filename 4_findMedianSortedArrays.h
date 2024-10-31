//
// Created by 王柯 on 11/14/22.
//

#ifndef LEETCODE_4_FINDMEDIANSORTEDARRAYS_H
#define LEETCODE_4_FINDMEDIANSORTEDARRAYS_H

#include "solution.h"

class FindMedianSortedArrays : public solution {
public:
    int findKthNum(int k, int l1, int l2, vector<int> &nums1, vector<int> &nums2) {
        int n = nums1.size() - l1, m = nums2.size() - l2;
        if (n < m) {
            return findKthNum(k, l2, l1, nums2, nums1);
        }
        if (m == 0) {
            return nums1[l1 + k - 1];
        }
        if (k == 1) {
            return min(nums1[l1], nums2[l2]);
        }
        int midIdx2 = min(k / 2 - 1, m - 1), midIdx1 = k - midIdx2 - 2;
        int mid1 = nums1[l1 + midIdx1], mid2 = nums2[l2 + midIdx2];
        if (mid1 == mid2) {
            return mid1;
        } else if (mid1 < mid2) {
            return findKthNum(k - midIdx1 - 1, l1 + midIdx1 + 1, l2, nums1, nums2);
        } else {
            return findKthNum(k - midIdx2 - 1, l1, l2 + midIdx2 + 1, nums1, nums2);
        }
    }

    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        double res = 0;
        int n = nums1.size(), m = nums2.size();
        if ((n + m) % 2 == 1) {
            res = findKthNum((n + m + 1) / 2, 0, 0, nums1, nums2);
        } else {
            res = ((double) findKthNum((n + m) / 2, 0, 0, nums1, nums2) + findKthNum((n + m) / 2 + 1, 0, 0, nums1, nums2)) / 2;
        }
        return res;
    }

    void check() {
        vector<int> nums1{1,2,3,4,5}, nums2{6,7,8,9,10,11,12,13,14,15,16,17};
        double res = findMedianSortedArrays(nums1, nums2);
        cout << res << endl;
    }
};

#endif //LEETCODE_4_FINDMEDIANSORTEDARRAYS_H
