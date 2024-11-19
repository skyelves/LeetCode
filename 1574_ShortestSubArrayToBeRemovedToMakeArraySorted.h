//
// Created by Ke Wang on 11/18/24.
//

#ifndef INC_1574_SHORTESTSUBARRAYTOBEREMOVEDTOMAKEARRAYSORTED_H
#define INC_1574_SHORTESTSUBARRAYTOBEREMOVEDTOMAKEARRAYSORTED_H

#include "solution.h"

class ShortestSubArrayToBeRemovedToMakeArraySorted : public solution {
public:
    int findLengthOfShortestSubarray(vector<int> &arr) {
        int res = 0;
        int n = arr.size();
        int left = 0, right = n - 1;
        while (left < n - 1) {
            if (arr[left + 1] < arr[left]) {
                break;
            }
            ++left;
        }
        if (left == n - 1) {
            return 0;
        }
        res = left + 1;
        while (right >= 0) {
            while (left >= 0 && arr[left] > arr[right]) {
                --left;
            }
            res = max(res, left + 1 + (n - right));
            if (right > 0 && arr[right - 1] <= arr[right]) {
                --right;
            } else {
                break;
            }
        }
        return n - res;
    }

    void check() {
        vector<int> arr{6, 3, 10, 11, 15, 20, 13, 3, 18, 12};
        cout << findLengthOfShortestSubarray(arr) << endl;
    }
};

#endif //INC_1574_SHORTESTSUBARRAYTOBEREMOVEDTOMAKEARRAYSORTED_H
