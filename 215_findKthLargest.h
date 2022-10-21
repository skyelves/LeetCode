//
// Created by 王柯 on 10/21/22.
//

#ifndef LEETCODE_215_FINDKTHLARGEST_H
#define LEETCODE_215_FINDKTHLARGEST_H

#include "solution.h"

class FindKthLargest : public solution {
public:
    int partition(int left, int right, int pivotIdx, vector<int> &nums) {
        int pivot = nums[pivotIdx];
        int i = left, j = right;
        while(i < j) {
            while(i < j && nums[j] <= pivot) --j;
            if (i < j) {
                nums[i] = nums[j];
                ++i;
            }
            while (i < j && nums[i] >= pivot) ++i;
            if (i < j) {
                nums[j] = nums[i];
                --j;
            }
        }
        nums[i] = pivot;
        return i;
    }

    int quickSelect(int left, int right, int k, vector<int> &nums) {
        if (left == right)
            return nums[left];
        int pivotIdx = partition(left, right, left, nums);
        if (pivotIdx >= k - 1)
            return quickSelect(left, pivotIdx, k, nums);
        else
            return quickSelect(pivotIdx + 1, right, k, nums);
    }

    int findKthLargest(vector<int> &nums, int k) {
//      Nlog(k)
//        int n = nums.size();
//        priority_queue<int, vector<int>, greater<int>> qq;
//        for (int i = 0; i < k; ++i) {
//            qq.push(nums[i]);
//        }
//        for (int i = k; i < n; ++i) {
//            int tmpT = qq.top();
//            if (nums[i] > tmpT) {
//                qq.pop();
//                qq.push(nums[i]);
//            }
//        }
//        return qq.top();

//      O(N)
        return quickSelect(0, nums.size() - 1, k, nums);
    }

    void check() {
        vector<int> nums{3,2,1,5,6,4};
        int k = 2;
        int res = quickSelect(0, nums.size() - 1, k, nums);
        cout << res << endl;
    }
};

#endif //LEETCODE_215_FINDKTHLARGEST_H
