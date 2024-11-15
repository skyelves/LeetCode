//
// Created by 王柯 on 8/16/22.
//

#ifndef LEETCODE_127_LADDERLENGTH_H
#define LEETCODE_127_LADDERLENGTH_H

#include "solution.h"

class LadderLength : public solution {
public:
    bool isAdjacent(string &s1, string &s2) {
        int diff = 0;
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) {
                ++diff;
            }
        }
        return diff == 1;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int begin = findWord(beginWord, wordList);
        if (begin == -1) {
            wordList.push_back(beginWord);
            begin = wordList.size() - 1;
        }
        int end = findWord(endWord, wordList);
        if (end == -1) {
            return 0;
        }
        int n = wordList.size();
        unordered_map<int, vector<int>> edge;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isAdjacent(wordList[i], wordList[j])) {
                    edge[i].push_back(j);
                    edge[j].push_back(i);
                }
            }
        }
        queue<pair<int, int>> curr;
        vector<bool> visited(n, false);
        visited[begin] = true;
        curr.emplace(begin, 1);
        while (!curr.empty()) {
            auto tmp = curr.front();
            curr.pop();
            for (int i : edge[tmp.first]) {
                if (!visited[i]) {
                    if (i == end) {
                        return tmp.second + 1;
                    }
                    visited[i] = true;
                    curr.emplace(i, tmp.second + 1);
                }
            }
        }
        return 0;
    }

    int findWord(string &endWord, vector<string>& wordList) {
        int n = wordList.size();
        int end = -1;
        for (int i = 0; i < n; ++i) {
            if (endWord == wordList[i]) {
                end = i;
                break;
            }
        }
        return end;
    }

    void check() {
        string beginWord = "hit", endWord = "cog";
        vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
        auto res = ladderLength(beginWord, endWord, wordList);
        cout << res << endl;
    }
};

#endif //LEETCODE_127_LADDERLENGTH_H
