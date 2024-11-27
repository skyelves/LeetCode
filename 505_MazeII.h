//
// Created by Ke Wang on 11/26/24.
//

#ifndef INC_505_MAZEII_H
#define INC_505_MAZEII_H

#include "solution.h"

class MazeII : public solution {
    vector<vector<int> > dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
    int shortestDistance(vector<vector<int> > &maze, vector<int> &start, vector<int> &destination) {
        int n = maze.size(), m = maze[0].size();
        vector<vector<vector<bool> > > visited(n, vector<vector<bool> >(m, vector<bool>(4, false)));
        queue<vector<int> > qq; // x,y,dir,distance
        for (int i = 0; i < 4; ++i) {
            qq.push({start[0], start[1], i, 0});
            visited[start[0]][start[1]][i] = true;
        }
        while (!qq.empty()) {
            auto tmp = qq.front();
            qq.pop();
            int nx = tmp[0] + dir[tmp[2]][0], ny = tmp[1] + dir[tmp[2]][1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && maze[nx][ny] == 0) {
                if (!visited[nx][ny][tmp[2]]) {
                    visited[nx][ny][tmp[2]] = true;
                    qq.push({nx, ny, tmp[2], tmp[3] + 1});
                }
            } else {
                if (tmp[0] == destination[0] && tmp[1] == destination[1]) {
                    return tmp[3];
                }
                for (int i = 0; i < 4; ++i) {
                    visited[tmp[0]][tmp[1]][i] = true;
                    int nx = tmp[0] + dir[i][0], ny = tmp[1] + dir[i][1];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && maze[nx][ny] == 0 && !visited[nx][ny][i]) {
                        visited[nx][ny][i] = true;
                        qq.push({nx, ny, i, tmp[3] + 1});
                    }
                }
            }
        }
        return -1;
    }

    void check() {
        vector<vector<int> > maze{{0, 0, 1, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 1, 0}, {1, 1, 0, 1, 1}, {0, 0, 0, 0, 0}};
        vector<int> start{0, 4}, destination{4, 4};
        cout << shortestDistance(maze, start, destination) << endl;
    }
};

#endif //INC_505_MAZEII_H
