//
// Created by Admin on 8/9/2024.
//

#ifndef LEETCODE_959_REGIONSCUTBYSLASHES_H
#define LEETCODE_959_REGIONSCUTBYSLASHES_H

#include "solution.h"

class RegionsCutBySlashes : public solution {
public:
    int regionsBySlashes(vector<string> &grid) {
        vector<vector<int>> extendedGraph = extendGraph(grid);
        return cntRegions(extendedGraph);
    }

    vector<vector<int>> extendGraph(vector<string> &grid) {
        int n = grid.size();
        vector<vector<int>> extendedGraph(3 * n, vector<int>(3 * n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '/') {
                    extendedGraph[3 * i][3 * j + 2] = 1;
                    extendedGraph[3 * i + 1][3 * j + 1] = 1;
                    extendedGraph[3 * i + 2][3 * j] = 1;
                } else if (grid[i][j] == '\\') {
                    extendedGraph[3 * i][3 * j] = 1;
                    extendedGraph[3 * i + 1][3 * j + 1] = 1;
                    extendedGraph[3 * i + 2][3 * j + 2] = 1;
                }
            }
        }
        return extendedGraph;
    }

    void recursiveExtend(vector<vector<int>> &graph, vector<vector<bool>> &visited, int i, int j) {
        if (i < 0 || j < 0 || i >= graph.size() || j >= graph.size()) {
            return;
        }
        if (!visited[i][j] && graph[i][j] == 0) {
            visited[i][j] = true;
            recursiveExtend(graph, visited, i + 1, j);
            recursiveExtend(graph, visited, i - 1, j);
            recursiveExtend(graph, visited, i, j + 1);
            recursiveExtend(graph, visited, i, j - 1);
        }
    }

    int cntRegions(vector<vector<int>> &graph) {
        int res = 0;
        int n = graph.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!visited[i][j] && graph[i][j] == 0) {
                    ++res;
                    recursiveExtend(graph, visited, i, j);
                }
            }
        }
        return res;
    }

    void check() {
        vector<string> grid{" /","/ "};
        cout << regionsBySlashes(grid) << endl;
    }
};

#endif //LEETCODE_959_REGIONSCUTBYSLASHES_H
