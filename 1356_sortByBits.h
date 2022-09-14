//
// Created by 王柯 on 9/13/22.
//

#ifndef LEETCODE_1356_SORTBYBITS_H
#define LEETCODE_1356_SORTBYBITS_H

class SortByBits : public solution {
public:
    vector<int> sortByBits(vector<int> &arr) {
        vector<pair<int, int> > bitarr;
        for (auto i : arr) {
            int bit_cnt = 0;
            for (int j = 0; j < 16; ++j) {
                if ((i >> j) & 1) {
                    bit_cnt++;
                }
            }
            bitarr.push_back({bit_cnt, i});
        }
        sort(bitarr.begin(), bitarr.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
            if (a.first != b.first) {
                return a.first < b.first;
            }
            return a.second < b.second;
        });
        vector<int> res;
        for (auto i : bitarr) {
            res.push_back(i.second);
        }
        return res;
    }

    void check() {
        vector<int> arr{0, 1, 2, 3, 4, 5, 6, 7, 8};
        auto res = sortByBits(arr);
        for (auto i : res) {
            cout << i << " ";
        }
        cout << endl;
    }
};

#endif //LEETCODE_1356_SORTBYBITS_H
