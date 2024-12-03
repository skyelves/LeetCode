//
// Created by Ke Wang on 12/3/24.
//

#ifndef INC_261_GRAPHVALIDTREE_H
#define INC_261_GRAPHVALIDTREE_H

#include "solution.h"

class GraphValidTree : public solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> parent(n, 0);
        int cnt = n;
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        for (auto &edge : edges) {
            int p1 = find(edge[0], parent), p2 = find(edge[1], parent);
            if (p1 == p2) {
                return false;
            } else {
                unionNode(edge[0], edge[1], parent);
                --cnt;
            }
        }
        return cnt == 1;
    }

    int find(int node, vector<int> &parent) {
        if (parent[node] == node) {
            return node;
        }
        int res = find(parent[node], parent);
        parent[node] = res;
        return res;
    }

    void unionNode(int n1, int n2, vector<int> &parent) {
        int p1 = find(n1, parent), p2 = find(n2, parent);
        if (p1 != p2) {
            parent[p2] = p1;
        }
    }
};

#endif //INC_261_GRAPHVALIDTREE_H
