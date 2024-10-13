//
// Created by Admin on 10/12/2024.
//

#ifndef LEETCODE_1334_FINDTHECITYWITHSMALLESTNEIGHBORSATTHRESHOLD_H
#define LEETCODE_1334_FINDTHECITYWITHSMALLESTNEIGHBORSATTHRESHOLD_H

#include "solution.h"

class FindTheCityWithSmallestNeighborAtThreshold : public solution {
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold) {
        vector<vector<int>> dis(n, vector<int>(n, INT32_MAX / 2));
        for (auto &edge: edges) {
            int from = edge[0], to = edge[1], weight = edge[2];
            dis[from][to] = weight;
            dis[to][from] = weight;
        }

        for (int i = 0; i < n; ++i) {
            dis[i][i] = 0;
        }

        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                    dis[j][i] = dis[i][j];
                }
            }
        }

        int res = INT32_MAX, resIdx = 0;
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                if (dis[i][j] <= distanceThreshold) {
                    ++cnt;
                }
            }
            if (cnt <= res) {
                res = cnt;
                resIdx = i;
            }
        }
        return resIdx;
    }

    struct cmp {
        bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
            return a.first > b.first;
        }
    };

    int findTheCity1(int n, vector<vector<int>> &edges, int distanceThreshold) {
        vector<vector<int>> dis(n, vector<int>(n, 1e9));
        for (auto &edge: edges) {
            int from = edge[0], to = edge[1], weight = edge[2];
            dis[from][to] = weight;
            dis[to][from] = weight;
        }

        int res = 0, minNum = INT32_MAX;
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            vector<bool> visited(n, false);
            priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
            pq.push(make_pair(0, i));
            while (!pq.empty() && cnt < n) {
                auto tmp = pq.top();
                pq.pop();
                if (!visited[tmp.second]) {
                    visited[tmp.second] = true;
                    dis[i][tmp.second] = tmp.first;
                    if (tmp.first > distanceThreshold) {
                        break;
                    }
                    ++cnt;
                    for (int j = 0; j < n; ++j) {
                        if (!visited[j] && dis[tmp.second][j] != 1e9) {
                            pq.push(make_pair(tmp.first + dis[tmp.second][j], j));
                        }
                    }
                }
            }
            if (cnt <= minNum) {
                minNum = cnt;
                res = i;
            }

        }
        return res;
    }

    void check() {
        int n = 5, distanceThreshold = 2;
        vector<vector<int>> edges{{0, 1, 2},
                                  {0, 4, 8},
                                  {1, 2, 3},
                                  {1, 4, 2},
                                  {2, 3, 1},
                                  {3, 4, 1}};
        cout << findTheCity1(n, edges, distanceThreshold) << endl;
    }
};

#endif //LEETCODE_1334_FINDTHECITYWITHSMALLESTNEIGHBORSATTHRESHOLD_H
