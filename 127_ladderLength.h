//
// Created by 王柯 on 8/16/22.
//

#ifndef LEETCODE_127_LADDERLENGTH_H
#define LEETCODE_127_LADDERLENGTH_H

#include "solution.h"

class LadderLength : public solution {
public:
    int **edge;
    int *dis;
    queue<int> qq;

    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        int wordLen = beginWord.size();
        int res = 0;
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
            return 0;
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
        for (int i = 0; i < len; ++i) {
            if (edge[beginIdx][i] == 1) {
                dis[i] = 1;
                qq.push(i);
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
                    visited[i] = true;
                }
            }
        }
        if (flag) {
            res = dis[endIdx] + 1;
        }

        return res;
    }

    void check() {
        string beginWord = "hit", endWord = "cog";
        vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
        auto res = ladderLength(beginWord, endWord, wordList);
        cout << res << endl;
    }
};

#endif //LEETCODE_127_LADDERLENGTH_H
