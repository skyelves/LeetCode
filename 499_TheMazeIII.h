//
// Created by Ke Wang on 12/3/24.
//

#ifndef INC_499_THEMAZEIII_H
#define INC_499_THEMAZEIII_H

#include "solution.h"

class TheMazeIII : public solution {
    vector<vector<int> > dir{{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
    map<pair<int, int>, char> mm{{{-1, 0}, 'u'}, {{1, 0}, 'd'}, {{0, 1}, 'r'}, {{0, -1}, 'l'}};

public:
    string findShortestWay(vector<vector<int> > &maze, vector<int> &ball, vector<int> &hole) {
        int n = maze.size(), m = maze[0].size();
        vector<vector<vector<vector<int> > >> parent(n, vector<vector<vector<int> >>(m, vector<vector<int>>(4)));
        vector<vector<vector<int> > > visited(n, vector<vector<int> >(m, vector<int>(4, -1)));
        queue<vector<int> > qq;
        for (int i = 0; i < 4; ++i) {
            qq.push({ball[0], ball[1], i, 0});
            visited[ball[0]][ball[1]][i] = true;
        }
        while (!qq.empty()) {
            auto tmp = qq.front();
            qq.pop();
            if (tmp[0] == hole[0] && tmp[1] == hole[1]) {
                string res = getInstructions(tmp[2], parent, ball, hole);
                return res;
            }
            int nx = tmp[0] + dir[tmp[2]][0], ny = tmp[1] + dir[tmp[2]][1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && maze[nx][ny] == 0) {
                if (visited[nx][ny][tmp[2]] == -1) {
                    visited[nx][ny][tmp[2]] = tmp[3] + 1;
                    qq.push({nx, ny, tmp[2], tmp[3] + 1});
                    parent[nx][ny][tmp[2]] = {tmp[0], tmp[1], tmp[2]};
                }
            } else {
                for (int i = 0; i < 4; ++i) {
                    nx = tmp[0] + dir[i][0], ny = tmp[1] + dir[i][1];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && maze[nx][ny] == 0 && visited[nx][ny][i] == -1) {
                        visited[nx][ny][i] = tmp[3] + 1;
                        qq.push({nx, ny, i, tmp[3] + 1});
                        parent[nx][ny][i] = {tmp[0], tmp[1], tmp[2]};
                    }
                }
            }
        }
        return "impossible";
    }

    string getInstructions(int curr, vector<vector<vector<vector<int> > >> &parent, vector<int> &ball, vector<int> &hole) {
        string res = "";
        vector<int> tmp = hole;
        tmp.push_back(curr);
        char last = '0';
        while (tmp[0] != ball[0] || tmp[1] != ball[1]) {
            vector<int> next = parent[tmp[0]][tmp[1]][tmp[2]];
            char tmp_dir = mm[{tmp[0] - next[0], tmp[1] - next[1]}];
            if (last != tmp_dir) {
                res.push_back(tmp_dir);
                last = tmp_dir;
            }
            tmp = next;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    void check() {
        vector<vector<int> > maze{{0, 0, 0, 0, 0}, {1, 1, 0, 0, 1}, {0, 0, 0, 0, 0}, {0, 1, 0, 0, 1}, {0, 1, 0, 0, 0}};
        vector<int> ball{4, 3}, hole{0, 1};
        cout << findShortestWay(maze, ball, hole) << endl;
    }
};

#endif //INC_499_THEMAZEIII_H
