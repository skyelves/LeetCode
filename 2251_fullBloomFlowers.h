//
// Created by 王柯 on 7/26/22.
//

#ifndef LEETCODE_2251_FULLBLOOMFLOWERS_H
#define LEETCODE_2251_FULLBLOOMFLOWERS_H

#include "solution.h"

class FullBloomFlowers : public solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>> &flowers, vector<int> &persons) {
        int flower_num = flowers.size();
        int person_num = persons.size();
        vector<int> starts, ends, res;
        map<int, int> res_map;
        set<int> persons_unique;
        for (auto i : persons) {
            persons_unique.insert(i);
        }
        for (auto i : flowers) {
            starts.push_back(i[0]);
            ends.push_back(i[1]);
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        int s = 0, e = 0;
        int bloom_cnt = 0;
        for (auto person : persons_unique) {
            while (s < flower_num && starts[s] <= person) {
                bloom_cnt++;
                s++;
            }
            while (e < flower_num && ends[e] < person) {
                bloom_cnt--;
                e++;
            }
            res_map[person] = bloom_cnt;
        }
        for (auto person : persons) {
            res.push_back(res_map[person]);
        }
        return res;
    }

    void check() {
        vector<vector<int>> flowers{
                {1, 6},
                {3, 7},
                {9, 12},
                {4, 13}
        };
        vector<int> persons{2, 3, 7, 2, 11};
        auto res = fullBloomFlowers(flowers, persons);
        for (auto i : res) {
            cout << i << endl;
        }
    }
};

#endif //LEETCODE_2251_FULLBLOOMFLOWERS_H
