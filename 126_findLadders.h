//
// Created by 王柯 on 8/14/22.
//

#ifndef LEETCODE_126_FINDLADDERS_H
#define LEETCODE_126_FINDLADDERS_H

#include "solution.h"

class FindLadders : public solution {
public:
    int **edge;
    int *dis;
    queue<int> qq;
    multimap<int, int> mm;

    vector<vector<int>> getPath(int d, int idx) {
        vector<vector<int>> res;
        if (d == 0) {
            vector<int> tmp{idx};
            res.push_back(tmp);
            return res;
        }
        auto iter = mm.find(d - 1);
        for (; iter != mm.end(); iter++) {
            if (iter->first == d - 1 && edge[idx][iter->second] == 1) {
                auto tmp = getPath(d - 1, iter->second);
                for (auto i : tmp) {
                    i.push_back(idx);
                    res.push_back(i);
                }
            }
        }
        return res;
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList) {
        int wordLen = beginWord.size();
        vector<vector<string>> res;
        int len = wordList.size();
        int beginIdx = -1, endIdx = -1;
        for (int i = 0; i < len; ++i) {
            if (wordList[i] == beginWord) {
                beginIdx = i;
                break;
            }
        }
        if (beginIdx == -1) {
            beginIdx = wordList.size();
            wordList.push_back(beginWord);
        }
        for (int i = 0; i < len; ++i) {
            if (wordList[i] == endWord) {
                endIdx = i;
                break;
            }
        }
        if (endIdx == -1) {
            return res;
        }
        len = wordList.size();
        dis = new int[len];
        edge = new int *[len];
        for (int i = 0; i < len; ++i) {
            edge[i] = new int[len];
            memset(edge[i], 0, sizeof(int) * len);
        }
        for (int i = 0; i < len; ++i) {
            for (int j = i + 1; j < len; ++j) {
                int diffCnt = 0;
                for (int k = 0; k < wordLen; ++k) {
                    if (wordList[i][k] != wordList[j][k]) {
                        diffCnt++;
                    }
                }
                if (diffCnt == 1) {
                    edge[i][j] = edge[j][i] = 1;
                }
            }
        }

        bool *visited = new bool[len];
        memset(visited, 0, sizeof(bool) * len);
        visited[beginIdx] = true;
        mm.insert({0, beginIdx});
        for (int i = 0; i < len; ++i) {
            if (edge[beginIdx][i] == 1) {
                dis[i] = 1;
                qq.push(i);
                mm.insert({1, i});
                visited[i] = true;
            } else {
                dis[i] = INT_MAX;
            }
        }
        bool flag = false;
        while (!qq.empty()) {
            int tmpIdx = qq.front();
            qq.pop();
            if (tmpIdx == endIdx) {
                flag = true;
                break;
            }
            for (int i = 0; i < len; ++i) {
                if (edge[tmpIdx][i] == 1 && !visited[i]) {
                    dis[i] = dis[tmpIdx] + 1;
                    qq.push(i);
                    mm.insert({dis[i], i});
                    visited[i] = true;
                }
            }
        }
        if (flag && dis[endIdx] != INT_MAX) {
            auto tmpRes = getPath(dis[endIdx], endIdx);
            for (auto i : tmpRes) {
                vector<string> tmp;
                for (auto j : i) {
                    tmp.push_back(wordList[j]);
                }
                res.push_back(tmp);
            }
        }

        return res;
    }

    void check() {
        string beginWord = "hot", endWord = "dog";
        vector<string> wordList = {"hot", "dog"};
        auto res = findLadders(beginWord, endWord, wordList);
        for (auto i: res) {
            for (auto j : i) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

#endif //LEETCODE_126_FINDLADDERS_H
