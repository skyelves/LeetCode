//
// Created by 王柯 on 7/27/22.
//

#ifndef LEETCODE_2003_SMALLESTMISSINGVALUESUBTREE_H
#define LEETCODE_2003_SMALLESTMISSINGVALUESUBTREE_H

#include "solution.h"

class SmallestMissingValueSubtree : public solution {
public:
    void dfs(int tmp, vector<vector<int> > &child, vector<int> &nums, bool *visited) {
        // note the parameter:
        // use `vector<vector<int> > &child` : accpted
        // but `vector<vector<int> > child` : TLE
        if (visited[nums[tmp]])
            return;
        visited[nums[tmp]] = true;
        for (auto i : child[tmp]) {
            dfs(i, child, nums, visited);
        }
    }


    vector<int> smallestMissingValueSubtree(vector<int> &parents, vector<int> &nums) {
        int node_num = parents.size();
        auto idxOne = find(nums.begin(), nums.end(), 1);
        int idx1 = (idxOne != nums.end()) ? idxOne - nums.begin() : -1;
        if (idx1 == -1) {
            vector<int> res(node_num, 1);
            return res;
        }
        vector<int> res(node_num, 1);
        vector<vector<int> > child(node_num);
        for (int i = 0; i < node_num; ++i) {
            if (parents[i] != -1) {
                child[parents[i]].push_back(i);
            }
        }
        int curr_min = 1;
        bool visited[100005] = {false};
        while (idx1 != -1) {
            dfs(idx1, child, nums, visited);
            while (visited[curr_min]) {
                curr_min++;
            }
            res[idx1] = curr_min;
            idx1 = parents[idx1];
        }

        return res;
    }

    void check() {
        vector<int> parents{-1, 0, 1, 0, 3, 3}, nums{5, 4, 6, 2, 1, 3};
        auto res = smallestMissingValueSubtree(parents, nums);
        for (auto i : res) {
            cout << i << endl;
        }
    }
};

#endif //LEETCODE_2003_SMALLESTMISSINGVALUESUBTREE_H
