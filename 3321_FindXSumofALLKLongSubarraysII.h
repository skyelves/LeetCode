//
// Created by Ke Wang on 10/17/24.
//

#ifndef INC_3321_FINDXSUMOFALLKLONGSUBARRAYSII_H
#define INC_3321_FINDXSUMOFALLKLONGSUBARRAYSII_H

#include "solution.h"
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

template<class T>
using ordered_set = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;

class FindXSumOfALLKLongSubarraysII : public solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        long long tmpSum = 0;
        vector<long long> res(n - k + 1, 0);
        unordered_map<int, int> cnt;
        ordered_set<pair<int, int>> pq;

        // initialize
        for (int i = 0; i < k; ++i) {
            ++cnt[nums[i]];
        }
        for (auto tmp : cnt) {
            pq.insert(make_pair(tmp.second, tmp.first));
        }
        auto it = pq.begin();
        for (int i = 0; i < x && it != pq.end(); ++i, ++it) {
            tmpSum += (long long)it->first * it->second;
        }
        res[0] = tmpSum;

        for (int i = 0; i < n - k; ++i) {
            if (nums[i] == nums[i + k]) {
                res[i + 1] = tmpSum;
                continue;
            }
            int tmp = nums[i];
            pair<int, int> tmpPair = {cnt[tmp], tmp};
            int tmpIdx = pq.order_of_key(tmpPair);
            pq.erase(tmpPair);
            --cnt[tmp];
            --tmpPair.first;
            if (tmpPair.first > 0) {
                pq.insert(tmpPair);
            }
            // calculate the affect to tmpSum
            if (tmpIdx < x){
                tmpSum -= tmp;
                int newIdx = pq.order_of_key(tmpPair);
                if (newIdx >= x) {
                    tmpSum -= (long long)tmp * cnt[tmp];
                    tmpSum += (long long)pq.find_by_order(x-1)->first * pq.find_by_order(x-1)->second;
                }
            }

            tmp = nums[i + k];
            tmpPair = {cnt[tmp], tmp};
            tmpIdx = pq.order_of_key(tmpPair);
            pq.erase(tmpPair);
            ++cnt[tmp];
            ++tmpPair.first;
            pq.insert(tmpPair);
            // calculate the affect to tmpSum
            if (tmpIdx < x) {
                tmpSum += tmp;
            } else {
                // tmpIdx >= x
                int newIdx = pq.order_of_key(tmpPair);
                if (newIdx < x) {
                    tmpSum += (long long)tmp * cnt[tmp];
                    tmpSum -= (long long)pq.find_by_order(x)->first * pq.find_by_order(x)->second;
                }
            }

            res[i + 1] = tmpSum;
        }
        return res;
    }

    void check() {
        vector<int> nums{4,4,4,10};
        int k = 2, x = 1;
        vector<long long> res = findXSum(nums, k, x);
        for (long long i : res) {
            cout << i << " ";
        }
    }
};

#endif //INC_3321_FINDXSUMOFALLKLONGSUBARRAYSII_H
