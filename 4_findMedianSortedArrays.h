//
// Created by 王柯 on 11/14/22.
//

#ifndef LEETCODE_4_FINDMEDIANSORTEDARRAYS_H
#define LEETCODE_4_FINDMEDIANSORTEDARRAYS_H

#include "solution.h"

class FindMedianSortedArrays : public solution {
public:
    double kth(vector<int> &nums1, vector<int> &nums2, int l1, int l2, int k) {
        int len1 = nums1.size() - l1, len2 = nums2.size() - l2;
        if (len1 < len2)
            return kth(nums2, nums1, l2, l1, k);
        if (len2 == 0)
            return nums1[l1 + k - 1];
        if (k == 1)
            return min(nums1[l1], nums2[l2]);
        int m2 = min(len2, k / 2), m1 = k - m2;
        if (nums1[l1 + m1 - 1] > nums2[l2 + m2 - 1]) {
            return kth(nums1, nums2, l1, l2 + m2, k - m2);
        } else {
            return kth(nums1, nums2, l1 + m1, l2, k - m1);
        }
    }

    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        double res = 0;
        int len1 = nums1.size(), len2 = nums2.size(), k = (len1 + len2 + 1) / 2;
        res = kth(nums1, nums2, 0, 0, k);
        if ((len1 + len2) % 2 == 0) {
            res += kth(nums1, nums2, 0, 0, k + 1);
            res /= 2;
        }

        return res;
    }

    void check() {
        vector<int> nums1{1}, nums2{2, 3, 4};
        double res = findMedianSortedArrays(nums1, nums2);
        cout << res << endl;
    }
};

#endif //LEETCODE_4_FINDMEDIANSORTEDARRAYS_H
